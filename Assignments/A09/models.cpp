// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices
#include <corecrt_math_defines.h>
void makeModels() {
    //// M1 : Cube

    M1_vertices.resize(3 * 8);

    // first vertex of M1
    M1_vertices[0] = -1.0;
    M1_vertices[1] = -1.0;
    M1_vertices[2] = -1.0;

    // second vertex of M1
    M1_vertices[3] =  1.0;
    M1_vertices[4] = -1.0;
    M1_vertices[5] = -1.0;

    // third vertex of M1
    M1_vertices[6] =  1.0;
    M1_vertices[7] =  1.0;
    M1_vertices[8] = -1.0;

    // fourth vertex of M1
    M1_vertices[9] = -1.0;
    M1_vertices[10] =  1.0;
    M1_vertices[11] = -1.0;

    //fifth
    M1_vertices[12] = -1.0;
    M1_vertices[13] =  -1.0;
    M1_vertices[14] = 1.0;

    //sixth
    M1_vertices[15] = 1.0;
    M1_vertices[16] =  -1.0;
    M1_vertices[17] = 1.0;

    //seventh
    M1_vertices[18] = 1.0;
    M1_vertices[19] =  1.0;
    M1_vertices[20] = 1.0;

    //eigth
    M1_vertices[21] = -1.0;
    M1_vertices[22] =  1.0;
    M1_vertices[23] = 1.0;

    // Resizes the indices array. Repalce the values with the correct number of
    // indices (3 * number of triangles)
    M1_indices.resize(3 * 12);

    // first triangle
    M1_indices[0] = 0;
    M1_indices[1] = 1;
    M1_indices[2] = 2;

    // second triangle
    M1_indices[3] = 2;
    M1_indices[4] = 3;
    M1_indices[5] = 0;

    // third triangle
    M1_indices[6] = 4;
    M1_indices[7] = 5;
    M1_indices[8] = 6;

    // fourth triangle
    M1_indices[9] = 4;
    M1_indices[10] = 6;
    M1_indices[11] = 7;

    // fifth triangle
    M1_indices[12] = 1;
    M1_indices[13] = 2;
    M1_indices[14] = 5;

    // sixth triangle
    M1_indices[15] = 2;
    M1_indices[16] = 5;
    M1_indices[17] = 6;

    // seventh triangle
    M1_indices[18] = 0;
    M1_indices[19] = 3;
    M1_indices[20] = 4;

    // eigth triangle
    M1_indices[21] = 3;
    M1_indices[22] = 4;
    M1_indices[23] = 7;

    // ninth triangle
    M1_indices[24] = 2;
    M1_indices[25] = 3;
    M1_indices[26] = 6;

    // tenth triangle
    M1_indices[27] = 2;
    M1_indices[28] = 3;
    M1_indices[29] = 7;

    // eleventh triangle
    M1_indices[30] = 0;
    M1_indices[31] = 1;
    M1_indices[32] = 5;

    // twelfth triangle
    M1_indices[33] = 0;
    M1_indices[34] = 5;
    M1_indices[35] = 4;





    //// M2 : Cylinder
// Replace the code below, that creates a simple rotated square, with the one to create a cylinder.


    int NSlices = 72;
    float radius = 1;
    float height = 1;
    float cx = 0, cy = 0, cz = -3;
// Resizes the vertices array. 
    M2_vertices.resize((NSlices + 1) * 2 * 3);

// Vertices definitions
    M2_vertices[0]  =  cx;
    M2_vertices[1]  = cy + height;
    M2_vertices[2]  = cz;

    for(int i = 0; i < NSlices; i++) {
        M2_vertices[(i+1) * 3 + 0] = cx + radius * cos((float) (i*2.0*M_PI/NSlices)); // x of the vertex
        M2_vertices[(i+1) * 3 + 1] = cy + height; // y of the vertex
        M2_vertices[(i+1) * 3 + 2] = cz + radius * sin((float) (i*2.0*M_PI/NSlices)); // z of the vertex
    }

    M2_vertices[219]  =  cx;
    M2_vertices[220]  = cy - height;
    M2_vertices[221]  = cz;

    for(int i = 0; i < NSlices; i++) {
        M2_vertices[(i*3) + 222 + 0] = cx + radius * cos((float) (i*2.0*M_PI/NSlices)); // x of the vertex
        M2_vertices[(i*3) + 222 + 1] = cy - height; // y of the vertex
        M2_vertices[(i*3) + 222 + 2] = cz + radius * sin((float) (i*2.0*M_PI/NSlices)); // z of the vertex
    }

// Resizes the indices array. 
    M2_indices.resize(3 * 2 * NSlices * 2 * NSlices);

// indices definitions
    for(int i = 0; i < NSlices; i++) {
        M2_indices[i * 3 + 0] = 0;
        M2_indices[i * 3 + 1] = i + 1;
        M2_indices[i * 3 + 2] = (i + 1) % NSlices + 1;
    } 

    for(int i = 0; i < NSlices; i++) {
        M2_indices[i * 3 + 216 + 0] = 73;
        M2_indices[i * 3 + 216 + 1] = 73 + i + 1;
        M2_indices[i * 3 + 216 + 2] = 73 + (i + 1) % NSlices + 1;
    } 

    for(int i = 0; i < NSlices-1; i++) {
        if (i%2 == 0){
            M2_indices[i * 6 + 435 + 0] = i + 1;
            M2_indices[i * 6 + 435 + 1] = i + 2;
            M2_indices[i * 6 + 435 + 2] = 74 + i + 1;

            M2_indices[i * 6 + 435 + 3] = i + 1;
            M2_indices[i * 6 + 435 + 4] = 74 + i + 1;
            M2_indices[i * 6 + 435 + 5] = 74 + i;
        }
        else{
            M2_indices[i * 6 + 435 + 0] = i + 2;
            M2_indices[i * 6 + 435 + 1] = i + 1;
            M2_indices[i * 6 + 435 + 2] = 74 + i;

            M2_indices[i * 6 + 435 + 3] = i + 2;
            M2_indices[i * 6 + 435 + 4] = 74 + i + 1;
            M2_indices[i * 6 + 435 + 5] = 74 + i;
        }
    }
	//last indices
    M2_indices[651] = 1;
    M2_indices[652] = 72;
    M2_indices[653] = 145;

    M2_indices[654] = 1;
    M2_indices[655] = 145;
    M2_indices[656] = 74;


    //// M3 : Sphere
    // Replace the code below, that creates a simple triangle, with the one to create a sphere.

    // Resizes the vertices array. 
    int slices = 30;
    int levels = 30;
    float max_radius = 2;
    float max_height = 4;
    float rad;
    float h;
    cx=0;
    cy=0;
    cz=-3;

    M3_vertices.resize((2 + slices * levels)*3);

    // Bottom vertex
    M3_vertices[0] = cx;
    M3_vertices[1] = cy - 1;
    M3_vertices[2] = cz;
    // Top vertex
    M3_vertices[3] = cx;
    M3_vertices[4] = cy + 1;
    M3_vertices[5] = cz;

//Vertex definitions
    for (int i = 1; i<levels; i++){
        rad = sin((float) (i*M_PI/levels));

        h = cos((float) (i*M_PI/levels));

        for (int j = 0; j<slices; j++){
            M3_vertices[((i-1)*slices*3) + (j*3) + 6 + 0] = cx + rad * cos((float) (j*2.0*M_PI/slices)); // x of the vertex
            M3_vertices[((i-1)*slices*3) + (j*3) + 6 + 1] = cy + h; // y of the vertex
            M3_vertices[((i-1)*slices*3) + (j*3) + 6 + 2] = cz + rad * sin((float) (j*2.0*M_PI/slices)); // z of the vertex
        }
    }


    // Resizes the indices array.
    M3_indices.resize((60 + levels*slices*2) * 3);

    // indices definitions
    for (int i=0; i<levels; i++){
        if (i==0){
            for(int j = 0; j < slices; j++) {
                M3_indices[j * 3 + 0] = 1;
                M3_indices[j * 3 + 1] = j + 2;
                M3_indices[j * 3 + 2] = (j + 1) % slices + 2;
            }
        }
        else {
            if (i == levels - 1) {
                for (int j = 0; j < slices; j++) {
                    M3_indices[(30 + 60 * (i - 1)) * 3 + j * 3 + 0] = 0;
                    M3_indices[(30 + 60 * (i - 1)) * 3 + j * 3 + 1] = (i - 1) * slices + j + 2;
                    M3_indices[(30 + 60 * (i - 1)) * 3 + j * 3 + 2] =
                            (i - 1) * slices + ((j + 1) % slices) + 2; 
                }
            }
            else{
                for(int j = 0; j < slices; j++) {
                    M3_indices[(30 + 60*(i-1))*3 + j*6 + 0] = (i-1)*slices + j + 2;
                    M3_indices[(30 + 60*(i-1))*3 + j*6 + 1] = (i-1)*slices + ((j + 1) % slices) + 2;
                    M3_indices[(30 + 60*(i-1))*3 + j*6 + 2] = i*slices + j +2;

                    M3_indices[(30 + 60*(i-1))*3 + j*6 + 3] = i*slices + j + 2;
                    M3_indices[(30 + 60*(i-1))*3 + j*6 + 4] = i*slices + ((j + 1) % slices) + 2;
                    M3_indices[(30 + 60*(i-1))*3 + j*6 + 5] = (i-1)*slices + ((j + 1) % slices) + 2;
                }
            }
        }
    }









    //// M4 : Spring
    int circles = 600;
    int vertices = 100;
    int idx = 0;
    int lvl = 3;
    float lrad = 0.1;
    cx = 0;
    cy = 0;
    cz = 0;

    
    M4_vertices.resize((2 + (circles+1) * vertices) * 3);

    // Vertices definitions
    for (int i = 0; i < circles+1; i++) {
        cx = cos((float)(i * 2 * M_PI * lvl / circles));
        cy = cy + 0.003;
        cz = sin((float)(i * 2 * M_PI * lvl / circles));
        if (i == 0) {
            M4_vertices[idx + 0] = cx;
            M4_vertices[idx + 1] = cy;
            M4_vertices[idx + 2] = cz;
            idx = idx + 3;
        }
        for (int j = 0; j < vertices; j++) {
            M4_vertices[idx + 0] = cx + lrad * cos((float)(i * 2 * M_PI * lvl / circles)) * cos((float)(j * 2 * M_PI / vertices));
            M4_vertices[idx + 1] = cy + lrad * sin((float)(j * 2 * M_PI / vertices));
            M4_vertices[idx + 2] = cz + lrad * sin((float)(i * 2 * M_PI * lvl / circles)) * cos((float)(j * 2 * M_PI / vertices));
            idx = idx + 3;
        }
        if (i == circles) {
            M4_vertices[idx + 0] = cx;
            M4_vertices[idx + 1] = cy;
            M4_vertices[idx + 2] = cz;
            idx = idx + 3;
        }
    }


    // Resizes the indices array. 
    M4_indices.resize((2 * vertices * (circles+1) + 2*vertices) * 3);
    int triidx = 0;
    idx = 0;
    // indices definitions
    for (int i = 0; i < circles; i++) {
        if (i == 0 ) {
            for (int j = 0; j < vertices; j++) {
                M4_indices[triidx + 0] = idx;
                M4_indices[triidx + 1] = idx + j + 1;
                M4_indices[triidx + 2] = idx + (j + 1) % vertices + 1;
                triidx = triidx + 3;
            }
            idx = idx + 1;
        }
        for (int j = 0; j < vertices; j++) {
            if (j == vertices - 1) {
                M4_indices[triidx + 0] = idx;
                M4_indices[triidx + 1] = (i * vertices) + 1;
                M4_indices[triidx + 2] = vertices * (i + 1) + 1;

                M4_indices[triidx + 3] = idx;
                M4_indices[triidx + 4] = vertices * (i + 1) + 1;
                M4_indices[triidx + 5] = vertices * (i + 1) + vertices;
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
	//last one
    idx = idx + vertices;
    for (int j = 0; j < vertices; j++) {
        M4_indices[triidx + 0] = idx;
        M4_indices[triidx + 1] = idx - (j + 1);
        M4_indices[triidx + 2] = idx - ((j + 1) % vertices + 1);
        triidx = triidx + 3;
    }
}