using namespace std;
#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include "validation.cpp"
#include "makeNginx.cpp"


    string host;
    string host_port;
    string proxy_host;
    string proxy_host_port;
    bool caching;
    bool access_logs;

int getOpts() {
    //ToDO
    // Ask about caching
    string caching_opt;
    string access_logs_opt;
    
    cout<<"Would you like your website to cache? (y/n): ";
    cin>>caching_opt;
    if(caching_opt == "y" || caching_opt == "Y") {
        caching = true;
    } else if (caching_opt == "n" || caching_opt == "N") {
        caching = false;
    } else {
        cout<<"Something is wrong please try again!";
        return 0;
    }
    // Ask if the user woudl like access logs
    cout<<"Would you like to log access? (y/n): ";
    cin>>access_logs_opt;
    if(access_logs_opt == "y" || access_logs_opt == "Y") {
        access_logs = true;
    } else if (access_logs_opt == "n" || access_logs_opt == "N") {
        access_logs = false;
    } else {
        cout<<"Something is wrong please try again!";
        return 0;
    }

    makeNginx(host, access_logs, caching, proxy_host, proxy_host_port);

    return 0;
}

int getProxyInfo() {
    // Get info for the proxy machine
    cout << "Enter the domain or ip for the proxy: (This is your proxy_pass): ";
    cin >> proxy_host;
    cout << "Enter the port for the proxy host (This is the port your proxy_pass will listen on): ";
    cin >> proxy_host_port;
    
    if (isIpOrDomain(proxy_host) != 0) {
        getOpts();
    } else if (isIpOrDomain(proxy_host) == 0) {
        cout<<"A fatal error has occured please check your entry and try again";
    }

    return 0;   
}

int getHostInfo() {
    // Get info for the host machine
    cout << "Enter the host domain: ";
    cin >> host;
    cout << "Enter the listening port on the host machine: ";
    cin >> host_port;


    if (isValidDomain(host) == false && isValidPort(host_port) == false) {
        cout<<"host domain and port are invalid!";
    } else if (isValidDomain(host) == false) {
        cout<<"host domain is invalid!";
    } else if (isValidPort(host_port) == false) {
        cout<<"host port is invalid!";
    } else if (isValidDomain(host) && isValidPort(host_port)) {
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
  