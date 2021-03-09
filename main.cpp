using namespace std;
#include <iostream>
#include <string>
#include <regex>
#include "validation.cpp"

int getHostInfo() {
    // Get info for the host machine
    string HOST;
    string HOST_PORT;
    cout << "Enter the host domain: ";
    cin >> HOST;
    cout << "Enter the listening port on the host machine: ";
    cin >> HOST_PORT;

    isValidDomain(HOST);
    isPortValid(HOST_PORT);
    return 0;   
}

int getProxyInfo() {
    // Get info for the proxy machine
    string PROXY_HOST;
    string PROXY_HOST_PORT;
    cout << "\nEnter the domain for the proxy host: ";
    cin >> PROXY_HOST;
    cout << "\nEnter the port for the proxy host: ";
    cin >> PROXY_HOST_PORT;
    
    isValidDomain(PROXY_HOST);
    isPortValid(PROXY_HOST_PORT);
    return 0;   
}

int main() {

    cout << "Nginx Config Utility\n";
    getHostInfo();
    return 0;   
}

    // ToDo
    // Query if the user it using a domain or an ip for their proxy_pass
    // domain validation function
    // port validation function
    // ip validation