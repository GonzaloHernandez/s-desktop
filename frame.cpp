#include "frame.h"
#include "button.h"
#include "types.h"
#include <iostream>

//void (*closedAction)();


void closeWindow(Widget* button){
//    (*closedAction)();
    button->getParent()->hide();
}

Frame::Frame(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height,
             color forecolor, color backcolor, const char text[]="")
            :Widget(x,y,700-(z*200),width,height,forecolor,backcolor,text)//510-100
{
    widgets = new Widget*[MAX];
    c_widget = 0;
    for(int i=0; i<MAX; i++){
        widgets[i] = NULL;
    }
    color buttons;
    buttons.r = forecolor.r-0.5f;
    buttons.g = forecolor.g-0.5f;
    buttons.b = forecolor.b-0.5f;
    Button * close = new Button(width-27,5,20,20,buttons,buttons,"X");
    Button * mini = new Button(width-52,5,20,20,buttons,buttons,"m");
    Button * maxi = new Button(width-77,5,20,20,buttons,buttons,"O");
    addWidget(close);
    addWidget(mini);
    addWidget(maxi);
    close->action = &closeWindow;
}

void Frame::draw(){
    if(!hidden){
        glBegin(GL_QUADS);
            glColor3f(forecolor.r-0.3f,forecolor.g-0.3f,forecolor.b-0.3f);
            glVertex3f(x,y,z);
            glVertex3f(x,y-30,z);
            glVertex3f(x+width,y-30,z);
            glVertex3f(x+width,y,z);
            glColor3f(forecolor.r,forecolor.g,forecolor.b);
            glVertex3f(x,y-30,z);
            glVertex3f(x,y-height,z);
            glVertex3f(x+width,y-height,z);
            glVertex3f(x+width,y-30,z);
        glEnd();
        glLineWidth(2.0);
        glBegin(GL_LINE_LOOP);
            glColor3f(forecolor.r+0.1f,forecolor.g+0.1f,forecolor.b+0.1f);
            glVertex3f(x,y,z);
            glVertex3f(x,y-height,z);
            glVertex3f(x+width,y-height,z);
            glVertex3f(x+width,y,z);
        glEnd();
        FontOBJ * font = new FontOBJ("../s-desktop/fonts.obj");
        font->drawText(text,x+(width/2.0)-(nChar/2.0)*40*0.4, y-18, z+1.0, 30);
        delete font;
        renderWidgets();
    }
}

void Frame::addWidget(Widget *widget){
    for(int i=0; i<MAX; i++){
        if(!widgets[i]){
            widgets[i] = widget;
            widgets[i]->setParent(this);
            c_widget++;
            return;
        }
    }
    if(c_widget<MAX){
        widgets[c_widget] = widget;
        widgets[c_widget]->setParent(this);
        c_widget++;
    }
}

void Frame::renderWidgets(){
    for(int i=0; i<c_widget; i++){
        widgets[i]->draw();
    }
}

const char* Frame::type(){
    return "Frame";
}

Widget* Frame::widgetFocused(Pointer* pointer){
    for(int i=0; i<MAX; i++){
        if(widgets[i]){
            if(widgets[i]->mouseInArea(pointer)){
                return widgets[i];
            }
        }
    }
    return NULL;
}
