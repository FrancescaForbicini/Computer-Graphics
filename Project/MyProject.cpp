// This has been adapted from the Vulkan tutorial

#include "MyProject.hpp"

const std::string MODEL_PATH = "models/";
const std::string TEXTURE_PATH = "textures/";

// The uniform buffer object used in this example
//maybe separate into a gubo (position of the camera) and an ubo for each specific object (position of each object)
struct UniformBufferObject {
    alignas(16) glm::mat4 model;
};

struct GlobalUniformBufferObject {
    alignas(16) glm::mat4 view;
    alignas(16) glm::mat4 proj;
    alignas(16) glm::vec3 lightColor;
    alignas(16) glm::vec3 lightPos;
    alignas(16) glm::vec2 cinout;
    alignas(16) glm::vec3 spotDirection;
    alignas(16) glm::vec3 eyePos;
};


// MAIN ! 
class MyProject : public BaseProject {
protected:
    // Here you list all the Vulkan objects you need:

    // Descriptor Layouts [what will be passed to the shaders]
    DescriptorSetLayout DSLglobal;
    DescriptorSetLayout DSLobj;

    // Pipelines [Shader couples] one is enough
    Pipeline P1;

    // Models, textures and Descriptors (values assigned to the uniforms)
    //one for each object (disk, puck 1, puck 2, table)
    Model M_Table;
    Texture T_Table;
    DescriptorSet DS_Table;

    Model M_Puck1;
    Texture T_Puck1;
    DescriptorSet DS_Puck1;

    Model M_Puck2;
    Texture T_Puck2;
    DescriptorSet DS_Puck2;

    Model M_Disk;
    Texture T_Disk;
    DescriptorSet DS_Disk;

    

    DescriptorSet DS_Global;

    //to change the view
    int curView = 0;
    int totalView = 3;
    int scoreRed = 0;
    int scoreBlue = 0;
    const float MOVE_SPEED = 2.4f;
    const float MOVE_COLLISION = 0.09f;
    const float UP_BORDER = 5.9f;
    const float DOWN_BORDER = -5.9f;
    const float RIGHT_BORDER = 4.4f;
    const float LEFT_BORDER = -4.4f;
    const float GOAL = 0.75f;
    glm::vec3 diskPosition = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 paddleRedPosition = glm::vec3(0.0f, 0.0f, 4.0f);
    glm::vec3 paddleBluePosition = glm::vec3(0.0f, 0.0f, -4.0f);
    glm::vec3 diskVel = glm::vec3(0.0f, 0.0f, -MOVE_COLLISION);

    float radius = 0.3f;

    // Here you set the main application parameters
    void setWindowParameters() {
        // window size, titile and initial background
        windowWidth = 1280;
        windowHeight = 720;
        windowTitle = "Air Hockey";
        initialBackgroundColor = { 0.0f, 0.0f, 0.0f, 1.0f };

        // Descriptor pool sizes
        //Remember to change when adding objects and textures
        uniformBlocksInPool = 5;
        texturesInPool = 4;
        setsInPool = 5;
    }

