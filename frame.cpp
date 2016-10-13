#include "frame.h"
#include "button.h"
#include "types.h"
#include <iostream>

Frame::Frame(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height,
             color forecolor, color backcolor, const char text[]="")
            :Widget(x,y,510-(z*50),width,height,forecolor,backcolor,text)
{
    widgets = new Widget*[MAX];
    c_widget = 0;
    color buttons;
    buttons.r = 0.5;
    buttons.g = 0.5;
    buttons.b = 0.5;
    Button * close = new Button(width-27,5,20,20,buttons,buttons,"X");
    Button * mini = new Button(width-52,5,20,20,buttons,buttons,"");
    Button * maxi = new Button(width-77,5,20,20,buttons,buttons,"");
    addWidget(close);
    addWidget(mini);
    addWidget(maxi);
}

void Frame::draw(){
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
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
        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(x,y,z);
        glVertex3f(x,y-height,z);
        glVertex3f(x+width,y-height,z);
        glVertex3f(x+width,y,z);
    glEnd();
    FontOBJ * font = new FontOBJ("../s-desktop/fonts.obj");
    font->drawText(text,x+(width/2.0)-(nChar/2.0)*40*0.4, y-20, z+1.0, 40);
    delete font;
    renderWidgets();
}

void Frame::addWidget(Widget *widget){
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
