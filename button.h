#ifndef BUTTON_H
#define BUTTON_H

#include "widget.h"

class Button:public Widget{
private:
    bool active;
public:
    Button(GLfloat x, GLfloat y, GLfloat width, GLfloat height,
           color forecolor, color backcolor, const char text[]);

    void draw();
    const char* type();
    void setActive(bool active);

    bool triggerEvent(XEvent& event, Pointer* pointer);
};

#endif // BUTTON_H
