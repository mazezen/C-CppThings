#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

#include "worker.h"

class Employee : public Worker
{
public:
    Employee(int id, string name, int dId);

    virtual void get_info();

    virtual string get_depart_name();
};

#endif
