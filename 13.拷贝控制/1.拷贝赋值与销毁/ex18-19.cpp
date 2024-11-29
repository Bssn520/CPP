#include <iostream>
#include <string>

class Employee
{
    friend void print(const Employee &em);

public:
    Employee()
    {
        id = n;
        ++n;
    };
    Employee(const std::string _name)
    {
        name = _name;
        id = n;
        ++n;
    };
    Employee(const Employee &) = delete;
    Employee &operator=(const Employee &) = delete;

private:
    std::string name;
    int id;
    static int n;
};

void print(const Employee &em) { std::cout << em.name << " " << em.id << std::endl; }

int Employee::n = 0;

int main()
{
    Employee a;
    Employee b("bbb");

    print(a);
    print(b);

    return 0;
}
