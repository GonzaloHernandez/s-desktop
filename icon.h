#ifndef ICON_H
#define ICON_H

#include "widget.h"
#include <iostream>

class Icon : public Widget{
private:
    GLuint texture;

    GLuint loadTexture(const char *filename);
public:
    Icon(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, color forecolor, color backcolor, const char text[]);
    void draw();
    const char* type();
};

#endif // ICON_H
