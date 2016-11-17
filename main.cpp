#include <iostream>
#include "sdesktop.h"
#include "widget.h"
#include "frame.h"
#include "button.h"

SDesktop * s_desktop = new SDesktop();
int nivel=1;
float x = 50;
float col=0.2;

static void action(Widget*){
    color c;
    c.r = 1-col;
    c.g = 1-col*0.3;
    c.b = 1-col*0.7;
    Frame * frame = new Frame(-600,280,nivel,300,200,c,c,"Window");
    nivel++;
    x+=50;
    col+=0.1;
    s_desktop->add(frame);
}

int main(int arg, char* argv[]){
    color c;
    c.r = 0.5;
    c.g = 0.5;
    c.b = 0.5;
    color c1;
    c1.r = 0.0;
    c1.g = 0.0;
    c1.b = 0.0;
    color c2;
    c2.r = 0.9;
    c2.g = 0.9;
    c2.b = 0.9;
    Frame * frame = new Frame(-10, 20, 1, 500, 300, c, c, "Ventana A");
    //s_desktop->add(frame);                                                                    //añadir
    Frame * frame1 = new Frame(0, 0, 0, 300, 300, c2, c, "Ventana B");
    s_desktop->add(frame1);
    Frame * frame2 = new Frame(-300, 300, 300, 300, 300, c2, c, "Frame");
    Button * button1 = new Button(10,35,100,20,c,c,"Add Window");
    button1->action = &action;
    //Button * button2 = new Button(10,130,50,20,c,c2,"Button");
    //Button * button3 = new Button(10,160,50,20,c,c2,"Button");
    frame1->addWidget(button1);
    //s_desktop->add(frame2);
    s_desktop->launch();
    delete s_desktop;
}
