#include <string>
#include <iostream>
#include "menu.cpp"
#include "nginx.cpp"

int main() {
    string startOpts[] = { "Create New Nginx Site", "exit" };
    // ToDO
    // Add the following menu items
    // "Disable Nginx Site", "View all Nginx Sites",
    cout << isValidDomain("google.com");

    menu start;
    start.newMenu(startOpts, sizeof(startOpts)/sizeof(startOpts[0]));
    start.start();
    int startOpt = start.userOpt();
    switch (startOpt)
    {
    case 1:
        Nginx newSite;
        newSite.init();
        break;
    }


    return 0;
}