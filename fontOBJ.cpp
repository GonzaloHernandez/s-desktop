#include "fontOBJ.h"
#include <iostream>
#include <GL/gl.h>

FontOBJ::FontOBJ(const char* name){
    Assimp::Importer importer;
    const aiScene * scene = importer.ReadFile(name,
                                              aiProcess_CalcTangentSpace |
                                              aiProcess_Triangulate |
                                              aiProcess_SortByPType);
    if(!scene){
        std::cout << "Error al abrir el archivo " << name << std::endl;
    }

    for(int i=0; i<scene->mNumMeshes; i++){
        letras[i].nVert = 0;
        letras[i].vert = new coor[scene->mMeshes[i]->mNumVertices];
        letras[i].index = new int[scene->mMeshes[i]->mNumFaces * 2];

        for(int j=0; j<scene->mMeshes[i]->mNumVertices; j++){
            letras[i].vert[j].x = scene->mMeshes[i]->mVertices[j].x;
            letras[i].vert[j].y = scene->mMeshes[i]->mVertices[j].y;
            letras[i].vert[j].z = scene->mMeshes[i]->mVertices[j].z;
        }

        int in = 0;
        for(int j=0; j<scene->mMeshes[i]->mNumFaces; j++){
            letras[i].nVert += scene->mMeshes[i]->mFaces[j].mNumIndices;
            for(int k=0; k<scene->mMeshes[i]->mFaces[j].mNumIndices; k++,in++){
                letras[i].index[in] = scene->mMeshes[i]->mFaces[j].mIndices[k];
            }
        }
    }
}

void FontOBJ::drawText(const char* texto, float x, float y, float z, float size){
    float posx = 0;
    if(strcmp(texto,"")==0){
        return;
    }
    char letra = '1';
    int pos = 0;
    while(letra != '\0'){
        letra = texto[pos];
        if(letra != '\0'){
            int let = (int)letra;
            if(let >= 65 && let <= 90){
                let -= 65;
            }
            else if(let>=97 && let <=122){
                let -= 97;
            }
            let = 25 - let;
            glPushMatrix();
            for(int i=0; i<letras[let].nVert; i+=2){
                glLineWidth(1.0);
                glBegin(GL_LINES);
                    glColor3f(0.0,0.0,0.0);
                    glVertex3f(x+posx+letras[let].vert[letras[let].index[i]].x*size,y+letras[let].vert[letras[let].index[i]].y*size,z+letras[let].vert[letras[let].index[i]].z);
                    glVertex3f(x+posx+letras[let].vert[letras[let].index[i+1]].x*size,y+letras[let].vert[letras[let].index[i+1]].y*size,z+letras[let].vert[letras[let].index[i+1]].z);
                glEnd();
            }
            glPopMatrix();
        }
        pos++;
        posx+=.4*size;
    }
}

