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
    c1.r = 0.0;
    c1.g = 0.0;
    c1.b = 0.0;
    color c2;
    c2.r = 0.7;
    c2.g = 0.7;
    c2.b = 0.9;
    Frame * frame = new Frame(-200, 200, 310, 800, 600, c1, c, "Frame");
    s_desktop->add(frame);
    Frame * frame1 = new Frame(-50, -400, -1000, 300, 300, c, c, "Frame");
    s_desktop->add(frame1);
    Frame * frame2 = new Frame(-300, 300, 300, 300, 300, c2, c, "Frame");
    Button * button1 = new Button(10,100,50,20,c1,c2,"Button");
    Button * button2 = new Button(10,130,50,20,c1,c2,"Button");
    Button * button3 = new Button(10,160,50,20,c1,c2,"Button");
    frame->addWidget(button1);
    frame->addWidget(button2);
    frame->addWidget(button3);
    s_desktop->add(frame2);
    for(int i=0; i<20; i++){
        Frame *b = new Frame(10*i,10*i,400,10,10,c1,c2,"");
        for(int j=0; j<40; j++){
            b->addWidget(new Button(0,0,3,3,c,c2,""));
        }
        s_desktop->add(b);
    }
    s_desktop->launch();
    delete s_desktop;
}
