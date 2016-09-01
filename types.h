#ifndef TYPES_H
#define TYPES_H

#include <GL/glx.h>
#include <GL/glu.h>

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;

enum AlignmentType{
    LEFT, RIGTH, CENTER
};

struct color{
    float r;
    float g;
    float b;
    float a=1.0f;
};

#endif // TYPES_H