    // Here you load and setup all your Vulkan objects
    void localInit() {
        // Descriptor Layouts [what will be passed to the shaders]
        DSLobj.init(this, {
            // this array contains the binding:
            // first  element : the binding number
            // second element : the type of element (buffer or texture)
            // third  element : the pipeline stage where it will be used
            {0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, VK_SHADER_STAGE_VERTEX_BIT},
            {1, VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, VK_SHADER_STAGE_FRAGMENT_BIT}
            });

        DSLglobal.init(this, {
                {0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, VK_SHADER_STAGE_ALL_GRAPHICS}
            });

        // Pipelines [Shader couples]
        // The last array, is a vector of pointer to the layouts of the sets that will
        // be used in this pipeline. The first element will be set 0, and so on..
        //Change shaders (or maybe not)
        P1.init(this, "shaders/vert.spv", "shaders/frag.spv", { &DSLglobal, &DSLobj });

        // Models, textures and Descriptors (values assigned to the uniforms)
        //One call to each class for each object
        M_Table.init(this, MODEL_PATH + "table.obj");
        T_Table.init(this, TEXTURE_PATH + "table.png");
        DS_Table.init(this, &DSLobj, {
            // the second parameter, is a pointer to the Uniform Set Layout of this set
            // the last parameter is an array, with one element per binding of the set.
            // first  element : the binding number
            // second element : UNIFORM or TEXTURE (an enum) depending on the type
            // third  element : only for UNIFORMs, the size of the corresponding C++ object
            // fourth element : only for TEXTUREs, the pointer to the corresponding texture object
                        {0, UNIFORM, sizeof(UniformBufferObject), nullptr},
                        {1, TEXTURE, 0, &T_Table}
            });

        M_Puck1.init(this, MODEL_PATH + "paddle.obj");
        T_Puck1.init(this, TEXTURE_PATH + "paddle1.png");
        DS_Puck1.init(this, &DSLobj, {
                    {0, UNIFORM, sizeof(UniformBufferObject), nullptr},
                    {1, TEXTURE, 0, &T_Puck1}
            });

        M_Puck2.init(this, MODEL_PATH + "paddle.obj");
        T_Puck2.init(this, TEXTURE_PATH + "paddle2.png");
        DS_Puck2.init(this, &DSLobj, {
                    {0, UNIFORM, sizeof(UniformBufferObject), nullptr},
                    {1, TEXTURE, 0, &T_Puck2}
            });

        M_Disk.init(this, MODEL_PATH + "disk.obj");
        T_Disk.init(this, TEXTURE_PATH + "disk.png");
        DS_Disk.init(this, &DSLobj, {
                    {0, UNIFORM, sizeof(UniformBufferObject), nullptr},
                    {1, TEXTURE, 0, &T_Disk}
            });

        

        DS_Global.init(this, &DSLglobal, {
                {0, UNIFORM, sizeof(GlobalUniformBufferObject), nullptr}
            });
    }

    // Here you destroy all the objects you created!		
    void localCleanup() {
        DS_Global.cleanup();
        DS_Table.cleanup();
        T_Table.cleanup();
        M_Table.cleanup();
        DS_Puck1.cleanup();
        T_Puck1.cleanup();
        M_Puck1.cleanup();
        DS_Puck2.cleanup();
        T_Puck2.cleanup();
        M_Puck2.cleanup();
        DS_Disk.cleanup();
        T_Disk.cleanup();
        M_Disk.cleanup();
        P1.cleanup();
        DSLglobal.cleanup();
        DSLobj.cleanup();
    }

    // Here it is the creation of the command buffer:
    // You send to the GPU all the objects you want to draw,
    // with their buffers and textures
    void populateCommandBuffer(VkCommandBuffer commandBuffer, int currentImage) {

        vkCmdBindPipeline(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS,
            P1.graphicsPipeline);
        vkCmdBindDescriptorSets(commandBuffer,
            VK_PIPELINE_BIND_POINT_GRAPHICS,
            P1.pipelineLayout, 0, 1, &DS_Global.descriptorSets[currentImage],
            0, nullptr);

        VkBuffer vertexBuffers[] = { M_Table.vertexBuffer };
        // property .vertexBuffer of models, contains the VkBuffer handle to its vertex buffer
        VkDeviceSize offsets[] = { 0 };
        vkCmdBindVertexBuffers(commandBuffer, 0, 1, vertexBuffers, offsets);
        // property .indexBuffer of models, contains the VkBuffer handle to its index buffer
        vkCmdBindIndexBuffer(commandBuffer, M_Table.indexBuffer, 0,
            VK_INDEX_TYPE_UINT32);

        // property .pipelineLayout of a pipeline contains its layout.
        // property .descriptorSets of a descriptor set contains its elements.
        vkCmdBindDescriptorSets(commandBuffer,
            VK_PIPELINE_BIND_POINT_GRAPHICS,
            P1.pipelineLayout, 1, 1, &DS_Table.descriptorSets[currentImage],
            0, nullptr);

        // property .indices.size() of models, contains the number of triangles * 3 of the mesh.
        vkCmdDrawIndexed(commandBuffer,
            static_cast<uint32_t>(M_Table.indices.size()), 1, 0, 0, 0);

        VkBuffer vertexBuffers1[] = { M_Puck1.vertexBuffer };
        VkDeviceSize offsets1[] = { 0 };
        vkCmdBindVertexBuffers(commandBuffer, 0, 1, vertexBuffers1, offsets1);
        vkCmdBindIndexBuffer(commandBuffer, M_Puck1.indexBuffer, 0,
            VK_INDEX_TYPE_UINT32);
        vkCmdBindDescriptorSets(commandBuffer,
            VK_PIPELINE_BIND_POINT_GRAPHICS,
            P1.pipelineLayout, 1, 1, &DS_Puck1.descriptorSets[currentImage],
            0, nullptr);
        vkCmdDrawIndexed(commandBuffer,
            static_cast<uint32_t>(M_Puck1.indices.size()), 1, 0, 0, 0);

        VkBuffer vertexBuffers2[] = { M_Puck2.vertexBuffer };
        VkDeviceSize offsets2[] = { 0 };
        vkCmdBindVertexBuffers(commandBuffer, 0, 1, vertexBuffers2, offsets2);
        vkCmdBindIndexBuffer(commandBuffer, M_Puck2.indexBuffer, 0,
            VK_INDEX_TYPE_UINT32);
        vkCmdBindDescriptorSets(commandBuffer,
            VK_PIPELINE_BIND_POINT_GRAPHICS,
            P1.pipelineLayout, 1, 1, &DS_Puck2.descriptorSets[currentImage],
            0, nullptr);
        vkCmdDrawIndexed(commandBuffer,
            static_cast<uint32_t>(M_Puck2.indices.size()), 1, 0, 0, 0);

        VkBuffer vertexBuffers3[] = { M_Disk.vertexBuffer };
        VkDeviceSize offsets3[] = { 0 };
        vkCmdBindVertexBuffers(commandBuffer, 0, 1, vertexBuffers3, offsets3);
        vkCmdBindIndexBuffer(commandBuffer, M_Disk.indexBuffer, 0,
            VK_INDEX_TYPE_UINT32);
        vkCmdBindDescriptorSets(commandBuffer,
            VK_PIPELINE_BIND_POINT_GRAPHICS,
            P1.pipelineLayout, 1, 1, &DS_Disk.descriptorSets[currentImage],
            0, nullptr);
        vkCmdDrawIndexed(commandBuffer,
            static_cast<uint32_t>(M_Disk.indices.size()), 1, 0, 0, 0);

       
    }

