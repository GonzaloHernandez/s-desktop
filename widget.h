#ifndef WIDGET_H
#define WIDGET_H

#ifndef GLX_H
#include <GL/glx.h>
#endif

class Widget{
protected:
    GLfloat         x,y,z;
    GLfloat         width,height,length;
    char            text[256];
    Display*        dpy;
    int             scr;
    Window          win;
    GLXContext*     glc;
public:
    Widget(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat length, const char text[]);
};

#endif // WIDGET_H
