#include <iostream>
#include <widget.h>

int main(int arg, char* argv[]){
    Widget * widget = new Widget(0, 0, 0, 10, 10, 10, "widget");
    delete widget;
}
