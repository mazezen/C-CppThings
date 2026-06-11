#include "leader.h"

Leader::Leader(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Leader::get_info()
{
    cout << "职工编号: " << this->m_Id << " \t职工姓名: " << this->m_Name
         << " \t岗位: " << this->get_depart_name() << " \t岗位职责: 完成老板下发的任务,并下发给员工"
         << endl;
}

string Leader::get_depart_name() { return string("经理"); }
