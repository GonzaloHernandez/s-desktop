#include <iostream>
#include "sdesktop.h"
#include "widget.h"
#include "frame.h"
#include "button.h"

SDesktop * s_desktop = new SDesktop();
int nivel=1;
float x = 50;
float col=0.2;

void reset(Widget *){
    nivel = 1;
    col = 0.2;
}

void action(Widget *){
    color c;
    c.r = 1-col;
    c.g = 1-col*0.3;
    c.b = 1-col*0.7;
    Frame * frame = new Frame(-450,-50,nivel,300,200,c,c,"Window");
    nivel++;
    x+=50;
    col+=0.1;
    s_desktop->add(frame);
}

int main(int , char* []){
    color c  = {0.5 , 0.5 , 0.5};
    color c1 = {1.0 , 1.0 , 1.0};
    color c2 = {0.9 , 0.9 , 0.9};

    Frame * frame1 = new Frame(0, 0, 1, 300, 100, c1, c, "Ventana B");
    s_desktop->add(frame1);
    Frame * frame2 = new Frame(-300, 300, 300, 300, 300, c2, c, "Frame");

    Button * button1 = new Button(10,35,100,20,c,c,"Add Window");
    button1->action = &action;
    Button * button2 = new Button(10,60,100,20,c,c,"Reset");
    button2->action = &reset;

    frame1->addWidget(button1);
    frame1->addWidget(button2);

    s_desktop->add(frame2);

    s_desktop->launch();
    delete s_desktop;
}
