#ifndef SDESKTOP_H
#define SDESKTOP_H

#include "types.h"

class SDesktop{
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
public:
    SDesktop();
    void init();
    void launch();
};

#endif // SDESKTOP_H
