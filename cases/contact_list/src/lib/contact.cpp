#include "lib.h"

ContactList *initialize() 
{
    struct ContactList *cl_arr = new ContactList;
    cl_arr->num = 0;
    return cl_arr;
}

int size(ContactList *cl_arr)
{
    return cl_arr->num;
}

int add(ContactList *cl_arr, ContactPeople *cp)
{
    if (cl_arr->num >= MAX_RECORDS)
    {
        return -1; 
    }

    cl_arr->cp_arr[cl_arr->num] = cp;
    cl_arr->num++;
    return 1;
}

void showAll(ContactList *cl_arr)
{
    if (cl_arr->num <= 0)
        cout << "暂无联系人" << endl;
    else 
    {
        for (int i = 0; i < cl_arr->num; i++)
        {
            cout << "姓名: " << cl_arr->cp_arr[i]->name <<
                " 性别: " << cl_arr->cp_arr[i]->sex <<
                " 年龄: " << cl_arr->cp_arr[i]->age << 
                " 手机号: " << cl_arr->cp_arr[i]->phone <<
                " 地址: " << cl_arr->cp_arr[i]->address <<
                endl;
        }
    }
}

void showByName(ContactList *cl_arr, string name)
{
    bool flag;
    int index;

    if (cl_arr->num <= 0)
        cout << "暂无联系人" << endl;
    else
    {
        for (int i = 0; i < cl_arr->num; i++)
        {
            if (cl_arr->cp_arr[i]->name == name)
            {
                flag = true;
                index = i;
            }
        }
    }

    if (false == flag) 
    {
        cout << "联系人不存在" << endl;
    }
    else
    {
        cout << "姓名: " << cl_arr->cp_arr[index]->name <<
            " 性别: " << cl_arr->cp_arr[index]->sex <<
            " 年龄: " << cl_arr->cp_arr[index]->age << 
            " 手机号: " << cl_arr->cp_arr[index]->phone <<
            " 地址: " << cl_arr->cp_arr[index]->address << endl;
    }
}

void modidyByName(ContactList *cl_arr, string name, ContactPeople *cp)
{
    if (cl_arr->num <= 0)
    {
        cout << "通讯录为空" << endl;
        return;
    }
    else 
    {
        for (int i = 0; i < cl_arr->num; i++)
        {
            if (cl_arr->cp_arr[i]->name == name)
            {
                cl_arr->cp_arr[i] = cp;
                cout << "修改联系人成功" << endl;
                return;
            }
        }
    }
    cout << "联系人不存在" << endl;
    return;
}

int remove(ContactList *cl_arr, string name)
{
    if (cl_arr->num <= 0)
    {
        return -1; 
    }

    for (int i = 0; i < cl_arr->num; i++)
    {
        if (cl_arr->cp_arr[i]->name == name) 
        {
            cl_arr->cp_arr[i] = NULL;
            cl_arr->num--;
            return 0;
        }
    }

    return 1;
}

void clear(ContactList *cl_arr)
{
    if (cl_arr->num > 0)
    {
        cl_arr->num = 0;
        free(cl_arr->cp_arr);
    }
}
