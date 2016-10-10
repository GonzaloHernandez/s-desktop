#include "sdesktop.h"
#include <iostream>

SDesktop::SDesktop()
{
    init();
}

void SDesktop::init(){
    dpy = XOpenDisplay(NULL);
    scr = DefaultScreen(dpy);

    width = XDisplayWidth(dpy, scr);
    height = XDisplayHeight(dpy, scr);
//    width = 2722;
//    height = 768;

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
    swa.event_mask = ExposureMask | KeyPressMask | ButtonPressMask | PointerMotionMask;

    win = XCreateWindow(dpy, DefaultRootWindow(dpy), 0, 0, width, height, 0, vi->depth, InputOutput,
                       vi->visual, CWColormap | CWEventMask | CWBackPixel, &swa);

    glc = glXCreateContext(dpy, vi, NULL, GL_TRUE);
    glXMakeCurrent(dpy, win, glc);

    play = false;

    glEnable(GL_DEPTH_TEST);

    pointer = new Pointer();
}

void SDesktop::launch(){
    play = true;
    changeSize();
    XMapWindow(dpy, win);
    while(play){
        XNextEvent(dpy, &evnt);
        switch(evnt.type){
            case Expose:
                draw();
            break;
            case MotionNotify:
                pointer->setCoor(evnt.xmotion.x-width/2.0, height/2.0-evnt.xmotion.y, pointer->getZ());
                std::cout << "x:" << pointer->getX() << "y:" << pointer->getY() << "z:" << pointer->getZ() << std::endl;
                draw();
            break;
            case ButtonPress:
                std::cout << evnt.xbutton.button << std::endl;
                switch(evnt.xbutton.button){
                    case 4:
                        pointer->setCoor(pointer->getX(), pointer->getY(), pointer->getZ()+100);
                        draw();
                    break;
                    case 5:
                        pointer->setCoor(pointer->getX(), pointer->getY(), pointer->getZ()-100);
                        draw();
                    break;
                }
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
            glPushMatrix();
            widgets[i]->draw();
            glPopMatrix();
        }
        else{
            break;
        }
    }
    pointer->draw();
}

void SDesktop::draw(){
    glClearColor(0.2f,0.2f,0.2f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glViewport(0,0,width/2.0,height);
    glLoadIdentity();
    glPushMatrix();
    gluLookAt(-RANGE/2.0,0,1200,-RANGE/2.0,0,0,0,1,0);
    render();
    glPopMatrix();
    glViewport(width/2.0,0,width/2.0,height);
    glLoadIdentity();
    glPushMatrix();
    gluLookAt(RANGE/2.0,0,1200,RANGE/2.0,0,0,0,1,0);
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