    void changeView(uint32_t currentImage) {
        GlobalUniformBufferObject gubo{};
        static int preView = -1;
        void* data;
        glm::mat4 CamMat = glm::mat4(1.0);

        //std::cout << "Changing POV\n";
        switch (curView) {
        case 0:
            if (curView != preView) {
                std::cout << "Top View\n";
                preView = curView;
            }
            CamMat = glm::lookAt(glm::vec3(0.0f, 20.0f, 0.01f),
                glm::vec3(0.0f, 0.0f, 0.0f),
                glm::vec3(0.0f, 1.0f, 0.0f));
            gubo.eyePos = glm::vec3(0.0f, 20.0f, 0.01f);
            break;

        case 1:
            if (curView != preView) {
                std::cout << "Player 1 View\n";
                preView = curView;
            }
            CamMat = glm::lookAt(glm::vec3(0.0f, 5.0f, 12.0f),
                glm::vec3(0.0f, 0.0f, 0.0f),
                glm::vec3(0.0f, 1.0f, 0.0f));
            gubo.eyePos = glm::vec3(0.0f, 5.0f, 12.0f);
            break;

        case 2:
            if (curView != preView) {
                std::cout << "Player 2 View\n";
                preView = curView;
            }
            CamMat = glm::lookAt(glm::vec3(0.0f, 5.0f, -12.0f),
                glm::vec3(0.0f, 0.0f, 0.0f),
                glm::vec3(0.0f, 1.0f, 0.0f));
            gubo.eyePos = glm::vec3(0.0f, 5.0f, -12.0f);
            break;
        }

        gubo.view = CamMat;
        gubo.lightColor = glm::vec3(0.9f, 0.9f, 0.9f);
        gubo.lightPos = glm::vec3(0.0f, 10.0f, 0.0f);
        gubo.cinout.x = 0.9f;
        gubo.cinout.y = 0.924f;
        gubo.spotDirection = glm::vec3(0.0f, 0.5f, 0.5f);
        gubo.proj = glm::perspective(glm::radians(45.0f),
            swapChainExtent.width / (float)swapChainExtent.height,
            0.1f, 50.0f);
        gubo.proj[1][1] *= -1;

        vkMapMemory(device, DS_Global.uniformBuffersMemory[0][currentImage], 0,
            sizeof(gubo), 0, &data);
        memcpy(data, &gubo, sizeof(gubo));
        vkUnmapMemory(device, DS_Global.uniformBuffersMemory[0][currentImage]);

    }
    void makeGoal() {
        //make a goal
        if (diskPosition.x + radius < GOAL && diskPosition.x - radius > -GOAL) {
            if (diskPosition.z < DOWN_BORDER - 0.1f) {
                scoreRed++;
                diskPosition = glm::vec3(0.0f, 0.0f, 0.0f);
                diskVel = glm::vec3(0.0f, 0.0f, -MOVE_COLLISION);
                std::cout << "GOAL! Red: " << scoreRed << "; Blue: " << scoreBlue << "\n";
            }
            else {
                if (diskPosition.z > UP_BORDER + 0.1f) {
                    scoreBlue++;
                    diskPosition = glm::vec3(0.0f, 0.0f, 0.0f);
                    diskVel = glm::vec3(0.0f, 0.0f, MOVE_COLLISION);
                    std::cout << "GOAL! Red: " << scoreRed << "; Blue: " << scoreBlue << "\n";
                }
            }
        }
    }

