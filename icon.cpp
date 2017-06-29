#include "icon.h"
#include "button.h"
#include "types.h"
#include <iostream>

Icon::Icon(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height,
             color forecolor, color backcolor, const char text[]="")
            :Widget(x,y,700-(z*200),width,height,forecolor,backcolor,text)//510-100
{
    texture = loadTexture("icon.bmp");
}

void Icon::draw(){
    if(!hidden){
        glColor3f(1.0, 1.0, 1.0);
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_CONSTANT);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
            glTexCoord2i(0, 1);
            glVertex3f(x,y,z);
            glTexCoord2i(0, 0);
            glVertex3f(x,y-height,z);
            glTexCoord2i(1, 0);
            glVertex3f(x+width,y-height,z);
            glTexCoord2i(1, 1);
            glVertex3f(x+width,y,z);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        //FontOBJ * font = new FontOBJ("../s-desktop/fonts.obj");
        //font->drawText(text,x+(width/2.0)-(nChar/2.0)*40*0.4, y-18, z+1.0, 30);
        //delete font;
    }
}

const char* Icon::type(){
    return "Icon";
}

GLuint Icon::loadTexture(const char *fileName){
    FILE *file;
    unsigned char header[54];
    unsigned int dataPos;
    unsigned int size;
    unsigned int width, height;
    unsigned char *data;


    file = fopen(fileName, "rb");

    if (file == NULL)
    {
        return false;
    }

    if (fread(header, 1, 54, file) != 54)
    {
        return false;
    }

    if (header[0] != 'B' || header[1] != 'M')
    {
        return false;
    }

    dataPos     = *(int*)&(header[0x0A]);
    size        = *(int*)&(header[0x22]);
    width       = *(int*)&(header[0x12]);
    height      = *(int*)&(header[0x16]);

    if (size == NULL)
        size = width * height * 3;
    if (dataPos == NULL)
        dataPos = 54;

    data = new unsigned char[size];

    fread(data, 1, size, file);

    for(int i=0; i<size; i+=3){
        char a = data[i];
        data[i] = data[i+2];
        data[i+2] = a;
    }

    fclose(file);
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    return texture;
}
