// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices

#include <corecrt_math_defines.h>
struct Vertex {
	glm::vec3 pos;
	glm::vec3 norm;
};

std::vector<Vertex> M1_vertices;
std::vector<Vertex> M2_vertices;
std::vector<Vertex> M3_vertices;
std::vector<Vertex> M4_vertices;

void makeModels() {
    //// M1 : Cube
    // Replace the code below, that creates a simple square, with the one to create a cube.

    // Resizes the vertices array.
    M1_vertices.resize(3 * 8);

    // first vertex of M1
    M1_vertices[0].pos = {-1.0, -1.0, -1.0};
    M1_vertices[0].norm = {0.0, -1.0, 0.0};
    M1_vertices[1].pos = {-1.0, -1.0, -1.0};
    M1_vertices[1].norm = {-1.0, 0.0, 0.0};
    M1_vertices[2].pos = {-1.0, -1.0, -1.0};
    M1_vertices[2].norm = {0.0, 0.0, -1.0};

    // second vertex of M1
    M1_vertices[3].pos = {1.0, -1.0, -1.0};
    M1_vertices[3].norm = {0.0, -1.0, 0.0};
    M1_vertices[4].pos = {1.0, -1.0, -1.0};
    M1_vertices[4].norm = {1.0, 0.0, 0.0};
    M1_vertices[5].pos = {1.0, -1.0, -1.0};
    M1_vertices[5].norm = {0.0, 0.0, -1.0};

    // third vertex of M1
    M1_vertices[6].pos = {1.0, 1.0, -1.0};
    M1_vertices[6].norm = {0.0, 1.0, 0.0};
    M1_vertices[7].pos = {1.0, 1.0, -1.0};
    M1_vertices[7].norm = {1.0, 0.0, 0.0};
    M1_vertices[8].pos = {1.0, 1.0, -1.0};
    M1_vertices[8].norm = {0.0, 0.0, -1.0};

    // fourth vertex of M1
    M1_vertices[9].pos = {-1.0, 1.0, -1.0};
    M1_vertices[9].norm = {0.0, 1.0, 0.0};
    M1_vertices[10].pos = {-1.0, 1.0, -1.0};
    M1_vertices[10].norm = {-1.0, 0.0, 0.0};
    M1_vertices[11].pos = {-1.0, 1.0, -1.0};
    M1_vertices[11].norm = {0.0, 0.0, -1.0};

    //fifth vertex of M1
    M1_vertices[12].pos = {-1.0, -1.0, 1.0};
    M1_vertices[12].norm = {0.0, -1.0, 0.0};
    M1_vertices[13].pos = {-1.0, -1.0, 1.0};
    M1_vertices[13].norm = {-1.0, 0.0, 0.0};
    M1_vertices[14].pos = {-1.0, -1.0, 1.0};
    M1_vertices[14].norm = {0.0, 0.0, 1.0};

    //sixth vertex of M1
    M1_vertices[15].pos = {1.0, -1.0, 1.0};
    M1_vertices[15].norm = {0.0, -1.0, 0.0};
    M1_vertices[16].pos = {1.0, -1.0, 1.0};
    M1_vertices[16].norm = {1.0, 0.0, 0.0};
    M1_vertices[17].pos = {1.0, -1.0, 1.0};
    M1_vertices[17].norm = {0.0, 0.0, 1.0};

    //seventh vertex of M1
    M1_vertices[18].pos = {1.0, 1.0, 1.0};
    M1_vertices[18].norm = {0.0, 1.0, 0.0};
    M1_vertices[19].pos = {1.0, 1.0, 1.0};
    M1_vertices[19].norm = {1.0, 0.0, 0.0};
    M1_vertices[20].pos = {1.0, 1.0, 1.0};
    M1_vertices[20].norm = {0.0, 0.0, 1.0};

    //eighth vertex of M1
    M1_vertices[21].pos = {-1.0, 1.0, 1.0};
    M1_vertices[21].norm = {0.0, 1.0, 0.0};
    M1_vertices[22].pos = {-1.0, 1.0, 1.0};
    M1_vertices[22].norm = {-1.0, 0.0, 0.0};
    M1_vertices[23].pos = {-1.0, 1.0, 1.0};
    M1_vertices[23].norm = {0.0, 0.0, 1.0};

    // Resizes the indices array. Replace the values with the correct number of
    // indices (3 * number of triangles)
    M1_indices.resize(3 * 12);

    // first triangle
    M1_indices[0] = 0;
    M1_indices[1] = 3;
    M1_indices[2] = 12;

    // second triangle
    M1_indices[3] = 2;
    M1_indices[4] = 5;
    M1_indices[5] = 11;

    // third triangle
    M1_indices[6] = 1;
    M1_indices[7] = 10;
    M1_indices[8] = 13;

    // fourth triangle
    M1_indices[9] = 3;
    M1_indices[10] = 12;
    M1_indices[11] = 15;

    // fifth triangle
    M1_indices[12] = 4;
    M1_indices[13] = 16;
    M1_indices[14] = 19;

    // sixth triangle
    M1_indices[15] = 20;
    M1_indices[16] = 14;
    M1_indices[17] = 17;

    // seventh triangle
    M1_indices[18] = 21;
    M1_indices[19] = 9;
    M1_indices[20] = 18;

    // eighth triangle
    M1_indices[21] = 22;
    M1_indices[22] = 10;
    M1_indices[23] = 13;

    // ninth triangle
    M1_indices[24] = 23;
    M1_indices[25] = 20;
    M1_indices[26] = 14;

    // tenth triangle
    M1_indices[27] = 6;
    M1_indices[28] = 9;
    M1_indices[29] = 18;

    // eleventh triangle
    M1_indices[30] = 7;
    M1_indices[31] = 19;
    M1_indices[32] = 4;

    // twelfth triangle
    M1_indices[33] = 8;
    M1_indices[34] = 11;
    M1_indices[35] = 5;








    //// M2 : Cylinder
    // Replace the code below, that creates a simple rotated square, with the one to create a cylinder.

    // Resizes the vertices array. Repalce the values with the correct number of
    // vertices components (3 * number of vertices)

    int NSlices = 36; //number of slices in which we divide a circle
    float radius = 1; //length of the radius
    float height = 1; //mid-height of the cylinder
    float cx = 0, cy = 0, cz = -3; //coordinates of the center of the cylinder

    M2_vertices.resize(1 + NSlices + NSlices + NSlices + NSlices + 1);

// Vertices definitions
    M2_vertices[0].pos  =  {cx, cy + height, cz};//top cap center
    M2_vertices[0].norm = {0.0, 1.0, 0.0};

    int j = 0;
    for(int i = 1; i <= NSlices; i++) {//top cap ring
        M2_vertices[i].pos = {cx + radius * cos((float) (j*2.0*M_PI/NSlices)), cy + height, cz + radius * sin((float) (j*2.0*M_PI/NSlices))};
        M2_vertices[i].norm = {0.0, 1.0, 0.0};
        j++;
    }
    j = 0;
    for(int i = NSlices+1; i <= 2*NSlices; i++) {//upper side ring (same position of top cap but different norms
        M2_vertices[i].pos = {cx + radius * cos((float) (j*2.0*M_PI/NSlices)), cy + height, cz + radius * sin((float) (j*2.0*M_PI/NSlices))};
        M2_vertices[i].norm = {cos((float) (j*2.0*M_PI/NSlices)), 0.0, sin((float) (j*2.0*M_PI/NSlices))};
        j++;
    }

    M2_vertices[2*NSlices+1].pos  =  {cx, cy-height, cz};//bottom cap center
    M2_vertices[2*NSlices+1].norm = {0.0, -1.0, 0.0};

    j = 0;
    for(int i = 2*NSlices+2; i <= 3*NSlices+1; i++) {//bottom cap ring
        M2_vertices[i].pos = {cx + radius * cos((float) (j*2.0*M_PI/NSlices)), cy - height, cz + radius * sin((float) (j*2.0*M_PI/NSlices))};
        M2_vertices[i].norm = {0.0, -1.0, 0.0};
        j++;
    }
    j = 0;
    for(int i = 3*NSlices+2; i <= 4*NSlices+1; i++) {//bottom side ring (same position of bottom cap but different norms
        M2_vertices[i].pos = {cx + radius * cos((float) (j*2.0*M_PI/NSlices)), cy - height, cz + radius * sin((float) (j*2.0*M_PI/NSlices))};
        M2_vertices[i].norm = {cos((float) (j*2.0*M_PI/NSlices)), 0.0, sin((float) (j*2.0*M_PI/NSlices))};
        j++;
    }

// Resizes the indices array. Repalce the values with the correct number of
// indices (3 * number of triangles)
    M2_indices.resize(3 * (NSlices + 2*NSlices + NSlices));

// indices definitions
    for(int i = 0; i < NSlices; i++) {//top cap triangles
        M2_indices[i * 3 + 0] = 0;
        M2_indices[i * 3 + 1] = i + 1;
        M2_indices[i * 3 + 2] = (i + 1) % NSlices + 1;
    }

    for(int i = 0; i < NSlices; i++) {//bottom cap triangles
        M2_indices[i * 3 + NSlices*3 + 0] = 2*NSlices+1;
        M2_indices[i * 3 + NSlices*3 + 1] = 2*NSlices+1 + i + 1;
        M2_indices[i * 3 + NSlices*3 + 2] = 2*NSlices+1 + (i + 1) % NSlices + 1;
    }


    for(int i = 0; i < NSlices-1; i++) {//side triangles
        M2_indices[i * 6 + 2*NSlices*3 + 0] = i + NSlices+1;
        M2_indices[i * 6 + 2*NSlices*3 + 1] = i + NSlices+2;
        M2_indices[i * 6 + 2*NSlices*3 + 2] = (2+2*NSlices) + i + NSlices+1;

        M2_indices[i * 6 + 2*NSlices*3 + 3] = i + NSlices+1;
        M2_indices[i * 6 + 2*NSlices*3 + 4] = (2+2*NSlices) + i + NSlices+1;
        M2_indices[i * 6 + 2*NSlices*3 + 5] = (2+2*NSlices) + i + NSlices;
    }
    //Last triangles (closing ones)
    M2_indices[12*NSlices - 6] = NSlices + 1;
    M2_indices[12*NSlices - 5] = NSlices + NSlices;
    M2_indices[12*NSlices - 4] = 1 + 2*NSlices + 2*NSlices;

    M2_indices[12*NSlices - 3] = NSlices + 1;
    M2_indices[12*NSlices - 2] = 1 + 2*NSlices + 2*NSlices;
    M2_indices[12*NSlices - 1] = 1 + 2*NSlices + NSlices + 1;







//// M3 : Sphere
    // Replace the code below, that creates a simple triangle, with the one to create a sphere.

    // Resizes the vertices array.
    int slices = 30; //slices in which we divide each circle
    int levels = 18; //number of circles we draw to compose the sphere
    float rad; //radius of the circle we are drawing (used in a loop)
    float h; //height of the circle we are drawing (used in a loop)
    cx=0; //coordinates of the center of the sphere
    cy=0;
    cz=-3;

    M3_vertices.resize(1 + (levels-1)*slices + 1);

    // Bottom vertex
    M3_vertices[0].pos = {cx, cy-1, cz};
    M3_vertices[0].norm = {0.0, -1.0, 0.0};
    // Top vertex
    M3_vertices[1].pos = {cx, cy+1, cz};
    M3_vertices[1].norm = {0.0, 1.0, 0.0};

    for (int i = 1; i<levels; i++){
        rad = sin((float) (i*M_PI/levels));

        h = cos((float) (i*M_PI/levels));

        for (int k = 0; k < slices; k++){//points of each circle
            M3_vertices[((i-1)*slices) + k + 2].pos = {cx + rad * cos((float) (k * 2.0 * M_PI / slices)), cy + h, cz + rad * sin((float) (k * 2.0 * M_PI / slices))};
            M3_vertices[((i-1)*slices) + k + 2].norm = {cos((float) (k * 2.0 * M_PI / slices)), h, sin((float) (k * 2.0 * M_PI / slices))};
        }
    }


    // Resizes the indices array. Repalce the values with the correct number of
    // indices (3 * number of triangles)
    M3_indices.resize((slices + (levels-2) * (2*slices) + slices) * 3);

    // indices definitions
    for (int i=0; i<levels; i++){
        if (i==0){//top cap, we need to draw triangles from first circle to the top vertex
            for(int k = 0; k < slices; k++) {
                M3_indices[k * 3 + 0] = 1;
                M3_indices[k * 3 + 1] = k + 2;
                M3_indices[k * 3 + 2] = (k + 1) % slices + 2;
            }
        }
        else {
            if (i == levels - 1) {//bottom cap, we need to draw triangles from last circle to bottom vertex
                for (int k = 0; k < slices; k++) {
                    M3_indices[(slices + 2*slices * (i - 1)) * 3 + k * 3 + 0] = 0;
                    M3_indices[(slices + 2*slices * (i - 1)) * 3 + k * 3 + 1] = (i - 1) * slices + k + 2;
                    M3_indices[(slices + 2*slices * (i - 1)) * 3 + k * 3 + 2] = (i - 1) * slices + ((k + 1) % slices) + 2;
                }
            }
            else{
                for(int k = 0; k < slices; k++) {//we need to draw triangles to connect different circles
                    M3_indices[(slices + 2*slices*(i-1))*3 + k * 6 + 0] = (i - 1) * slices + k + 2;
                    M3_indices[(slices + 2*slices*(i-1))*3 + k * 6 + 1] = (i - 1) * slices + ((k + 1) % slices) + 2;
                    M3_indices[(slices + 2*slices*(i-1))*3 + k * 6 + 2] = i * slices + k + 2;

                    M3_indices[(slices + 2*slices*(i-1))*3 + k * 6 + 3] = i * slices + k + 2;
                    M3_indices[(slices + 2*slices*(i-1))*3 + k * 6 + 4] = i * slices + ((k + 1) % slices) + 2;
                    M3_indices[(slices + 2*slices*(i-1))*3 + k * 6 + 5] = (i - 1) * slices + ((k + 1) % slices) + 2;
                }
            }
        }
    }









//// M4 : Spring
    int circles = 200; //number of slices of each circle
    int vertices = 72; //number of circles we draw
    int idx = 0;
    int lvl = 3; //number of coils of the spring
    float lrad = 0.1; //radius of the circles
    cx = 0; //coordinates of the center of the spring
    cy = 0;
    cz = 0;

    // Replace the code below, that creates a simple octahedron, with the one to create a spring.
    M4_vertices.resize(2 + (circles+1)*vertices + 2*vertices);

    // Vertices definitions
    for (int i = 0; i < circles+1; i++) {
        cx = cos((float)(i * 2 * M_PI * lvl / circles));
        cy = cy + 0.006;
        cz = sin((float)(i * 2 * M_PI * lvl / circles));
        if (i == 0) {
            M4_vertices[idx].pos = {cx, cy, cz};//need to draw vertex of first circle to close the spring
            M4_vertices[idx].norm = {cz, 0.0, -cx};
            idx++;
            for (int k = 0; k < vertices; k++) {//first circle has also norms as the center (like in cylinder case)
                M4_vertices[idx].pos = {cx + lrad * cos((float)(i * 2 * M_PI * lvl / circles)) * cos((float)(k * 2 * M_PI / vertices)),
                                        cy + lrad * sin((float)(k * 2 * M_PI / vertices)),
                                        cz + lrad * sin((float)(i * 2 * M_PI * lvl / circles)) * cos((float)(k * 2 * M_PI / vertices))};
                M4_vertices[idx].norm = {cz, 0.0, -cx};
                idx++;
            }
        }
        for (int k = 0; k < vertices; k++) {
            M4_vertices[idx].pos = {cx + lrad * cos((float)(i * 2 * M_PI * lvl / circles)) * cos((float)(k * 2 * M_PI / vertices)),
                                    cy + lrad * sin((float)(k * 2 * M_PI / vertices)),
                                    cz + lrad * sin((float)(i * 2 * M_PI * lvl / circles)) * cos((float)(k * 2 * M_PI / vertices))};
            M4_vertices[idx].norm = {cos((float)(i * 2 * M_PI * lvl / circles)) * cos((float)(k * 2 * M_PI / vertices)),
                                     sin((float)(k * 2 * M_PI / vertices)),
                                     sin((float)(i * 2 * M_PI * lvl / circles)) * cos((float)(k * 2 * M_PI / vertices))};
            idx++;
        }
        if (i == circles) {//need to draw vertex of last circle to close the spring
            for (int k = 0; k < vertices; k++) {//last circle has also norms as the center (like in cylinder case)
                M4_vertices[idx].pos = {cx + lrad * cos((float)(i * 2 * M_PI * lvl / circles)) * cos((float)(k * 2 * M_PI / vertices)),
                                        cy + lrad * sin((float)(k * 2 * M_PI / vertices)),
                                        cz + lrad * sin((float)(i * 2 * M_PI * lvl / circles)) * cos((float)(k * 2 * M_PI / vertices))};
                M4_vertices[idx].norm = {-cz, 0.0, cx};
                idx++;
            }
            M4_vertices[idx].pos = {cx, cy, cz};
            M4_vertices[idx].norm = {-cz, 0.0, cx};
            idx++;
        }
    }


    // Resizes the indices array. Replace the values with the correct number of
    // indices (3 * number of triangles)
    M4_indices.resize((vertices + 2*(circles+1)*vertices + vertices) * 3);
    int triidx = 0;
    idx = 0;
    // indices definitions
    for (int i = 0; i < circles; i++) {
        if (i == 0) {
            for (int k = 0; k < vertices; k++) {//triangles to close spring (first circle)
                M4_indices[triidx + 0] = idx;
                M4_indices[triidx + 1] = idx + k + 1;
                M4_indices[triidx + 2] = idx + (k + 1) % vertices + 1;
                triidx = triidx + 3;
            }
            idx = idx + vertices + 1;
        }
        for (int k = 0; k < vertices; k++) {
            if (k == vertices - 1) {
                M4_indices[triidx + 0] = idx;
                M4_indices[triidx + 1] = vertices + (i * vertices) + 1;
                M4_indices[triidx + 2] = vertices + vertices * (i + 1) + 1;

                M4_indices[triidx + 3] = idx;
                M4_indices[triidx + 4] = vertices + vertices * (i + 1) + 1;
                M4_indices[triidx + 5] = vertices + vertices * (i + 1) + vertices;
                triidx = triidx + 6;
                idx = idx + 1;
            }
            else {
                M4_indices[triidx + 0] = idx;
                M4_indices[triidx + 1] = idx + 1;
                M4_indices[triidx + 2] = vertices + idx + 1;

                M4_indices[triidx + 3] = idx;
                M4_indices[triidx + 4] = vertices + idx;
                M4_indices[triidx + 5] = vertices + idx + 1;
                triidx = triidx + 6;
                idx = idx + 1;
            }
        }
    }
    idx = idx + 2*vertices;
    for (int k = 0; k < vertices; k++) {//triangles to close the spring (last circle)
        M4_indices[triidx + 0] = idx;
        M4_indices[triidx + 1] = idx - (k + 1);
        M4_indices[triidx + 2] = idx - ((k + 1) % vertices + 1);
        triidx = triidx + 3;
    }

}