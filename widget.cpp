#include "widget.h"
#include <cstring>
#include <iostream>

Widget::Widget(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height,
               color forecolor, color backcolor, const char text[]="")
               :x(x),y(y),z(z),width(width),height(height),forecolor(forecolor),
                backcolor(backcolor)
{
    strcpy(this->text, text);
    nChar = 0;
    while(text[nChar] != '\0'){
        nChar++;
    }
    hidden = false;
    action = &defaultAction;
    taggedAction = &defaultTaggedAction;
    referencedAction = &defaultReferencedAction;
    parent = NULL;
}

bool Widget::triggerEvent(XEvent &){
    return false;
}

bool Widget::mouseInArea(Pointer* pointer){             //Event to z ------------------------> *
    float mx = pointer->getX();
    float my = pointer->getY();
    float z = pointer->getZ();
    if(!getParent()){
        if(z >= this->z && z < this->z+50){
            if(mx > x && mx < x+width && my < y && my > y-height){
                return true;
            }
        }
    }
    else{
        if(z > this->getParent()->getZ() && z < this->getParent()->getZ()+50){
            if(mx > getParent()->getX()+x && mx < getParent()->getX()+x+width && my < getParent()->getY()-y && my > getParent()->getY()-height-y){
                return true;
            }
        }
    }
    return false;
}

void Widget::setFocused(bool focused){
    this->focused = focused;
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

color Widget::getBackcolor()
{
    return backcolor;
}

void Widget::setText(const char text[]){
    strcpy(this->text, text);
    draw();
}

void Widget::show(){
    hidden = false;
}

void Widget::setForecolor(color forecolor){
    this->forecolor = forecolor;
    draw();
}

void Widget::setBackcolor(color backcolor){
    this->backcolor = backcolor;
    draw();
}

void Widget::setParent(Widget * parent){
    this->parent = parent;
}

void Widget::setX(GLfloat x)
{
    this->x = x;
    draw();
}

void Widget::setY(GLfloat y)
{
    this->y = y;
    draw();
}

void Widget::setWidth(GLfloat width)
{
    this->width = width;
    draw();
}

void Widget::setHeight(GLfloat height)
{
    this->height = height;
    draw();
}

Widget* Widget::getParent(){
    return parent;
}

void Widget::draw(){}

const char* Widget::type(){
    return "Widget";
}

GLfloat Widget::getWidth(){
    return width;
}

GLfloat Widget::getHeight(){
    return height;
}

void Widget::hide(){
    hidden = true;
    (*action)(this);
}

Widget::~Widget(){}
