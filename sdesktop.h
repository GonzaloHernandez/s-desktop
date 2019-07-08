#ifndef SDESKTOP_H
#define SDESKTOP_H

#include "types.h"
#include "widget.h"
#include "pointer.h"

class SDesktop{
    static const int   MAX = 500;
    static constexpr float RANGE = 10.0f;
private:
    Display *               dpy;
    bool                    play;
    int                     scr;
    Window                  win;
    uint                    width;
    uint                    height;
    XVisualInfo *           vi;
    XEvent                  evnt;
    GLXContext              glc;
    Widget *                widgets[MAX];
    Pointer *               pointer;

    void changeSize();
    void draw();
    void render();

public:
    SDesktop();
    ~SDesktop();
    void init();
    void launch();
    bool add(Widget *widget);
    bool remove(Widget *widget);
};

#endif // SDESKTOP_H
