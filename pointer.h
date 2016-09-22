#ifndef POINTER_H
#define POINTER_H

#include <GL/glx.h>
#include "types.h"

class Pointer{
private:
    Coordinate coor;
public:
    Pointer();
    void draw();
    void setCoor(GLfloat x, GLfloat y, GLfloat z);
    GLfloat getX();
    GLfloat getY();
    GLfloat getZ();
};

#endif // POINTER_H
