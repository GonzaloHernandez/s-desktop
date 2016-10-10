#include "sdesktop.h"
#include <iostream>
#include "frame.h"

SDesktop::SDesktop()
{
    init();
}

void SDesktop::init(){
    dpy = XOpenDisplay(NULL);
    scr = DefaultScreen(dpy);

    width = XDisplayWidth(dpy, scr);
    height = XDisplayHeight(dpy, scr);
    width = 1920;
    height = 1080;

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
    swa.event_mask = ExposureMask | KeyPressMask | PointerMotionMask;

    win = XCreateWindow(dpy, DefaultRootWindow(dpy), 0, 0, width, height, 0, vi->depth, InputOutput,
                       vi->visual, CWColormap | CWEventMask | CWBackPixel, &swa);

    glc = glXCreateContext(dpy, vi, NULL, GL_TRUE);
    glXMakeCurrent(dpy, win, glc);

    play = false;

    glEnable(GL_DEPTH_TEST);
}

void SDesktop::launch(){
    play = true;
    XMapWindow(dpy, win);
    changeSize();
    while(play){
        XNextEvent(dpy, &evnt);
        switch(evnt.type){
            case Expose:
                draw();
            break;
            case MotionNotify:
            break;
            case KeyPress:
                switch(evnt.xkey.keycode){
                    case 9:
                        XCloseDisplay(dpy);
                        play = false;
                    break;
                    case 23:
                        draw();
                    break;
                    case 52:
                        ((Frame *)(widgets[0]))->widgets->setActive(true);
                    break;
                    default:
                        std::cout << evnt.xkey.keycode << std::endl;
                    break;
                }
            break;
        }
    }
}

bool SDesktop::add(Widget *widget){
    for(int i=0; i<MAX; i++) if(!widgets[i]){
        widgets[i] = widget;
        return true;
    }
    return false;
}

void SDesktop::render(){
    for(int i=0; i<MAX; i++){
        if(widgets[i]){
            widgets[i]->draw();
        }
        else{
            break;
        }
    }
}

void SDesktop::draw(){
    glClearColor(.62f, .81f, .93f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glViewport(0,0,width/2.0,height);
    gluLookAt(-RANGE/2, 0.0, 680.0, -RANGE/2, 0.0, 0.0, 0.0, 1.0, 0.0);
    render();
    glPopMatrix();
    glPushMatrix();
    glViewport(width/2.0, 0, width/2, height);
    gluLookAt(RANGE/2, 0.0, 680.0, RANGE/2, 0.0, 0.0, 0.0, 1.0, 0.0);
    render();
    glPopMatrix();
    glXSwapBuffers(dpy, win);
}

void SDesktop::changeSize(){
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, (GLfloat)width/(GLfloat)height, 0.1, 3000);
    glMatrixMode(GL_MODELVIEW);
}
