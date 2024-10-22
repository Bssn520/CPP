#include <iostream>
#include <iso646.h>

class X;
class Y;

class X
{
    Y* ptr_Y = nullptr;
};

class Y
{
    X obj_X;
};