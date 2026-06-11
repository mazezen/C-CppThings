#ifndef MANAGER_H
#define MANAGER_H

#include <fstream>
#include <iostream>
using namespace std;
#include "boss.h"
#include "employee.h"
#include "leader.h"
#include "worker.h"

#define FILENAME "data.txt"

class WorkerManager
{
public:
    WorkerManager();

    // 展示菜单
    void show_menu();

    // 退出系统
    void exit_sys();

    // 职工人数
    int m_EmpNum;

    // 文件是否为空
    bool m_FileIsEmpty;

    // 职工数组指针
    Worker** m_EmpArray;

    // 添加职工
    void add_emp();

    // 保存文件
    void save();

    // 统计人数
    int get_EmpNum();

    void init_emp();

    // 显示职工
    void show_emp();

    // 删除职工
    void del_emp(int id);

    // 是否存在
    int is_exist(int id);

    // 修改职工
    void modify();

    // 查找
    void find_emp();

    // 排序
    void sort_emp();

    // 清空
    void clear_data();

    ~WorkerManager();
};

#endif
