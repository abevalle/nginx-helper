#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;
// namespace fs = filesystem;

// int makeSymLink(string host) {
//    filesystem::create_symlink("/etc/nginx/sites-available/"+host, "/etc/nginx/sites-enabled/"+host);
//     return 0;
// }

int makeNginx(string host, bool access_logs, bool caching, string proxy_host, string proxy_host_port) {
    ofstream outfile ("/etc/nginx/sites-available/"+host);
    outfile << "####################################################" <<endl;
    outfile << "#     THIS FILE WAS GENERATED WITH NGINX-UTILS     #" <<endl;
    outfile << "#     USE CERTBOT TO ADD SSL/TLS CERTIFICATES      #" <<endl;
    outfile << "#  IF YOU ARE FACING AN ISSUE SUBMIT AN ISSUE      #" <<endl;
    outfile << "#  ON GITHUB                                       #" <<endl;
    outfile << "#  https://github.com/abevalle/nginx-utils/issues  #" <<endl;
    outfile << "####################################################" <<endl << endl;
    outfile << "server {" << endl;
    outfile << "        listen 80;" << endl;
    outfile << "        server_name "<<host<<";" << endl;
    if (access_logs == false) {
         outfile << "        access_log   off"<<endl;
         }

    if (caching) {
        outfile << "        location ~*  \\.(jpg|jpeg|png|gif|ico|css|js)$ {" << endl;
        outfile << "            expires 365d;" << endl;
        outfile << "      }" << endl;
    }
    outfile << "        location / {" << endl;
    outfile << "           proxy_set_header Host $host;" << endl;
    outfile << "           proxy_pass http://"<<proxy_host<<":"<<proxy_host_port<<"/;"<<endl;
    // Disabled because it breakes things in ngnix
    // outfile << "           proxy_redirect off;" << endl;
    outfile << "           proxy_set_header X-Real-IP $remote_addr;" << endl;
    outfile << "           proxy_set_header X-Forwarded-Proto https;"<< endl;
    outfile << "      }"<< endl;
    outfile << "}";
    outfile.close();
    // cout << "Making symbolic link";
    // makeSymLink(host);
    cout << "Done!";
    cout << "Make symlink function is still development. Please create symlink then reload nginx.";

    return 0;
}