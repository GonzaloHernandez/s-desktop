#include "button.h"

Button::Button(GLfloat x, GLfloat y, GLfloat width, GLfloat height, color forecolor, color backcolor, const char text[])
    :Widget(x,y,0,width,height,forecolor,backcolor,text)
{
    active = false;
}

void Button::draw(){
    glPushMatrix();
    glBegin(GL_QUADS);
        if(active){
            glVertex3f(getParent()->getX()+x,getParent()->getY()-y, getParent()->getZ()*-100+5);
            glVertex3f(getParent()->getX()+x,getParent()->getY()-y-height, getParent()->getZ()*-100+5);
            glVertex3f(getParent()->getX()+x+width,getParent()->getY()-y-height, getParent()->getZ()*-100+5);
            glVertex3f(getParent()->getX()+x+width,getParent()->getY()-y, getParent()->getZ()*-100+5);
        }
        else{
            glVertex3f(getParent()->getX()+x,getParent()->getY()-y, getParent()->getZ()*-100+10);
            glVertex3f(getParent()->getX()+x,getParent()->getY()-y-height, getParent()->getZ()*-100+10);
            glVertex3f(getParent()->getX()+x+width,getParent()->getY()-y-height, getParent()->getZ()*-100+10);
            glVertex3f(getParent()->getX()+x+width,getParent()->getY()-y, getParent()->getZ()*-100+10);
        }
    glEnd();
    glPopMatrix();
}
