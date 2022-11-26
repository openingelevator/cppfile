#pragma once
#include <string>
#include "Date.h" // include Date class definition
using namespace std;

class Employee
{
public:
    Employee(const string&, const string&,
        const Date&, const Date&);
    void print() const;
    ~Employee(); // provided to confirm destruction order
private:
    string firstName; // composition: member object
    string lastName; // composition: member object
    const Date birthDate; // composition: member object
    const Date hireDate; // composition: member object
}; // end class Employee
