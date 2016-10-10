#include "button.h"
#include <iostream>

Button::Button(GLfloat x, GLfloat y, GLfloat width, GLfloat height,
             color forecolor, color backcolor, const char text[]="")
            :Widget(x,y,0,width,height,forecolor,backcolor,text)
{



}

void Button::draw(){
    if (active){
        glBegin(GL_QUADS);
            glColor3f(forecolor.r,forecolor.g,forecolor.b);
            glVertex3f(parent->getX()+x,parent->getY()+y,parent->getZ()+2);
            glVertex3f(parent->getX()+x,parent->getY()+y-height,parent->getZ()+2);
            glVertex3f(parent->getX()+x+width,parent->getY()+y-height,parent->getZ()+2);
            glVertex3f(parent->getX()+x+width,parent->getY()+y,parent->getZ()+2);
        glEnd();
        glLineWidth(2.0);
        glBegin(GL_LINE_LOOP);
            glColor3f(1.0f,1.0f,1.0f);
            glVertex3f(parent->getX()+x,parent->getY()+y,parent->getZ()+2);
            glVertex3f(parent->getX()+x,parent->getY()+y-height,parent->getZ()+2);
            glVertex3f(parent->getX()+x+width,parent->getY()+y-height,parent->getZ()+2);
            glVertex3f(parent->getX()+x+width,parent->getY()+y,parent->getZ()+2);
        glEnd();
        std::cout << active << std::endl;
    }
    else{
        glBegin(GL_QUADS);
            glColor3f(forecolor.r,forecolor.g,forecolor.b);
            glVertex3f(parent->getX()+x,parent->getY()+y,parent->getZ()+5);
            glVertex3f(parent->getX()+x,parent->getY()+y-height,parent->getZ()+5);
            glVertex3f(parent->getX()+x+width,parent->getY()+y-height,parent->getZ()+5);
            glVertex3f(parent->getX()+x+width,parent->getY()+y,parent->getZ()+5);
        glEnd();
        glLineWidth(2.0);
        glBegin(GL_LINE_LOOP);
            glColor3f(1.0f,1.0f,1.0f);
            glVertex3f(parent->getX()+x,parent->getY()+y,parent->getZ()+5);
            glVertex3f(parent->getX()+x,parent->getY()+y-height,parent->getZ()+5);
            glVertex3f(parent->getX()+x+width,parent->getY()+y-height,parent->getZ()+5);
            glVertex3f(parent->getX()+x+width,parent->getY()+y,parent->getZ()+5);
        glEnd();
        std::cout << active << std::endl;
    }

}

bool Button::triggerEvent(XEvent &){
    // ...
}


