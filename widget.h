#ifndef WIDGET_H
#define WIDGET_H

#include "pointer.h"
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

    static void defaultAction(Widget*){}
    static void defaultTaggedAction(char []){}
    static void defaultReferencedAction(Widget *){}

public:
    Widget(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height,
           color forecolor, color backcolor, const char text[]);

    void (*action)(Widget*);
    void (*taggedAction)(char text[]);
    void (*referencedAction)(Widget *ref);

    bool mouseInArea(Pointer* pointer);
    GLfloat getX();
    GLfloat getY();
    GLfloat getZ();
    GLfloat getWidth();
    GLfloat getHeight();
    char *getText();
    void setText(const char text[]);
    void show();
    void setForecolor(color forecolor);
    void setBackcolor(color backcolor);
    void setParent(Widget * parent);
    Widget* getParent();
    virtual void setFocused(bool focused);
    virtual bool triggerEvent(XEvent&);
    virtual void draw();
    virtual const char * type();
    void hide();
    virtual ~Widget();
};

#endif // WIDGET_H
