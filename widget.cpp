#include "widget.h"
#include <cstring>

Widget::Widget(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height,
               color forecolor, color backcolor, const char text[]="")
               :x(x),y(y),z(z),width(width),height(height),forecolor(forecolor),
                backcolor(backcolor)
{
    strcpy(this->text, text);
    action = &defaultAction;
    taggedAction = &defaultTaggedAction;
    referencedAction = &defaultReferencedAction;
    active = false;
}

bool Widget::triggerEvent(XEvent &){
    return false;
}

bool Widget::mouseInArea(XEvent &evnt){             //Event to z ------------------------> *
    int mx = evnt.xbutton.x;
    int my = evnt.xbutton.y;

    if(mx > x && mx < x+width && my > y && my < y+height){
        return true;
    }
    return false;
}

void Widget::setFocused(bool){
    this->focused = false;
}

GLfloat Widget::getX(){
    return x;
}

GLfloat Widget::getY(){
    return y;
}

GLfloat Widget::getZ(){
    return z;
}

char * Widget::getText(){
    return text;
}

void Widget::setText(const char text[]){
    strcpy(this->text, text);
    draw();
}

void Widget::show(){
    hidden = false;
    draw();
}

void Widget::setForecolor(color forecolor){
    this->forecolor = forecolor;
    draw();
}

void Widget::setBackcolor(color backcolor){
    this->backcolor = backcolor;
    draw();
}

void Widget::draw(){}

Widget::~Widget(){}

void Widget::setParent(Widget* widget){
    parent = widget;
}

Widget * Widget::getParent(){
    return parent;
}

void Widget::setActive(bool active){
    this->active = active;
}
