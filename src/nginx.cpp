#include <iostream>
#include <string>
using namespace std;

class Nginx {
    public:
    struct general {
        string hostname;
        string domain;
        int port;
    };
    struct web {
        string directory;
        string options[];
    };
    struct reverse_proxy {
        string domain;
        int port;
        string options[];
    };

    int General(string g_hostname, string g_domain) {
        general.hostname = g_hostname;
        general.domain = g_domain;
    };

    int Web(string w_dir, string w_opts[]) {
        web.enabled = web;
        web.directory = w_dir;
        web.options = w_opts;
    };

    int ReverseProxy(string rp_domain, in rp_port, string rp_opts[]) {
        reverse_proxy.domain = rp_domain;
        reverse_proxy.port = rp_port;
        reverse_proxy.options = rp_opts;
    };
}