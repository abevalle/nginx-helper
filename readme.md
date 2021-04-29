### NGINX-UTILS
[![Build](https://github.com/abevalle/nginx-utils/actions/workflows/c-cpp.yml/badge.svg?branch=refactor)](https://github.com/abevalle/nginx-utils/actions/workflows/c-cpp.yml)
---

Portable utility to assist making nginx configs rapidily. This is mainly to use on my nginx docker container to make deployment faster and easier for new websites.


### Installation
---

To install this run the following

```shell
$ curl -o- https://github.com/abevalle/nginx-utils/raw/master/dist/nginx-utils | bash
```
<!-- Then run
```shell
$ chmod +x /etc/nginx-utils
$ sudo ./nginx-utils
``` -->

### Usage
---
`sudo nginx-utils`

```
Welcome to Ngnix Utils
Please select from an option below
1: Create New Nginx Site
2: exit
Please select an option: 
```

#### Create New Nginx Site
Follow the prompts and fill with yout own data. Then run nginx -t to verify config. If the config is ok then reload nginx.
```
Please select an option: 1
Enter the host domain: example.com
Enter the listening port on the host machine: 80
Enter the domain or ip for the proxy: (This is your proxy_pass): localhost
Enter the port for the proxy host (This is the port your proxy_pass will listen on): 1234
Would you like your website to cache? (This can break things at the moment) (y/n): n
Would you like to log access? (y/n): y
Making symbolic link
Done!
Please test the nginx config by running nginx -t.
```

### Build from source
---
Still under developemnt to execure the program simply call 
```shell
./dist/output
```
Then follow the prompts