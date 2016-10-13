#ifndef WIDGET_H
#define WIDGET_H

#include "types.h"
#include "fontOBJ.h"

class Widget{
protected:
    GLfloat         x,y,z;
    GLfloat         width,height;
    char            text[256];
    int             nChar;
    bool            focused;
    bool            hidden;
    color           forecolor;
    color           backcolor;
    Widget *        parent;

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
    void setParent(Widget * parent);
    Widget* getParent();
    virtual void setFocused(bool);
    virtual bool triggerEvent(XEvent&);
    virtual void draw();
    virtual ~Widget();
};

#endif // WIDGET_H
