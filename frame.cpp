#include "frame.h"
#include <iostream>

Frame::Frame(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height,
             color forecolor, color backcolor, const char text[]="")
            :Widget(x,y,z,width,height,forecolor,backcolor,text)
{

}

void Frame::draw(){
    glBegin(GL_QUADS);
        glColor3f(forecolor.r,forecolor.g,forecolor.b);
        glVertex3f(x,y,z);
        glVertex3f(x,y-height,z);
        glVertex3f(x+width,y-height,z);
        glVertex3f(x+width,y,z);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(x,y,z);
        glVertex3f(x,y-height,z);
        glVertex3f(x+width,y-height,z);
        glVertex3f(x+width,y,z);
    glEnd();
}
