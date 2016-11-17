#include "pointer.h"
#include <iostream>

Pointer::Pointer()
{
    coor.x = 0;
    coor.y = 0;
    coor.z = 802;//512
}

void Pointer::draw(){
    glPushMatrix();
    glBegin(GL_TRIANGLES);
        glColor3f(1.0,1.0,1.0);
        glVertex3f(coor.x, coor.y, coor.z);
        glVertex3f(coor.x, coor.y-10, coor.z);
        glVertex3f(coor.x+10, coor.y, coor.z);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glLineWidth(2.0);
        glColor3f(0.0,0.0,0.0);
        glVertex3f(coor.x, coor.y, coor.z);
        glVertex3f(coor.x, coor.y-10, coor.z);
        glVertex3f(coor.x+10, coor.y, coor.z);
    glEnd();
    glPopMatrix();
}

void Pointer::setCoor(GLfloat x, GLfloat y, GLfloat z){
    coor.x = x;
    coor.y = y;
    if(z <= MAX && z >= MIN)
        coor.z = z;
}

GLfloat Pointer::getX(){
    return coor.x;
}

GLfloat Pointer::getY(){
    return coor.y;
}

GLfloat Pointer::getZ(){
    return coor.z;
}
