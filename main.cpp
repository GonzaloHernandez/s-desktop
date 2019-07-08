#include <iostream>
#include "sdesktop.h"
#include "widget.h"
#include "frame.h"
#include "button.h"

static SDesktop * s_desktop = new SDesktop();
static int nivel=1;
static float x = 50.0f;
static float col=0.2f;

void reset(Widget *){
    nivel = 1;
    col = 0.2f;
}

void action(Widget *){
    color c;
    c.r = 1-col;
    c.g = 1-col*0.3f;
    c.b = 1-col*0.7f;
    Frame * frame = new Frame(-450,-50,nivel,300,200,c,c,"Window");
    nivel++;
    x+=50;
    col+=0.1f;
    s_desktop->add(frame);
}

void quit(Widget *) {
    exit(0);
}

int main(int , char* []){
    color c  = {0.8f , 0.8f , 0.8f};
    color c1 = {1.0f , 1.0f , 1.0f};
    color c2 = {0.9f , 0.9f , 0.9f};

    Frame * fr_creator = new Frame(0, 0, 1, 300, 100, c1, c, "Window Creator");
    fr_creator->action =&quit;
    s_desktop->add(fr_creator);
    Frame * fr_example = new Frame(-300, 300, 2, 300, 300, c2, c, "Frame Example");

    Button * bt_add = new Button(10,35,100,20,c,c,"Add Window");
    bt_add->action = &action;
    Button * bt_reset = new Button(10,60,100,20,c,c,"Reset");
    bt_reset->action = &reset;

    fr_creator->addWidget(bt_add);
    fr_creator->addWidget(bt_reset);

    s_desktop->add(fr_example);

    s_desktop->launch();
    delete s_desktop;
}
