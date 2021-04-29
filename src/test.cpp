#include "acutest.h"
#include "validation.cpp"

void test_isValidIp(void) {
    string ip;

    TEST_CHECK(isValidIp("10.28.0.1") == 1);
}; 

TEST_LIST = {
    {"isValidIp", test_isValidIp},
    {NULL,NULL}
};