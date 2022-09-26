// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices

#include <corecrt_math_defines.h>
struct Vertex {
	glm::vec3 pos;
	glm::vec3 norm;
	glm::vec2 UV;
};

std::vector<Vertex> M1_vertices;
std::vector<Vertex> M2_vertices;


void makeModels() {
//// M1 : Cube
    M1_vertices.resize(3 * 8); //done

    // first vertex of M1
    M1_vertices[0].pos = {-1.0, -1.0, -1.0};
    M1_vertices[0].norm = {0.0, -1.0, 0.0};
    M1_vertices[0].UV = {0.125, 0.5};

    M1_vertices[1].pos = {-1.0, -1.0, -1.0};
    M1_vertices[1].norm = {-1.0, 0.0, 0.0};
    M1_vertices[1].UV = {0.125, 0.0};

    M1_vertices[2].pos = {-1.0, -1.0, -1.0};
    M1_vertices[2].norm = {0.0, 0.0, -1.0};
    M1_vertices[2].UV = {0.0, 0.375};


    // second vertex of M1
    M1_vertices[3].pos = {1.0, -1.0, -1.0};
    M1_vertices[3].norm = {0.0, -1.0, 0.0};
    M1_vertices[3].UV = {0.125, 0.375};

    M1_vertices[4].pos = {1.0, -1.0, -1.0};
    M1_vertices[4].norm = {1.0, 0.0, 0.0};
    M1_vertices[4].UV = {0.125, 0.375};

    M1_vertices[5].pos = {1.0, -1.0, -1.0};
    M1_vertices[5].norm = {0.0, 0.0, -1.0};
    M1_vertices[5].UV = {0.125, 0.375};


    // third vertex of M1
    M1_vertices[6].pos = {1.0, 1.0, -1.0};
    M1_vertices[6].norm = {0.0, 1.0, 0.0};
    M1_vertices[6].UV = {0.125, 0.25};

    M1_vertices[7].pos = {1.0, 1.0, -1.0};
    M1_vertices[7].norm = {1.0, 0.0, 0.0};
    M1_vertices[7].UV = {0.125, 0.25};

    M1_vertices[8].pos = {1.0, 1.0, -1.0};
    M1_vertices[8].norm = {0.0, 0.0, -1.0};
    M1_vertices[8].UV = {0.125, 0.25};


    // fourth vertex of M1
    M1_vertices[9].pos = {-1.0, 1.0, -1.0};
    M1_vertices[9].norm = {0.0, 1.0, 0.0};
    M1_vertices[9].UV = {0.125, 0.125};

    M1_vertices[10].pos = {-1.0, 1.0, -1.0};
    M1_vertices[10].norm = {-1.0, 0.0, 0.0};
    M1_vertices[10].UV = {0.125, 0.125};

    M1_vertices[11].pos = {-1.0, 1.0, -1.0};
    M1_vertices[11].norm = {0.0, 0.0, -1.0};
    M1_vertices[11].UV = {0.0, 0.25};


    //fifth vertex of M1
    M1_vertices[12].pos = {-1.0, -1.0, 1.0};
    M1_vertices[12].norm = {0.0, -1.0, 0.0};
    M1_vertices[12].UV = {0.25, 0.5};

    M1_vertices[13].pos = {-1.0, -1.0, 1.0};
    M1_vertices[13].norm = {-1.0, 0.0, 0.0};
    M1_vertices[13].UV = {0.25, 0.0};

    M1_vertices[14].pos = {-1.0, -1.0, 1.0};
    M1_vertices[14].norm = {0.0, 0.0, 1.0};
    M1_vertices[14].UV = {0.375, 0.375};


    //sixth vertex of M1
    M1_vertices[15].pos = {1.0, -1.0, 1.0};
    M1_vertices[15].norm = {0.0, -1.0, 0.0};
    M1_vertices[15].UV = {0.25, 0.375};

    M1_vertices[16].pos = {1.0, -1.0, 1.0};
    M1_vertices[16].norm = {1.0, 0.0, 0.0};
    M1_vertices[16].UV = {0.25, 0.375};

    M1_vertices[17].pos = {1.0, -1.0, 1.0};
    M1_vertices[17].norm = {0.0, 0.0, 1.0};
    M1_vertices[17].UV = {0.25, 0.375};


    //seventh vertex of M1
    M1_vertices[18].pos = {1.0, 1.0, 1.0};
    M1_vertices[18].norm = {0.0, 1.0, 0.0};
    M1_vertices[18].UV = {0.25, 0.25};

    M1_vertices[19].pos = {1.0, 1.0, 1.0};
    M1_vertices[19].norm = {1.0, 0.0, 0.0};
    M1_vertices[19].UV = {0.25, 0.25};

    M1_vertices[20].pos = {1.0, 1.0, 1.0};
    M1_vertices[20].norm = {0.0, 0.0, 1.0};
    M1_vertices[20].UV = {0.25, 0.25};


    //eighth vertex of M1
    M1_vertices[21].pos = {-1.0, 1.0, 1.0};
    M1_vertices[21].norm = {0.0, 1.0, 0.0};
    M1_vertices[21].UV = {0.25, 0.125};

    M1_vertices[22].pos = {-1.0, 1.0, 1.0};
    M1_vertices[22].norm = {-1.0, 0.0, 0.0};
    M1_vertices[22].UV = {0.25, 0.125};

    M1_vertices[23].pos = {-1.0, 1.0, 1.0};
    M1_vertices[23].norm = {0.0, 0.0, 1.0};
    M1_vertices[23].UV = {0.375, 0.25};


    // Resizes the indices array. Repalce the values with the correct number of
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

    int NSlices = 36; //number of slices in which we divide each circle
    float radius = 1;
    float height = 1;
    float cx = 0, cy = 0, cz = -3;

    M2_vertices.resize(1 + NSlices + NSlices + NSlices + NSlices + 1 + 2); //last two the ones replicated for the texture

// Vertices definitions
    M2_vertices[0].pos  =  {cx, cy + height, cz};//top cap center
    M2_vertices[0].norm = {0.0, 1.0, 0.0};
    M2_vertices[0].UV = {0.625, 0.125};

    int j = 0;
    for(int i = 1; i <= NSlices; i++) {//top cap ring
        M2_vertices[i].pos = {cx + radius * cos((float) (j*2.0*M_PI/NSlices)), cy + height, cz + radius * sin((float) (j*2.0*M_PI/NSlices))};
        M2_vertices[i].norm = {0.0, 1.0, 0.0};
        M2_vertices[i].UV = {0.625 + 0.125*cos((float) (j*2.0*M_PI/NSlices)), 0.125 + 0.125*sin((float) (j*2.0*M_PI/NSlices))};
        j++;
    }
    j = 0;
    for(int i = NSlices+1; i <= 2*NSlices; i++) {//upper side ring
        M2_vertices[i].pos = {cx + radius * cos((float) (j*2.0*M_PI/NSlices)), cy + height, cz + radius * sin((float) (j*2.0*M_PI/NSlices))};
        M2_vertices[i].norm = {cos((float) (j*2.0*M_PI/NSlices)), 0.0, sin((float) (j*2.0*M_PI/NSlices))};
        M2_vertices[i].UV = {1 - (j*0.5)/NSlices, 0.25};

        if (j==0){ //vertex in same position but with different UV coord
            M2_vertices[4*NSlices+2].pos = {cx + radius * cos((float) (j*2.0*M_PI/NSlices)), cy + height, cz + radius * sin((float) (j*2.0*M_PI/NSlices))};
            M2_vertices[4*NSlices+2].norm = {cos((float) (j*2.0*M_PI/NSlices)), 0.0, sin((float) (j*2.0*M_PI/NSlices))};
            M2_vertices[4*NSlices+2].UV = {0.5, 0.25};
        }

        j++;
    }

    M2_vertices[2*NSlices+1].pos  =  {cx, cy-height, cz};//bottom cap center
    M2_vertices[2*NSlices+1].norm = {0.0, -1.0, 0.0};
    M2_vertices[2*NSlices+1].UV = {0.875, 0.125};

    j = 0;
    for(int i = 2*NSlices+2; i <= 3*NSlices+1; i++) {//bottom cap ring
        M2_vertices[i].pos = {cx + radius * cos((float) (j*2.0*M_PI/NSlices)), cy - height, cz + radius * sin((float) (j*2.0*M_PI/NSlices))};
        M2_vertices[i].norm = {0.0, -1.0, 0.0};
        M2_vertices[i].UV = {0.875 + 0.125*cos((float) (j*2.0*M_PI/NSlices)), 0.125 + 0.125*sin((float) (j*2.0*M_PI/NSlices))};
        j++;
    }
    j = 0;
    for(int i = 3*NSlices+2; i <= 4*NSlices+1; i++) {//bottom side ring
        M2_vertices[i].pos = {cx + radius * cos((float) (j*2.0*M_PI/NSlices)), cy - height, cz + radius * sin((float) (j*2.0*M_PI/NSlices))};
        M2_vertices[i].norm = {cos((float) (j*2.0*M_PI/NSlices)), 0.0, sin((float) (j*2.0*M_PI/NSlices))};
        M2_vertices[i].UV = {1 - (j*0.5)/NSlices, 0.5};

        if (j==0){//vertex in same position but with different UV coord
            M2_vertices[4*NSlices+3].pos = {cx + radius * cos((float) (j*2.0*M_PI/NSlices)), cy - height, cz + radius * sin((float) (j*2.0*M_PI/NSlices))};
            M2_vertices[4*NSlices+3].norm = {cos((float) (j*2.0*M_PI/NSlices)), 0.0, sin((float) (j*2.0*M_PI/NSlices))};
            M2_vertices[4*NSlices+3].UV = {0.5, 0.5};
        }

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
    //Last triangles
    M2_indices[12*NSlices - 6] = 4*NSlices + 2;
    M2_indices[12*NSlices - 5] = NSlices + NSlices;
    M2_indices[12*NSlices - 4] = 1 + 2*NSlices + 2*NSlices;

    M2_indices[12*NSlices - 3] = 4*NSlices + 2;
    M2_indices[12*NSlices - 2] = 1 + 2*NSlices + 2*NSlices;
    M2_indices[12*NSlices - 1] = 4*NSlices + 3;


}