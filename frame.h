#ifndef FRAME_H
#define FRAME_H

#include "widget.h"

class Frame : public Widget{
private:
public:
    Frame(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, color forecolor, color backcolor, const char text[]);
    void draw();
};

#endif // FRAME_H
