#ifndef FRAME_H
#define FRAME_H

#include "widget.h"

class Frame : public Widget{
    static const int MAX=500;
private:
    Widget ** widgets;
    int c_widget;

    void renderWidgets();
public:
    Frame(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, color forecolor, color backcolor, const char text[]);
    void draw();
    void addWidget(Widget * widget);
};

#endif // FRAME_H
