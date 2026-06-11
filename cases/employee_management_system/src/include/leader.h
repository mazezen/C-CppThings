#ifndef LEADER_H
#define LEADER_H

#include "worker.h"

class Leader : public Worker
{
public:
    Leader(int id, string name, int dId);

    virtual void get_info();

    virtual string get_depart_name();
};

#endif
