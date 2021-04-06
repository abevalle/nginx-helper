#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>
using namespace std;
namespace fs = std::experimental::filesystem;

void makeSymLink(string host) {
   fs::create_symlink("/etc/nginx/sites-available/"+host, "/etc/nginx/sites-enabled/"+host);
}

int makeNginx(string host, string host_port, bool access_logs, bool caching, string proxy_host, string proxy_host_port) {
    ofstream outfile ("/etc/nginx/sites-available/"+host);
    outfile << "####################################################" <<endl;
    outfile << "#     THIS FILE WAS GENERATED WITH NGINX-UTILS     #" <<endl;
    outfile << "#     USE CERTBOT TO ADD SSL/TLS CERTIFICATES      #" <<endl;
    outfile << "#   IF YOU ARE FACING AN ISSUE SUBMIT AN ISSUE     #" <<endl;
    outfile << "#                  ON GITHUB                       #" <<endl;
    outfile << "#  https://github.com/abevalle/nginx-utils/issues  #" <<endl;
    outfile << "####################################################" <<endl << endl;
    outfile << "server {" << endl;
    outfile << "        listen " << host_port << ";" << endl;
    outfile << "        server_name "<<host<<";" << endl;
    if (access_logs == false) {
         outfile << "        access_log   off"<<endl;
         }
    // I'm thinking of removing this option because it can break things. I'll have to look in to
    // how to make it work or just do it better...
    if (caching) {
        outfile << "        location ~*  \\.(jpg|jpeg|png|gif|ico|css|js)$ {" << endl;
        outfile << "            expires 365d;" << endl;
        outfile << "      }" << endl;
    }
    outfile << "        location / {" << endl;
    outfile << "           proxy_set_header Host $host;" << endl;
    outfile << "           proxy_pass http://"<<proxy_host<<":"<<proxy_host_port<<"/;"<<endl;
    outfile << "           proxy_set_header X-Real-IP $remote_addr;" << endl;
    outfile << "           proxy_set_header X-Forwarded-Proto https;"<< endl;
    outfile << "      }"<< endl;
    outfile << "}";
    outfile.close();
    cout << "Making symbolic link\n";
    makeSymLink(host);
    cout << "Done!\n";
    cout << "Please test the nginx config by running nginx -t.\n";

    return 0;
}