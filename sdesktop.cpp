#include "sdesktop.h"

SDesktop::SDesktop()
{
    init();
}

void SDesktop::init(){
    dpy = XOpenDisplay(NULL);
    scr = DefaultScreen(dpy);

    width = XDisplayWidth(dpy, scr);
    height = XDisplayHeight(dpy, scr);

    GLint att[]={
        GLX_RGBA,           True,
        GLX_DEPTH_SIZE,     XDisplayPlanes(dpy, scr),
        GLX_DOUBLEBUFFER,   True,
        None
    };

    vi = glXChooseVisual(dpy, scr, att);

    XSetWindowAttributes swa;

    swa.background_pixel = 0;
    swa.colormap = XCreateColormap(dpy, DefaultRootWindow(dpy), vi->visual, AllocNone);
    swa.event_mask = ExposureMask | KeyPressMask;

    win = XCreateWindow(dpy, DefaultRootWindow(dpy), 0, 0, width, height, 0, vi->depth, InputOutput,
                       vi->visual, CWColormap | CWEventMask | CWBackPixel, &swa);

    glc = glXCreateContext(dpy, vi, NULL, GL_TRUE);
    glXMakeCurrent(dpy, win, glc);

    play = false;
}

void SDesktop::launch(){
    play = true;
    XMapWindow(dpy, win);
    while(play){
        XNextEvent(dpy, &evnt);
    }
}
