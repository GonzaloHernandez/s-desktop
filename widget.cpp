#include "widget.h"
#include <cstring>

Widget::Widget(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat length,
               const char text[]="", ulong forecolor=0, ulong backcolor=0xFFFFFF)
               :x(x),y(y),z(z),width(width),height(height),length(length),forecolor(forecolor),
                backcolor(backcolor)
{
    strcpy(this->text, text);
    action = &defaultAction;
    taggedAction = &defaultTaggedAction;
    referencedAction = &defaultReferencedAction;
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

void Widget::setForecolor(ulong forecolor){
    this->forecolor = forecolor;
    draw();
}

void Widget::setBackcolor(ulong backcolor){
    this->backcolor = backcolor;
    draw();
}

void Widget::draw(){}

Widget::~Widget(){}
