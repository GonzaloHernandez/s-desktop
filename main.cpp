#include <iostream>
#include "sdesktop.h"
#include "widget.h"
#include "frame.h"
#include "button.h"

int main(int arg, char* argv[]){
    SDesktop * s_desktop = new SDesktop();
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
    Frame * frame = new Frame(-710, 390, 1, 1366, 768, c, c, "VentanaA");
    s_desktop->add(frame);
    Frame * frame1 = new Frame(0, 0, 0, 300, 300, c2, c, "VentanaB");
    s_desktop->add(frame1);
    Frame * frame2 = new Frame(-300, 300, 300, 300, 300, c2, c, "Frame");
    Button * button1 = new Button(10,100,100,20,c2,c2,"Button");
    //Button * button2 = new Button(10,130,50,20,c,c2,"Button");
    //Button * button3 = new Button(10,160,50,20,c,c2,"Button");
    frame->addWidget(button1);
    s_desktop->add(frame2);
    s_desktop->launch();
    delete s_desktop;
}
