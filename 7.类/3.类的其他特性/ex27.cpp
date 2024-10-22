#include <iostream>
#include <string.h>
#include "Screen_ex24.h"


int main()
{
    Screen myScreen(5, 5, '#');
    myScreen.move(4, 0).set('X').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";


    return  0;
}