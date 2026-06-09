#include "lib.h"

int main()
{
    printMenu();
    struct ContactList *cl_arr = initialize();

    int choose = 0;
    while (true)
    {
        cout << "请输入您的操作" << endl;
        cin >> choose;

        switch (choose)
        {
            case 1:
            {
                // 1: 添加联系人. 信息包括 (姓名, 性别, 年龄, 联系电话, 家庭住址) 最多1000条记录
                string name;
                string sex;
                int age;
                string phone;
                string address;
                cout << "请输入姓名: ";
                cin >> name;
                cout << endl;
                cout << "请输入性别: ";
                cin >> sex;
                cout << endl;
                cout << "请输入年龄: ";
                cin >> age;
                cout << endl;
                cout << "请输入电话: ";
                cin >> phone;
                cout << endl;
                cout << "请输入地址: ";
                cin >> address;
                cout << endl;

                struct ContactPeople *cp = new ContactPeople;
                cp->name = name;
                cp->sex = sex;
                cp->age = age;
                cp->phone = phone;
                cp->address = address;

                int res = add(cl_arr, cp);
                if (-1 == res)
                    cout << "通讯录已满" << endl;
                else if (res == 1)
                {
                    cout << "添加联系人成功" << endl;
                } 
                else 
                {
                    cout << "添加联系人失败" << endl;
                }
                
                break;
            }
                
            case 2:
            {
                // 2: 显示联系人: 显示通讯录中所有联系人信息
                showAll(cl_arr);
                break;
            }
            
            case 3:
            {
                // 3: 删除联系人: 按照姓名进行删除指定联系人
                string name;
                cout << "请输入要删除的联系人姓名: ";
                cin >> name;
                cout << endl;

                int res = remove(cl_arr, name);
                if (-1 == res)
                    cout << "通讯录为空" << endl;
                else if (res == 0)
                {
                    cout << "删除联系人成功" << endl;
                } 
                else 
                {
                    cout << "删除联系人失败" << endl;
                }
                break;
            }
            
            case 4:
            {
                 // 4: 查找联系人: 按照姓名查看指定联系人信息
                string name;
                cout << "请输入要查找的联系人姓名: ";
                cin >> name;
                cout << endl;
                showByName(cl_arr, name);
                break;

            }
            case 5:
            {
                // 5: 修改联系人: 按照姓名重新修改指定联系人
                string name;
                string sex;
                int age;
                string phone;
                string address;
                cout << "请输入姓名: ";
                cin >> name;
                cout << endl;
                cout << "请输入性别: ";
                cin >> sex;
                cout << endl;
                cout << "请输入年龄: ";
                cin >> age;
                cout << endl;
                cout << "请输入电话: ";
                cin >> phone;
                cout << endl;
                cout << "请输入地址: ";
                cin >> address;
                cout << endl;
                struct ContactPeople *cp = new ContactPeople;
                cp->name = name;
                cp->sex = sex;
                cp->age = age;
                cp->phone = phone;
                cp->address = address;
                modidyByName(cl_arr, name, cp);
                break;
            }
            case 6:
            {
                // 6: 清空联系人: 清空通讯录中所有信息
                clear(cl_arr);
                break;
            }
            case 7:
            {
                // 7: 退出通讯录: 退出当前使用的通讯录
                cout << "退出成功!" << endl;
                break;
            }
            default:
            {
                cout << "未知" << endl;
                break;
            }
        }
    }
    

    return 0;
}
