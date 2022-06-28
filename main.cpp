#include "s.h"

using namespace std;

int main() {
    system("color F0");
    connectDb();
    Sleep(1000);
    int op;
    login:
    system("cls");
    printf("-----------------------------------\n"
           "欢迎使用京东超市系统，请选择你的用户类型登录：\n1.最高管理员（店长）\n2.管理员（店员）\n3.用户（买家）\n"
           "-----------------------------------\n"
           "请输入你的选择：\n");
    cin >> op;
    switch (op) {
        case 1:
            loginin(0);
            break;
        case 2:
            loginin(1);
            break;
        case 3:
            loginin(2);
            break;
    }
    Sleep(1000);
    if(userid==0 or userid==1){
        while  (1) {
            system("cls");
            printf("\n-----------------------------------\n"
                   "欢迎你管理员：%s  今天是%4d年%02d月%02d日\n"
                   "-----------------------------------\n"
                   "1.商品查询\n"
                   "2.商品修改\n"
                   "3.账目管理\n"
                   "4.收银系统\n"
                   "5.账户管理\n"
                   "6.系统设置\n"
                   "7.退出系统\n"
                   "8.切换账户\n"
                   "-----------------------------------\n"
                   "请输入你的选择：\n",idbuffer,y,m,d);
            cin >> op;
            switch (op) {
                case 1:
                    findgoods();
                    break;
                case 2:
                    editgoods();
                    break;
                case 3:
                    system("cls");
                    printf("\n-----------------------------------\n"
                           "请输入以下选择查询：\n"
                           "1.显示所有账单\n"
                           "2.筛选指定销量\n"
                           "3.查看指定月份\n"
                           "4.导出账单文件\n"
                           "5.返回上层菜单\n");
                    cin >> op;
                    switch (op) {
                        case 1:
                            disallmoney();
                            break;
                        case 2:
                            limitedmoney();
                            break;
                        case 3:
                            findmonthmoney();
                            break;
                        case 4:
                            outputfile();
                            break;
                    }
                    break;
                case 4:
                    adminbuy();
                    break;
                case 5:
                    system("cls");
                    printf("\n-----------------------------------\n"
                           "请输入以下选择操作：\n"
                           "1.添加管理员\n"
                           "2.添加新用户\n"
                           "3.设置用户vip\n"
                           "4.删除账户\n"
                           "5.返回上层\n"
                           "");
                    cin >> op;
                    switch (op) {
                        case 1:
                            if(userid==0)
                                addadmin();
                            else
                                printf("操作失败，不具有权限。\n");
                            break;
                        case 2:
                            adduser();
                            break;
                        case 3:
                            setvip();
                            break;
                        case 4:
                            deleteuser();
                            break;
                    }
                    break;
                case 6:
                    system("cls");
                    printf("\n-----------------------------------\n"
                           "请输入以下选择操作：\n"
                           "1.修改日期\n"
                           "2.导出商品\n"
                           "2.返回上层\n");
                    cin >> op;
                    switch (op) {
                        case 1:
                            editday();
                            break;
                        case 2:
                            outputgoodsfile();
                            break;
                    }
                    break;
                case 7:
                    printf("已退出系统！\n");
                    return 0;
                case 8:
                    printf("正在退出当前账号：%s\n",idbuffer);
                    userid=-1;
                    goto login;
            }
            if(op==7)
                break;
        }
    }else if(userid==2){
        vip= getintdata("vip","guest","account",idbuffer);
        if(vip==0){
            printf("尊敬的用户：%s，您是否需要办理vip?\n",idbuffer);
            char ch;
            cin >> ch;
            if(ch=='y' or ch=='Y'){
                upintdate("guest","vip",1,"account",idbuffer);
                printf("恭喜你办理成功！\n");
                system("pause");
            }
        }
        while(1) {
            system("cls");
            printf("\n-----------------------------------\n"
                   "欢迎你用户：%s  今天是%4d年%02d月%02d日\n"
                   "-----------------------------------\n"
                   "1.查询信息\n"
                   "2.查询商品\n"
                   "3.开始购物\n"
                   "4.充值余额\n"
                   "5.退出系统\n"
                   "6.切换账户\n"
                   "-----------------------------------\n"
                   "请输入你的选择：\n", idbuffer, y, m, d);
            cin >> op;
            switch (op) {
                case 1:
                    disguest();
                    break;
                case 2:
                    findgoods();
                    break;
                case 3:
                    guestbuyer();
                    break;
                case 4:
                    addbalance();
                    break;
                case 5:
                    return 0;
                case 6:
                    printf("正在退出当前账号：%s\n",idbuffer);
                    userid=-1;
                    goto login;
            }
        }
    }
    return 0;
}