    void handleCollision() {
        //disk collision with paddle
        if ((abs(glm::length(paddleRedPosition - diskPosition)) <= 2 * radius)) {
            diskVel = MOVE_COLLISION * normalize(diskPosition - paddleRedPosition);
        }
        else {
            if (abs(glm::length(paddleBluePosition - diskPosition)) <= 2 * radius) {
                diskVel = MOVE_COLLISION * normalize(diskPosition - paddleBluePosition);
            }
        }

        //disk collision with goal
        if ((diskPosition.z + radius >= UP_BORDER || diskPosition.z - radius <= DOWN_BORDER) &&
            (diskPosition.x - radius <= -GOAL || diskPosition.x + radius >= GOAL)) {
            diskVel.z = -diskVel.z;
            if (diskPosition.z + radius >= UP_BORDER) {
                diskPosition.z = UP_BORDER - radius - 0.01f;
            }
            if (diskPosition.z - radius <= DOWN_BORDER) {
                diskPosition.z = DOWN_BORDER + radius + 0.01f;
            }
        }
        if (diskPosition.x + radius >= RIGHT_BORDER || diskPosition.x - radius <= LEFT_BORDER) {
            diskVel.x = -diskVel.x;
        }
    }

    //movement player 1
    void handleMovementRedPaddle(float deltaT) {
        if (curView != 2) {
            if (glfwGetKey(window, GLFW_KEY_UP)) {
                paddleRedPosition.z -= deltaT * MOVE_SPEED;
            }
            if (glfwGetKey(window, GLFW_KEY_DOWN)) {
                paddleRedPosition.z += deltaT * MOVE_SPEED;
            }
            if (glfwGetKey(window, GLFW_KEY_LEFT)) {
                paddleRedPosition.x -= deltaT * MOVE_SPEED;
            }
            if (glfwGetKey(window, GLFW_KEY_RIGHT)) {
                paddleRedPosition.x += deltaT * MOVE_SPEED;
            }
        }
        else {
            if (glfwGetKey(window, GLFW_KEY_UP)) {
                paddleRedPosition.z += deltaT * MOVE_SPEED;
            }
            if (glfwGetKey(window, GLFW_KEY_DOWN)) {
                paddleRedPosition.z -= deltaT * MOVE_SPEED;
            }
            if (glfwGetKey(window, GLFW_KEY_LEFT)) {
                paddleRedPosition.x += deltaT * MOVE_SPEED;
            }
            if (glfwGetKey(window, GLFW_KEY_RIGHT)) {
                paddleRedPosition.x -= deltaT * MOVE_SPEED;
            }
        }

        //paddle can't exceed the half court and the borders
        paddleRedPosition.z = std::max(paddleRedPosition.z, 0.0f + radius);
        paddleRedPosition.z = std::min(paddleRedPosition.z, UP_BORDER - radius);
        paddleRedPosition.x = std::min(paddleRedPosition.x, RIGHT_BORDER - radius);
        paddleRedPosition.x = std::max(paddleRedPosition.x, LEFT_BORDER + radius);

    }

