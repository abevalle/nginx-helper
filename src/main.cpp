#include <string>
#include <iostream>
#include "menu.cpp"

int main() {
    string startOpts[] = { "Create New Nginx Site", "Disable Nginx Site", "View all Nginx Sites", "exit" };
    menu start;
    start.newMenu(startOpts);
    start.start();
    return 0;
}