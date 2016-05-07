#include "widget.h"
#include <cstring>

Widget::Widget(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat length, const char text[]):
    x(x),y(y),z(z),width(width),height(height),length(length)
{
    strcpy(this->text, text);
}
