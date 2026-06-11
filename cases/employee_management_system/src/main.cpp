#include <cstdlib>
#include <iostream>

#include "manager.h"
using namespace std;

int main()
{
    WorkerManager wm;
    int chose = 0;
    while (1) {
        wm.show_menu();
        cout << "请输入您的选择: ";
        cin >> chose;
        switch (chose) {
        case 0:  // 退出系统
            wm.exit_sys();
            break;
        case 1:  // 添加职工
            wm.add_emp();
            break;
        case 2:  // 显示职工
            wm.show_emp();
            break;

        case 3:  // 删除职工
        {
            cout << "请输入要删除的职工编号" << endl;
            int id;
            cin >> id;
            int ret = wm.is_exist(id);
            if (ret != -1) {
                wm.del_emp(ret);
            } else {
                cout << "职工不存在" << endl;
            }
            break;
        }

        case 4:  // 修改职工
            wm.modify();
            break;

        case 5:  // 查找职工
            wm.find_emp();
            break;

        case 6:  // 排序职工
            wm.sort_emp();
            break;

        case 7:  // 清空文件
            wm.clear_data();
            break;
        default:
            system("clear");
            break;
        }
    }

    getchar();
    return 0;
}
