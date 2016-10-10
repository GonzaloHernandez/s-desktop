#ifndef WIDGET_H
#define WIDGET_H

#include "types.h"

class Widget{
protected:
    GLfloat         x,y,z;
    GLfloat         width,height;
    char            text[256];
    bool            focused;
    bool            hidden;
    color           forecolor;
    color           backcolor;
    Widget * parent;
    bool active;
    static void defaultAction(){}
    static void defaultTaggedAction(char []){}
    static void defaultReferencedAction(Widget *){}

public:
    Widget(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height,
           color forecolor, color backcolor, const char text[]);

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
    void setForecolor(color forecolor);
    void setBackcolor(color backcolor);
    virtual void setFocused(bool);
    virtual bool triggerEvent(XEvent&);
    virtual void draw()=0;
    void setParent(Widget*);
    Widget* getParent();
    virtual ~Widget();

    void setActive(bool active);
};

#endif // WIDGET_H
