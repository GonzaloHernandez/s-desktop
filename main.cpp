#include <iostream>
#include "sdesktop.h"
#include "widget.h"
#include "frame.h"

int main(int arg, char* argv[]){
    SDesktop * s_desktop = new SDesktop();
    color c;
    c.r = 0.5;
    c.g = 0.5;
    c.b = 0.9;
    color c1;
    c1.r = 0.0;
    c1.g = 0.0;
    c1.b = 0.0;
    color c2;
    c2.r = 0.7;
    c2.g = 0.7;
    c2.b = 0.9;
    Frame * frame = new Frame(-200, -100, 100, 300, 300, c1, c, "Frame");
    s_desktop->add(frame);
    Frame * frame1 = new Frame(-50, -400, -1000, 300, 300, c, c, "Frame");
    s_desktop->add(frame1);
    Frame * frame2 = new Frame(-300, -450, 300, 300, 300, c2, c, "Frame");
    s_desktop->add(frame2);
    s_desktop->launch();
    delete s_desktop;
}
