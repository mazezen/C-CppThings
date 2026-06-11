#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:
    virtual void get_info() = 0;

    virtual string get_depart_name() = 0;

    virtual ~Worker() {};

    int m_Id;
    string m_Name;
    int m_DeptId;
};

#endif
