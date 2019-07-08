#include "button.h"
#include <iostream>

Button::Button(GLfloat x, GLfloat y, GLfloat width, GLfloat height, color forecolor, color backcolor, const char text[])
    :Widget(x,y,0,width,height,forecolor,backcolor,text)
{
    active = false;
}

void Button::draw(){
    if(!hidden){
        glPushMatrix();
        glColor3f(forecolor.r,forecolor.g,forecolor.b);
        glBegin(GL_QUADS);
            if(active){
                glVertex3f(getParent()->getX()+x,getParent()->getY()-y, getParent()->getZ()+.6);
                glVertex3f(getParent()->getX()+x,getParent()->getY()-y-height, getParent()->getZ()+.6);
                glVertex3f(getParent()->getX()+x+width,getParent()->getY()-y-height, getParent()->getZ()+.6);
                glVertex3f(getParent()->getX()+x+width,getParent()->getY()-y, getParent()->getZ()+.6);
            }
            else{
                glVertex3f(getParent()->getX()+x,getParent()->getY()-y, getParent()->getZ()+.9);
                glVertex3f(getParent()->getX()+x,getParent()->getY()-y-height, getParent()->getZ()+.9);
                glVertex3f(getParent()->getX()+x+width,getParent()->getY()-y-height, getParent()->getZ()+.9);
                glVertex3f(getParent()->getX()+x+width,getParent()->getY()-y, getParent()->getZ()+.9);
            }
        glEnd();
        FontOBJ *font = new FontOBJ("../s-desktop/fonts.obj");
        if(font){
            if(active){
                font->drawText(text,getParent()->getX()+x+10,getParent()->getY()-y-height/2.0-0.5,getParent()->getZ()+1.4,20);
            }
            else{
                font->drawText(text,getParent()->getX()+x+10,getParent()->getY()-y-height/2.0-0.5,getParent()->getZ()+1.5,20);
            }
        }
        delete font;
        glPopMatrix();
    }
}

const char* Button::type(){
    return "Button";
}

void Button::setActive(bool active){
    this->active = active;
}

bool Button::triggerEvent(XEvent& event, Pointer* pointer) {
    switch (event.type) {
        case ButtonPress:
            if (mouseInArea(pointer)) {
                active = true;
                draw();
            }
            break;
        case ButtonRelease:
            if (active && mouseInArea(pointer)) {
                active = false;
                draw();
                (*action)(this);
//                (*taggedAction)(text);
//                (*referencedAction)(this);
                return true;
            }
            break;
        case MotionNotify:
            if (active && !mouseInArea(pointer)) {
                active = false;
                draw();
            }
    }
    return false;
}
