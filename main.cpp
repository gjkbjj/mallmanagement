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
           "��ӭʹ�þ�������ϵͳ����ѡ������û����͵�¼��\n1.��߹���Ա���곤��\n2.����Ա����Ա��\n3.�û�����ң�\n"
           "-----------------------------------\n"
           "���������ѡ��\n");
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
                   "��ӭ�����Ա��%s  ������%4d��%02d��%02d��\n"
                   "-----------------------------------\n"
                   "1.��Ʒ��ѯ\n"
                   "2.��Ʒ�޸�\n"
                   "3.��Ŀ����\n"
                   "4.����ϵͳ\n"
                   "5.�˻�����\n"
                   "6.ϵͳ����\n"
                   "7.�˳�ϵͳ\n"
                   "8.�л��˻�\n"
                   "-----------------------------------\n"
                   "���������ѡ��\n",idbuffer,y,m,d);
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
                           "����������ѡ���ѯ��\n"
                           "1.��ʾ�����˵�\n"
                           "2.ɸѡָ������\n"
                           "3.�鿴ָ���·�\n"
                           "4.�����˵��ļ�\n"
                           "5.�����ϲ�˵�\n");
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
                           "����������ѡ�������\n"
                           "1.��ӹ���Ա\n"
                           "2.������û�\n"
                           "3.�����û�vip\n"
                           "4.ɾ���˻�\n"
                           "5.�����ϲ�\n"
                           "");
                    cin >> op;
                    switch (op) {
                        case 1:
                            if(userid==0)
                                addadmin();
                            else
                                printf("����ʧ�ܣ�������Ȩ�ޡ�\n");
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
                           "����������ѡ�������\n"
                           "1.�޸�����\n"
                           "2.������Ʒ\n"
                           "2.�����ϲ�\n");
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
                    printf("���˳�ϵͳ��\n");
                    return 0;
                case 8:
                    printf("�����˳���ǰ�˺ţ�%s\n",idbuffer);
                    userid=-1;
                    goto login;
            }
            if(op==7)
                break;
        }
    }else if(userid==2){
        vip= getintdata("vip","guest","account",idbuffer);
        if(vip==0){
            printf("�𾴵��û���%s�����Ƿ���Ҫ����vip?\n",idbuffer);
            char ch;
            cin >> ch;
            if(ch=='y' or ch=='Y'){
                upintdate("guest","vip",1,"account",idbuffer);
                printf("��ϲ�����ɹ���\n");
                system("pause");
            }
        }
        while(1) {
            system("cls");
            printf("\n-----------------------------------\n"
                   "��ӭ���û���%s  ������%4d��%02d��%02d��\n"
                   "-----------------------------------\n"
                   "1.��ѯ��Ϣ\n"
                   "2.��ѯ��Ʒ\n"
                   "3.��ʼ����\n"
                   "4.��ֵ���\n"
                   "5.�˳�ϵͳ\n"
                   "6.�л��˻�\n"
                   "-----------------------------------\n"
                   "���������ѡ��\n", idbuffer, y, m, d);
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
                    printf("�����˳���ǰ�˺ţ�%s\n",idbuffer);
                    userid=-1;
                    goto login;
            }
        }
    }
    return 0;
}
