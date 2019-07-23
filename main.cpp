#include <iostream>
#include "sdesktop.h"
#include "widget.h"
#include "frame.h"
#include "button.h"

static SDesktop * s_desktop = new SDesktop();
static float nivel=1;
static float x = 50.0f;
static float col=0.2f;

Frame * fr_creator=NULL;
Frame * fr_current=NULL;

void moveUp(Widget *) {
    if (fr_current) {
        fr_current->setY(fr_current->getY()+10);
    }
}

void moveLeft(Widget *) {
    if (fr_current) {
        fr_current->setX(fr_current->getX()-10);
    }
}

void moveDown(Widget *) {
    if (fr_current) {
        fr_current->setY(fr_current->getY()-10);
    }
}

void moveRight(Widget *) {
    if (fr_current) {
        fr_current->setX(fr_current->getX()+10);
    }
}

void action(Widget *){
    color c;
    c.r = 1-col;
    c.g = 1-col*0.3f;
    c.b = 1-col*0.7f;
    fr_current = new Frame(-450,-50,nivel,300,200,c,c,"Window");
    nivel+=0.5f;
    x+=50;
    col+=0.1f;
    s_desktop->add(fr_current);
}

void quit(Widget *) {
    exit(0);
}

int main(int , char* []){
    color c  = {0.8f , 0.8f , 0.8f};
    color c1 = {1.0f , 1.0f , 1.0f};
    color c2 = {0.9f , 0.9f , 0.9f};

    fr_creator = new Frame(0, 0, 1, 300, 100, c1, c, "Window Control");
    fr_creator->action =&quit;
    s_desktop->add(fr_creator);

    Button * bt_add = new Button(20,60,100,20,c,c,"Add Window");
    bt_add->action = &action;
    Button * bt_up      = new Button(180,35,20,20,c,c,"");
    bt_up->action   = &moveUp;
    Button * bt_left    = new Button(150,60,20,20,c,c,"");
    bt_left->action   = &moveLeft;
    Button * bt_down    = new Button(180,60,20,20,c,c,"");
    bt_down->action   = &moveDown;
    Button * bt_right   = new Button(210,60,20,20,c,c,"");
    bt_right->action   = &moveRight;

    fr_creator->addWidget(bt_add);
    fr_creator->addWidget(bt_up);
    fr_creator->addWidget(bt_left);
    fr_creator->addWidget(bt_down);
    fr_creator->addWidget(bt_right);

    s_desktop->launch();
    delete s_desktop;
}
