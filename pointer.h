#ifndef POINTER_H
#define POINTER_H

#include <GL/glx.h>

class Pointer{
private:
    struct Coordinate{
        GLfloat x;
        GLfloat y;
        GLfloat z;
    }coor;
    static constexpr float MAX=512;
    static constexpr float MIN=-512;
public:
    Pointer();
    void draw();
    void setCoor(GLfloat x, GLfloat y, GLfloat z);
    GLfloat getX();
    GLfloat getY();
    GLfloat getZ();
};

#endif // POINTER_H
