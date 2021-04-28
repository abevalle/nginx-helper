#include <string>
#include <iostream>
#include "menu.cpp"

int main() {
    string startOpts[] = { "Create New Nginx Site", "Disable Nginx Site", "View all Nginx Sites", "exit" };
    menu start;
    start.newMenu(startOpts, sizeof(startOpts)/sizeof(startOpts[0]));
    start.start();
    return 0;
}