#ifndef FONT_H
#define FONT_H

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/mesh.h>

struct coor{
    float x;
    float y;
    float z;
};

class FontOBJ{
private:
    struct letra{
        coor * vert;
        int * index;
        int nVert;
    }letras[26];
public:
    FontOBJ(const char *name);
    void drawText(const char* texto, float x, float y, float z, float size);
};

#endif // FONT_H
