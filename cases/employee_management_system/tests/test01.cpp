#include "boss.h"
#include "employee.h"
#include "leader.h"
#include "worker.h"

void test()
{
    Worker* worker = NULL;

    worker = new Employee(1, "张三", 1);
    worker->get_info();
    worker->get_depart_name();
    delete worker;

    worker = new Leader(2, "李四", 1);
    worker->get_info();
    worker->get_depart_name();
    delete worker;

    worker = new Boss(3, "王五", 1);
    worker->get_info();
    worker->get_depart_name();
    delete worker;
}

int main()
{
    test();

    return 0;
}
