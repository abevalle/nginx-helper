#include <iostream>
#include <string>
#include <array>
using namespace std;

class menu {
    public:
        string opts;
        int optsLen;

    void newMenu(string optList[]) {
        optsLen = sizeof(optList)/sizeof(optList[0]);
        opts[optsLen] = optList;
    }

    void start() {
        

        cout << "Welcome to Ngnix Utils" << endl;
        cout << "Please select from an option below" << endl;
        listOpts(opts, optsLen);
    }

    int listOpts() {
        for( unsigned int a = 0; a < optsLen; a = a + 1 ) {
            cout << a+1 << ": " << opts[a] << '\n';
        }
        getUserOpt(opts, optsLen);

        return 0;
    };

    int getUserOpt() {
        int opt;
        cout << "Please select and option: ";
        cin >> opt;
        if ((opt >= 1) && (opt <= optsLen)) {

        } else {
            return 1;
        }

        return opt;
    };

};