#include "employee.h"

Employee::Employee(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Employee::get_info()
{
    cout << "职工编号: " << this->m_Id << " \t职工姓名: " << this->m_Name
         << " \t岗位: " << this->get_depart_name() << " \t岗位职责: 完成经理交给的任务" << endl;
}

string Employee::get_depart_name() { return string("员工"); }
