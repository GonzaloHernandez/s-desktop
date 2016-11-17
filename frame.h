#ifndef FRAME_H
#define FRAME_H

#include "widget.h"
#include <iostream>

class Frame : public Widget{
    static const int MAX=500;
private:
    Widget ** widgets;
    int c_widget;

    void renderWidgets();
    static void closeWindow(Widget* button){
        button->getParent()->hide();
    }

public:
    Frame(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, color forecolor, color backcolor, const char text[]);
    void draw();
    void addWidget(Widget * widget);
    Widget * widgetFocused(XEvent&, float z);
    const char* type();
};

#endif // FRAME_H
