#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <string>

#define MAX_RECORDS 1000

using namespace std;

struct ContactPeople {
    string name;
    string sex;
    int age;
    string phone;
    string address;
};

struct ContactList {
    struct ContactPeople *cp_arr[MAX_RECORDS];
    int num;
};

void printMenu();

ContactList *initialize();

// 获取通讯录数量
int size(ContactList *cl_arr);

// 添加联系人
int add(ContactList *cl_arr, ContactPeople *cp);

// 查看所有联系人
void showAll(ContactList *cl_arr);

// 查看指定联系人
void showByName(ContactList *cl_arr, string name);

// 修改联系人
void modidyByName(ContactList *cl_arr, string name, ContactPeople *cp);

// 删除联系人
int remove(ContactList *cl_arr, string name);

// 清空联系人
void clear(ContactList *cl_arr);

#endif
