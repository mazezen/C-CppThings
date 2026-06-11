#ifndef BOSS_H
#define BOSS_H

#include "worker.h"
class Boss : public Worker
{
public:
    Boss(int id, string name, int dId);

    virtual void get_info();

    virtual string get_depart_name();
};

#endif
