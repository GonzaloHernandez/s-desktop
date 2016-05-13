#ifndef WIDGET_H
#define WIDGET_H

#include "types.h"

class Widget{
protected:
    GLfloat         x,y,z;
    GLfloat         width,height,length;
    char            text[256];
    bool            focused;
    bool            hidden;
    ulong           forecolor;
    ulong           backcolor;
public:
    Widget(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat length, const char text[]);
};

#endif // WIDGET_H
