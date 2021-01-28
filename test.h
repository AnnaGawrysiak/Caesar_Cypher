#pragma once
#include "Caesar.h"

class test
{
private:
    test();
    static test* wsk;

public:
    void operator = (const test&) = delete;
    test(const test&) = delete;

    static test* get_instance();

    bool test1();

    bool test2();

    bool test3();

    bool test4();

    bool test5();

    bool test6();

    bool test7();

    bool test8();

    void run(); // obiekt testowy mamy tylko jeden i mozemy go sobie wywolywac ile chcemy

};