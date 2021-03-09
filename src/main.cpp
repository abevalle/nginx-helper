using namespace std;
#include <iostream>
#include <string>
#include <regex>
#include "validation.cpp"

int getProxyInfo() {
    // Get info for the proxy machine
    string PROXY_HOST;
    string PROXY_HOST_PORT;
    cout << "Enter the domain or ip for the proxy: (This is your proxy_pass): ";
    cin >> PROXY_HOST;
    cout << "Enter the port for the proxy host (This is the port your proxy_pass will listen on): ";
    cin >> PROXY_HOST_PORT;
    
    // Detect if user is using an ip or domain for thair proxy_pass
    if (isIpOrDomain(PROXY_HOST) == 1) {
        cout<<"You are using an ip as your proxy_pass";
    } else if (isIpOrDomain(PROXY_HOST) == 2) {
        cout<<"you are using a domain as your proxy_pass";
    } else if (isIpOrDomain(PROXY_HOST) == 0) {
        cout<<"ERR: something went wrong check your entry!! Then try again.";
    }

    return 0;   
}

int getHostInfo() {
    // Get info for the host machine
    string HOST;
    string HOST_PORT;
    cout << "Enter the host domain: ";
    cin >> HOST;
    cout << "Enter the listening port on the host machine: ";
    cin >> HOST_PORT;


    if (isValidDomain(HOST) == false && isValidPort(HOST_PORT) == false) {
        cout<<"Host domain and port are invalid!";
    } else if (isValidDomain(HOST) == false) {
        cout<<"Host domain is invalid!";
    } else if (isValidPort(HOST_PORT) == false) {
        cout<<"Host port is invalid!";
    } else if (isValidDomain(HOST) && isValidPort(HOST_PORT)) {
        getProxyInfo();
    }
    return 0;   
}

int start() {
    cout<<"Welcome to nginx-utils\n";
    cout<<"Made by Abe Valle\n";
    cout<<"To use please follow the prompts\n";
    getHostInfo();
    return 0;
}

int main() {
    start();
    return 0;   
}

    // ToDo
  