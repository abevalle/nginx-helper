#include <iostream>
#include <string>
#include <array>
using namespace std;

class menu {
    public:
        string opts[5];
        int optsLen;

    void newMenu(string *optList, int len) {
        optsLen = len;
        for(unsigned int i = 0; i < optsLen; i = i + 1 ) {
            opts[i] = optList[i];
        }
    }

    void start() {
        cout << "Welcome to Ngnix Utils" << endl;
        cout << "Please select from an option below" << endl;
        listOpts();
    }

    int exit(int code) {
        cout << "good bye.";
        return code;
    };

    int listOpts() {
        for( unsigned int a = 0; a < optsLen; a = a + 1 ) {
            cout << a+1 << ": " << opts[a] << '\n';
        }
        getUserOpt();

        return 0;
    };

    int getUserOpt() {
        int opt;
        cout << "Please select and option: ";
        cin >> opt;
        if ((opt >= 1) && (opt <= optsLen-1)) {
            cout << optsLen << endl;
        } else if (opt == optsLen) {
            exit(1);
        }

        return opt;
    };

};