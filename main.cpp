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
    c.b = 0.9;
    color c1;
    c1.r = 0.1;
    c1.g = 1.0;
    c1.b = 0.1;
    color c2;
    c2.r = 0.7;
    c2.g = 0.7;
    c2.b = 0.9;
    //Frame * frame = new Frame(-300, 200, 300, 200, 200, c1, c, "Frame");
    //s_desktop->add(frame);
    Frame * frame1 = new Frame(-100, 300, -100, 800, 600, c, c, "Frame");
    Button* button = new Button(100,-100,100,20,c1,c1,"ñLKJAD");
    frame1->addWidget(button);
    s_desktop->add(frame1);
//    Frame * frame2 = new Frame(-300, -450, 300, 300, 300, c2, c, "Frame");
//    s_desktop->add(frame2);
    s_desktop->launch();
    delete s_desktop;
}
