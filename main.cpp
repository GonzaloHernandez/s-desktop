#include <iostream>
#include "sdesktop.h"

int main(int arg, char* argv[]){
    SDesktop * s_desktop = new SDesktop();
    s_desktop->launch();
    delete s_desktop;
}
