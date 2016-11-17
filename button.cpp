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
                glVertex3f(getParent()->getX()+x,getParent()->getY()-y, getParent()->getZ()+.3);
                glVertex3f(getParent()->getX()+x,getParent()->getY()-y-height, getParent()->getZ()+.3);
                glVertex3f(getParent()->getX()+x+width,getParent()->getY()-y-height, getParent()->getZ()+.3);
                glVertex3f(getParent()->getX()+x+width,getParent()->getY()-y, getParent()->getZ()+.3);
            }
            else{
                glVertex3f(getParent()->getX()+x,getParent()->getY()-y, getParent()->getZ()+.7);
                glVertex3f(getParent()->getX()+x,getParent()->getY()-y-height, getParent()->getZ()+.7);
                glVertex3f(getParent()->getX()+x+width,getParent()->getY()-y-height, getParent()->getZ()+.7);
                glVertex3f(getParent()->getX()+x+width,getParent()->getY()-y, getParent()->getZ()+.7);
            }
        glEnd();
        FontOBJ *font = new FontOBJ("../s-desktop/fonts.obj");
        if(font){
            font->drawText(text,getParent()->getX()+x+10,getParent()->getY()-y-height/2.0-0.5,getParent()->getZ()+1.0,20);
        }
        delete font;
        glPopMatrix();
    }
}

const char* Button::type(){
    return "Button";
}

