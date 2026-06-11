#include "manager.h"

#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <fstream>

#include "boss.h"
#include "employee.h"
#include "leader.h"
#include "worker.h"

WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    if (!ifs.is_open()) {
        cout << "数据文件不存在" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "数据文件为空" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    int empNums = this->get_EmpNum();
    cout << "目前拥有 " << empNums << " 个职工" << endl;
    this->m_EmpNum = empNums;

    this->m_EmpArray = new Worker*[this->m_EmpNum];
    this->init_emp();
}

void WorkerManager::show_menu()
{
    cout << "********************************************" << endl;
    cout << "************* 欢迎使用职工管理系统 ************" << endl;
    cout << "************** 0: 退出管理系统 ***************" << endl;
    cout << "************** 1: 增加职工信息 ***************" << endl;
    cout << "************** 2: 显示职工信息 ***************" << endl;
    cout << "************** 3: 删除离职员工 ***************" << endl;
    cout << "************** 4: 修改职工信息 ***************" << endl;
    cout << "************** 5: 查找职工信息 ***************" << endl;
    cout << "************** 6: 按照编号排序 ***************" << endl;
    cout << "************** 7: 清空所有文档 ***************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void WorkerManager::exit_sys()
{
    cout << "欢迎下次使用" << endl;
    getchar();
    exit(0);
}

void WorkerManager::add_emp()
{
    cout << "请输入添加职工的数量" << endl;
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0) {
        // 计算新空间大小
        int new_size = this->m_EmpNum + addNum;
        // 开辟内存空间
        Worker** newSpace = new Worker*[new_size];
        // 将原空间下数据拷贝到新空间中
        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        // 批量添加
        for (int i = 0; i < addNum; i++) {
            int id;
            string name;
            int dSelect;
            cout << "请输入第 " << i + 1 << " 个员工编号: ";
            cin >> id;
            cout << "请输入第 " << i + 1 << " 个员工姓名: ";
            cin >> name;
            cout << "请选择该职工岗位: " << endl;
            cout << "1, 普通职工" << endl;
            cout << "2, 经理" << endl;
            cout << "3, 老板" << endl;
            cin >> dSelect;

            Worker* worker = NULL;
            switch (dSelect) {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Leader(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }

            // 保存职工信息
            newSpace[this->m_EmpNum + i] = worker;
        }

        // 释放原有空间
        delete[] this->m_EmpArray;
        // 更改指向新空间
        this->m_EmpArray = newSpace;
        // 更新职工人数
        this->m_EmpNum = new_size;
        // 成功添加后, 保存到文件中
        this->save();
        this->m_FileIsEmpty = false;
        // 提示
        cout << "成功添加了 " << addNum << " 名新职工" << endl;
    } else {
        cout << "输入数据有误" << endl;
    }
    getchar();
    system("clear");
};

void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->m_EmpNum; i++) {
        ofs << this->m_EmpArray[i]->m_Id << " " << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }
    ofs.close();
}

int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId) {
        num++;
    }

    ifs.close();

    return num;
}

void WorkerManager::init_emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId) {
        Worker* worker = NULL;
        if (dId == 1)  // 普通员工
        {
            worker = new Employee(id, name, dId);
        } else if (dId == 2) {  // 经理
            worker = new Leader(id, name, dId);
        } else {  // CEO
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }
    ifs.close();
}

void WorkerManager::show_emp()
{
    for (int i = 0; i < this->m_EmpNum; i++) {
        // cout << "总共有 " << this->m_EmpNum << " 个职工" << endl;
        this->m_EmpArray[i]->get_info();
    }
}

int WorkerManager::is_exist(int id)
{
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_Id == id) {
            index = i;
            break;
        }
    }

    return index;
}

void WorkerManager::del_emp(int id)
{
    for (int i = id; i < this->m_EmpNum; i++) {
        // 数据迁移
        this->m_EmpArray[i] = this->m_EmpArray[i + 1];
    }
    this->m_EmpNum--;
    this->save();
    cout << "删除成功" << endl;
}

void WorkerManager::sort_emp()
{
    cout << "请选择排序方式: " << endl;
    cout << "1. 按职工编号升序" << endl;
    cout << "2. 按职工编号降序" << endl;
    int select = 0;
    cin >> select;

    for (int i = 0; i < this->m_EmpNum; i++) {
        int minOrMax = i;
        for (int j = i + 1; j < this->m_EmpNum; j++) {
            if (select == 1) {
                if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id) {
                    minOrMax = j;
                }
            } else {
                if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id) {
                    minOrMax = j;
                }
            }
        }
        if (i != minOrMax) {
            Worker* temp = this->m_EmpArray[i];
            this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
            this->m_EmpArray[minOrMax] = temp;
        }
    }
    cout << "排序成功: " << endl;
    this->save();
    this->show_emp();
}

void WorkerManager::modify()
{
    cout << "请输入要修改的职工编号: " << endl;
    int id;
    cin >> id;

    int ret = this->is_exist(id);
    if (ret != -1) {
        delete this->m_EmpArray[ret];

        int newId = 0;
        string newName = "";
        int newDSelect = 0;
        cout << "查到: " << id << "号职工,请输入新职工号: ";
        cin >> newId;
        cout << "请输入姓名: " << endl;
        cin >> newName;
        cout << "请选择该职工岗位: " << endl;
        cout << "1, 普通职工" << endl;
        cout << "2, 经理" << endl;
        cout << "3, 老板" << endl;
        cin >> newDSelect;

        Worker* worker = NULL;
        switch (newDSelect) {
        case 1:
            worker = new Employee(newId, newName, 1);
            break;
        case 2:
            worker = new Leader(newId, newName, 2);
            break;
        case 3:
            worker = new Boss(newId, newName, 3);
            break;
        default:
            break;
        }

        this->m_EmpArray[ret] = worker;

        cout << "修改成功!" << endl;
        this->save();

    } else {
        cout << "职工不存在" << endl;
    }
}

void WorkerManager::find_emp()
{
    cout << "请输入要查找的职工编号: " << endl;
    int id;
    cin >> id;

    int ret = this->is_exist(id);
    if (ret != -1) {
        this->m_EmpArray[ret]->get_info();
    } else {
        cout << "职工不存在" << endl;
    }
}

void WorkerManager::clear_data()
{
    cout << "确认清空吗? " << endl;
    cout << "1. 确认" << endl;
    cout << "2. 返回" << endl;

    int select = 0;
    cin >> select;
    if (select == 1) {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                if (this->m_EmpArray[i] != NULL) {
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum = 0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;
        }
        cout << "清空成功!" << endl;
    }
}

WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != NULL) {
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}
