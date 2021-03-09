bool isValidDomain(string domain) {
    const regex pattern("^[a-zA-Z0-9][a-zA-Z0-9-]{1,61}[a-zA-Z0-9].[a-zA-Z]{2,}$");
    if(regex_match(domain, pattern)) {
        return true;
    } else {
        return false;
    }
}

bool isIpValid(string ip) {
    const regex pattern("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    if(regex_match(ip, pattern)) {
        return true;
    } else {
        return false;
    }
}

bool isPortValid(string port) {
    const regex pattern("^([0-9]{1,4}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])$");
    if(regex_match(port, pattern)) {
        return true;
    } else {
        return false;
    }
}