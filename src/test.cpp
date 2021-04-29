#include "acutest.h"
#include "validation.cpp"

void test_isValidIp(void) {
    TEST_CHECK(isValidIp("10.28.0.1") == 1);
}; 

void test_isValidDomain(void) {
    TEST_CHECK(isValidDomain("google.com") == 1);
}

void test_isValidPort(void) {
    TEST_CHECK(isValidPort("999") == 1);
}

void test_isValidIpOrDomain_ip(void) {
    TEST_CHECK(isIpOrDomain("10.28.0.1") == 1);
}

void test_isValidIpOrDomain_domain(void) {
    TEST_CHECK(isIpOrDomain("abevalle.com") == 2);
}

void test_isValidIpOrDomain_localhost(void) {
    TEST_CHECK(isIpOrDomain("localhost") == 3);
}

void test_isValidIpOrDomain_fail(void) {
    TEST_CHECK(isIpOrDomain("dafsdfsdf") == 0);
}

TEST_LIST = {
    {"isValidIp", test_isValidIp},
    {"isValidDomain", test_isValidDomain},
    {"isValidPort", test_isValidPort},
    {"isValidIpOrDomain IP", test_isValidIpOrDomain_ip},
    {"isValidIpOrDomain Domain", test_isValidIpOrDomain_domain},
    {"isValidIpOrDomain Localhost", test_isValidIpOrDomain_localhost},
    {"isValidIpOrDomain Fail", test_isValidIpOrDomain_fail},
    {NULL,NULL}
};