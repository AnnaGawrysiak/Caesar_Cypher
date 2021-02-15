#pragma once
#include "Caesar.h"
#include "First_Cylinder.h"
#include "Cylinder_Rotate_Odd.h"
#include "Cylinder_Rotate_3rd.h"

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

    bool test9();

    bool test10();

    bool test11();

    bool test12();

    bool test13();

    void run(); 

};