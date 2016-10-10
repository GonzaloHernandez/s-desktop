#include "pointer.h"

Pointer::Pointer()
{
    coor.x = 0;
    coor.y = 0;
    coor.z = 0;
}

void Pointer::draw(){
    glPushMatrix();
    glBegin(GL_TRIANGLES);
        glVertex3f(coor.x, coor.y, coor.z);
        glVertex3f(coor.x, coor.y-10, coor.z);
        glVertex3f(coor.x+10, coor.y, coor.z);
    glEnd();
    glPopMatrix();
}

void Pointer::setCoor(GLfloat x, GLfloat y, GLfloat z){
    coor.x = x;
    coor.y = y;
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
