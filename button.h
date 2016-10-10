#ifndef BUTTON_H
#define BUTTON_H

#include <widget.h>
#include <frame.h>

class Button : public Widget{
public:
    Button(GLfloat x, GLfloat y, GLfloat width, GLfloat height,
           color forecolor, color backcolor, const char text[]);
    void draw();
    bool triggerEvent(XEvent &);

};

#endif // BUTTON_H
