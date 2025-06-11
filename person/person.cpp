#include <person.h>
#include <iostream>
#include <string>

Person::Person(const std::string name)
{
    this->name = name;
}

void Person::walking()
{
    std::cout << this->name << " is Walking" << std::endl;
}