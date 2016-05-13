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

    static void defaultAction(){}
    static void defaultTaggedAction(char []){}
    static void defaultReferencedAction(Widget *){}

public:
    Widget(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat length,
           const char text[], ulong forecolor, ulong backcolor);

    void (*action)();
    void (*taggedAction)(char text[]);
    void (*referencedAction)(Widget *ref);

    bool mouseInArea(XEvent & evnt);
    GLfloat getX();
    GLfloat getY();
    GLfloat getZ();
    char *getText();
    void setText(const char text[]);
    void show();
    void setForecolor(ulong forecolor);
    void setBackcolor(ulong backcolor);
    virtual void setFocused(bool);
    virtual bool triggerEvent(XEvent&);
    virtual void draw();
    virtual ~Widget();
};

#endif // WIDGET_H