    //movement player 2
    void handleMovementBluePaddle(float deltaT) {
        if (curView == 2) {
            if (glfwGetKey(window, GLFW_KEY_W)) {
                paddleBluePosition.z += deltaT * MOVE_SPEED;
            }
            if (glfwGetKey(window, GLFW_KEY_S)) {
                paddleBluePosition.z -= deltaT * MOVE_SPEED;
            }
            if (glfwGetKey(window, GLFW_KEY_A)) {
                paddleBluePosition.x += deltaT * MOVE_SPEED;
            }
            if (glfwGetKey(window, GLFW_KEY_D)) {
                paddleBluePosition.x -= deltaT * MOVE_SPEED;
            }
        }
        else {
            if (glfwGetKey(window, GLFW_KEY_W)) {
                paddleBluePosition.z -= deltaT * MOVE_SPEED;
            }
            if (glfwGetKey(window, GLFW_KEY_S)) {
                paddleBluePosition.z += deltaT * MOVE_SPEED;
            }
            if (glfwGetKey(window, GLFW_KEY_A)) {
                paddleBluePosition.x -= deltaT * MOVE_SPEED;
            }
            if (glfwGetKey(window, GLFW_KEY_D)) {
                paddleBluePosition.x += deltaT * MOVE_SPEED;
            }
        }

        //paddle can't exceed the half court and the borders
        paddleBluePosition.z = std::min(paddleBluePosition.z, 0.0f - radius);
        paddleBluePosition.z = std::max(paddleBluePosition.z, DOWN_BORDER + radius);
        paddleBluePosition.x = std::min(paddleBluePosition.x, RIGHT_BORDER - radius);
        paddleBluePosition.x = std::max(paddleBluePosition.x, LEFT_BORDER + radius);
    }



    // Here is where you update the uniforms.
    // Very likely this will be where you will be writing the logic of your application.
    void updateUniformBuffer(uint32_t currentImage) {
        static auto startTime = std::chrono::high_resolution_clock::now();
        static float lastTime = 0.0f;
        auto currentTime = std::chrono::high_resolution_clock::now();
        float time = std::chrono::duration<float, std::chrono::seconds::period>
            (currentTime - startTime).count();
        static float debounce = time;

        UniformBufferObject ubo{};
        GlobalUniformBufferObject gubo{};

        float deltaT = time - lastTime;
        lastTime = time;

        void* data;
        glm::mat4 CamMat = glm::mat4(1.0);

        //change point of view
        if (glfwGetKey(window, GLFW_KEY_SPACE)) {
            if (time - debounce > 0.33) {
                curView = (curView + 1) % totalView;
                debounce = time;
            }
        }
        //change the view when key space is pressed
        changeView(currentImage);

        // Here is where you actually update your uniforms
        ubo.model = glm::scale(glm::mat4(1.0f), glm::vec3(1.5f, 1.0f, 1.5f));
        vkMapMemory(device, DS_Table.uniformBuffersMemory[0][currentImage], 0,
            sizeof(ubo), 0, &data);
        memcpy(data, &ubo, sizeof(ubo));
        vkUnmapMemory(device, DS_Table.uniformBuffersMemory[0][currentImage]);

        //Movement of player 1 (red)
        handleMovementRedPaddle(deltaT);
        //move the red paddle in the actual position
        ubo.model = glm::translate(glm::mat4(1.0f), paddleRedPosition);
        vkMapMemory(device, DS_Puck1.uniformBuffersMemory[0][currentImage], 0,
            sizeof(ubo), 0, &data);
        memcpy(data, &ubo, sizeof(ubo));
        vkUnmapMemory(device, DS_Puck1.uniformBuffersMemory[0][currentImage]);

        //Movement of player 2(blue)
        handleMovementBluePaddle(deltaT);
        //move the blue paddle in the actual position
        ubo.model = glm::translate(glm::mat4(1.0f),
            paddleBluePosition);
        vkMapMemory(device, DS_Puck2.uniformBuffersMemory[0][currentImage], 0,
            sizeof(ubo), 0, &data);
        memcpy(data, &ubo, sizeof(ubo));
        vkUnmapMemory(device, DS_Puck2.uniformBuffersMemory[0][currentImage]);


        diskPosition = diskPosition + diskVel;
        //move the disk in the right position
        ubo.model = glm::translate(glm::mat4(1.0f), diskPosition);
        vkMapMemory(device, DS_Disk.uniformBuffersMemory[0][currentImage], 0,
            sizeof(ubo), 0, &data);
        memcpy(data, &ubo, sizeof(ubo));
        vkUnmapMemory(device, DS_Disk.uniformBuffersMemory[0][currentImage]);

        handleCollision();
        makeGoal();

        
    }

};


// This is the main: probably you do not need to touch this!
int main() {
    MyProject app;

    try {
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}