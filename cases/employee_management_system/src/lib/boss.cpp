#include "boss.h"

Boss::Boss(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Boss::get_info()
{
    cout << "职工编号: " << this->m_Id << " \t职工姓名: " << this->m_Name
         << " \t岗位: " << this->get_depart_name() << " \t岗位职责: 管理公司所有事物" << endl;
}

string Boss::get_depart_name() { return string("老板"); }
