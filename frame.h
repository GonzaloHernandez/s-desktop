#ifndef FRAME_H
#define FRAME_H

#include "widget.h"

class Frame : public Widget{
private:
public:
    Widget* widgets;
    Frame(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, color forecolor, color backcolor, const char text[]);
    void addWidget(Widget* widget);
    float getX();
    float getY();
    float getZ();
    void draw();
    void render();
};

#endif // FRAME_H
