//
// Created by 18395 on 2022/6/26.
//

#include "..\s.h"
using namespace std;
MYSQL mysql, *sock;                 //mysql���
const char *host = "127.0.0.1";     //������ַ
const char *dbUser = "root";          //���ݿ��û���
const char *dbPwd = "657413";         //���ݿ��½����
const char *db = "jd";             //���ݿ���
unsigned int port = 3306;           //mysql�������˿�
const char *unix_socket = NULL;     //win������Ϊ��
unsigned long client_flag = 0;      //�������һ��Ϊ0
MYSQL_RES *result;                  //����������
MYSQL_ROW row;                      //������ǽ�����е�һ��


void connectDb() {
    mysql_init(&mysql); //����֮ǰ����ʹ�������������ʼ��
    if ((sock = mysql_real_connect(&mysql, host, dbUser, dbPwd, db, port, unix_socket, client_flag)) == NULL) //����MySQL

    {

//        printf("����ʧ�� \n");
//
//        fprintf(stderr, " %s1\n", mysql_error(&mysql));

        exit(1);

    } else {

//        fprintf(stderr, "���ݿ����ӳɹ�\n");

    }
}
//���ҹ���Ա
int finduser(char id[],char password[],char table[]){
    char buffer[100];
    system("cls");
    printf("-----------------------------------\n");
    sprintf(buffer,"select password from %s where account = \'%s\';",table,id);
    if (mysql_real_query(&mysql, buffer, (unsigned long) strlen(buffer))) {
        fprintf(stderr, "0:mysql_real_query failure!\n");
    } else {
        result = mysql_store_result(&mysql);
        if (result == NULL) {
            fprintf(stderr, "0:mysql_store_result failure��\n");
        } else {
            row = mysql_fetch_row(result);
            while (row) {
                if (strcmp(password, row[0]) == 0) {
                    printf("��½�ɹ�\n");
                    return 1;
                } else {
                    printf("��¼ʧ�ܣ������������˺����룡\n");
                    userid=-1;
                    return 0;
                }
                row = mysql_fetch_row(result);
            }
        }
    }
    system("pause");
}
//������Ʒ
void findgoods(){
    system("cls");
    printf("-----------------------------------\n");
    printf("���������ѯ����Ʒ���ƣ�\n");
    getchar();
    char bufffer[100],input[20];
    cin >> input;
    sprintf(bufffer,"select * from goods where name = \'%s\';",input);
    if (mysql_real_query(&mysql, bufffer, (unsigned long) strlen(bufffer))) {
        fprintf(stderr, "mysql_real_query err");
    } else {
        result = mysql_store_result(&mysql);
        if (result == NULL) {
            fprintf(stderr, "mysql_store_result failure��\n");
        } else {
            printf("����    ���    �ۼ�   ����\n-----------------------------------\n");
            while (row = mysql_fetch_row(result)) {
                printf("%s\t %s\t%s\t%s\n",
                       row[0], row[1], row[2], row[3]);
            }
        }
    }
    system("pause");
}
void editgoods() {
    int op;
    char buffer[255],edit[255];
    double t,tf;
    char input[20];
    system("cls");
    printf("������Ҫ�޸ĵ�����:\n");
    cin >> input;
    printf("��������Ҫ�޸ĵ����ݣ�\n1.���\n2.�ۼ�\n3.����\n");
    cin >> op;
    switch (op) {
        case 1:
            printf("��������޸ĵ�������\n");
            cin >> t;
            sprintf(edit,"numbers = %.2f",t,254);
            break;
        case 2:
            printf("��������޸ĵ��ۼۣ�\n");
            cin >> tf;
            sprintf(edit,"price = %.2f",tf,254);
            break;
        case 3:
            printf("��������޸ĵĽ��ۣ�\n");
            cin >> tf;
            sprintf(edit,"purchasedprice = %.2f",tf,254);
            break;
    }
    sprintf(buffer,"update goods set %s where name = \'%s\';",edit,input);
    //cout << buffer;
    mysql_query(&mysql, buffer);
    printf("�޸ĳɹ���\n");
    system("pause");
}
void disallmoney() {
    system("cls");
    char buffer[100]="select * from money order by month;";
    if (mysql_real_query(&mysql, buffer, (unsigned long) strlen(buffer))) {
        fprintf(stderr, "mysql_real_query err");

    } else {
        result = mysql_store_result(&mysql);
        if (result == NULL) {
            fprintf(stderr, "mysql_store_result failure��\n");
        } else {
            printf("\n-----------------------------------\n""ʱ��     ����      ֧��\n"
                   "-----------------------------------\n");
            while (row = mysql_fetch_row(result)) {
                printf("%s-%s-%s %-10s%-10s\n",
                       row[0], row[1], row[2], row[3], row[4]);
            }
        }
    }
    system("pause");
}
void limitedmoney(){
    char buffer[255],input[255];
    int s,b;
    printf("\n-----------------------------------\n"
               "��ѡ��ɸѡ������(������С�����ֵ)\n");
    cin >> s >> b;
    sprintf(buffer,"select * from money where sum >= %d and sum <= %d;",s,b);
    if (mysql_real_query(&mysql, buffer, (unsigned long) strlen(buffer))) {
        fprintf(stderr, "mysql_real_query err");

    } else {
        result = mysql_store_result(&mysql);
        if (result == NULL) {
            fprintf(stderr, "mysql_store_result failure��\n");
        } else {
            printf("ʱ��        ����  ֧��\n"
                   "\n-----------------------------------\n");
            while (row = mysql_fetch_row(result)) {
                printf("%s-%s-%s  %s    %s\n",
                       row[0], row[1], row[2], row[3], row[4]);
            }
        }
    }
    system("pause");
}
void findmonthmoney(){
    char buffer[255],input[255];
    int m;
    printf("\n-----------------------------------\n"
           "��������鿴���·ݣ�\n");
    cin >> m;
    sprintf(buffer,"select * from money where month = %d;",m);
    if (mysql_real_query(&mysql, buffer, (unsigned long) strlen(buffer))) {
        fprintf(stderr, "mysql_real_query err");

    } else {
        result = mysql_store_result(&mysql);
        if (result == NULL) {
            fprintf(stderr, "mysql_store_result failure��\n");
        } else {
            printf("ʱ��        ����  ֧��\n");
            while (row = mysql_fetch_row(result)) {
                printf("%s-%s-%s  %s    %s\n",
                       row[0], row[1], row[2], row[3], row[4]);
            }
        }
    }
    system("pause");
}
void addadmin(){
    char buffer[255],account[20],password[20];
    printf("��������������Ա�˻�����\n");
    cin >> account;
    printf("��������������Ա����:\n");
    cin >> password;
    sprintf(buffer,"insert into clerk (account,password) values (\'%s\',\'%s\');",account,password);
    mysql_query(&mysql, buffer);
    printf("�����ɹ���\n");
    system("pause");
}
void adduser(){
    system("cls");
    char buffer[255],account[20],password[20];
    int vip=0;double balance=0.0;
    printf("�����������û��˻�����\n");
    cin >> account;
    printf("�����������û�����:\n");
    cin >> password;
    printf("�Ƿ�����Ϊvip��(0Ϊ��1Ϊ�ǣ�\n");
    cin >> vip;
    printf("�������ʼ��\n");
    cin >> balance;
    sprintf(buffer,"insert into guest (account,password,vip,balance) values (\'%s\',\'%s\',%d,%.2f);",account,password,vip,balance);
    mysql_query(&mysql, buffer);
    printf("�����ɹ���\n");
    system("pause");
}
void setvip(){
    char buffer[255],name[20];
    system("cls");
    printf("����������Ϊvip���û�����\n");
    cin >> name;
    sprintf(buffer,"update guest set vip = 1 where account = \'%s\';",name);
    mysql_query(&mysql, buffer);
    printf("�ѽ�%s�û�����Ϊvip\n",name);
    system("pause");
}
void deleteuser(){
    char buffer[255],name[20];
    int op;
    printf("\n-----------------------------------\n"
           "������ɾ���û������ͣ�\n"
           "1.����Ա\n"
           "2.�û�\n");
    cin >> op;
    printf("�������ɾ�����˺�����\n",name);
    cin >> name;
    if(op==1)
        sprintf(buffer,"delete from clerk where account = \'%s\';",name);
    else
        sprintf(buffer,"delete from guest where account = \'%s\';",name);
    mysql_query(&mysql, buffer);
    printf("ɾ���ɹ���\n");
    system("pause");
}
void disallgoods(){
    char buffer[100]="select name,price from goods order by price asc ;";
    if (mysql_real_query(&mysql, buffer, (unsigned long) strlen(buffer))) {
        fprintf(stderr, "mysql_real_query err");

    } else {
        result = mysql_store_result(&mysql);
        if (result == NULL) {
            fprintf(stderr, "mysql_store_result failure��\n");
        } else {
            printf("\n-----------------------------------\n""����         ��Ǯ\n"
                   "-----------------------------------\n");
            while (row = mysql_fetch_row(result)) {
                printf("%-10s   %s\n",
                       row[0], row[1]);
            }
        }
    }
    system("pause");
}
double getdata(char ret[],char table[],char s1[],char s2[]){
    char bufs[255];
    double sum;
    sprintf(bufs,"select %s from %s where %s = \'%s\';",ret,table,s1,s2);
    if (mysql_real_query(&mysql, bufs, (unsigned long) strlen(bufs))) {
        fprintf(stderr, "0:mysql_real_query failure!\n");
    } else {
        result = mysql_store_result(&mysql);
        if (result == NULL) {
            fprintf(stderr, "0:mysql_store_result failure��\n");
        } else {
            row = mysql_fetch_row(result);
            while (row) {
                sum= atof(row[0]);
                row = mysql_fetch_row(result);
            }
        }
    }
    return sum;
}
char * getchardata(char ret[], char table[], char s1[], char s2[]){
    char bufs[255];
    char sum[20];
    sprintf(bufs,"select %s from %s where %s = \'%s\';",ret,table,s1,s2);
    if (mysql_real_query(&mysql, bufs, (unsigned long) strlen(bufs))) {
        fprintf(stderr, "0:mysql_real_query failure!\n");
    } else {
        result = mysql_store_result(&mysql);
        if (result == NULL) {
            fprintf(stderr, "0:mysql_store_result failure��\n");
        } else {
            row = mysql_fetch_row(result);
            while (row) {
                strcpy(sum,row[0]);
                row = mysql_fetch_row(result);
            }
        }
    }
    return sum;
}
int getintdata(char ret[],char table[],char s1[],char s2[]){
    char bufs[255];
    int sum;
    sprintf(bufs,"select %s from %s where %s = \'%s\';",ret,table,s1,s2);
    if (mysql_real_query(&mysql, bufs, (unsigned long) strlen(bufs))) {
        fprintf(stderr, "0:mysql_real_query failure!\n");
    } else {
        result = mysql_store_result(&mysql);
        if (result == NULL) {
            fprintf(stderr, "0:mysql_store_result failure��\n");
        } else {
            row = mysql_fetch_row(result);
            while (row) {
                sum= atof(row[0]);
                row = mysql_fetch_row(result);
            }
        }
    }
    return sum;
}
void updoubledate(char table[],char select [],double t,char s1[],char s2[]){
    char buffer[255];
    sprintf(buffer,"update %s set %s = %.2f where %s = \'%s\';",table,select,t,s1,s2);
    mysql_query(&mysql, buffer);
}
void upintdate(char table[],char select [],int t,char s1[],char s2[]){
    char buffer[255];
    sprintf(buffer,"update %s set %s = %d where %s = \'%s\';",table,select,t,s1,s2);
    mysql_query(&mysql, buffer);
}
void adminbuy() {
    char buffer[255], input[20], buyer[20];
    double sum = 0, balance = 0.0, sumout = 0.0, t1, t2;
    int numbers;
    buy:
    system("cls");
    printf("�����뵱ǰ�����ˣ�(����next�л���һ��,exit�˳�)\n");
    cin >> buyer;
    if(strcmp(buyer, "next") == 0){
        nextday();
        printf("�����ѽ�����һ��!��ǰ����Ϊ%04d��%02d��%02d�ա�\n",y,m,d);
        system("pause");
        goto buy;
    }else if(strcmp(buyer,"exit")==0){
        printf("���˳�����ϵͳ��\n");
    }else{
    disallgoods();
    do {
        printf("-----------------------------------\n"
               "ʱ�䣺%4d��%02d��%02d��\n"
               "��������������Ʒ���ƺ�������������ok��ɽ��㣬exit�˳���\n", y, m, d);
        cin >> input;
        if (strcmp(input, "ok") == 0) {
            printf("���ڽ���------\n"
                   "�ܹ����ѣ�%.2fԪ����ѡ��֧����ʽ��\n"
                   "1.��Ա������\n"
                   "2.�ֽ�����\n", sum);
            int op;
            cin >> op;
            switch (op) {
                case 1:
                    balance = getdata("balance", "guest", "account", buyer);
                    if (balance < sum) {
                        printf("֧��ʧ�ܣ���ѡ���ֽ�֧��\n");
                        goto cash;
                    } else {
                        printf("֧���ɹ����ѽ�%.2fԪ\n", sum);
                        balance -= sum;
                        //printf("balance=%.2f\n",balance);
                        updoubledate("guest", "balance", balance, "account", buyer);
                        char buf[255];
                        sprintf(buf, "insert into money (year, month, day, sum, sumout) values (%d,%d,%d,%.2f,%.2f);",
                                y, m, d, sum, sumout);
                        mysql_query(&mysql, buf);
                        system("pause");
                        goto buy;
                    }
                case 2:
                cash:
                    printf("�ɹ�֧����\n");
                    system("pause");
                    goto buy;
            }
        }else if (strcmp(input, "exit") == 0) {
            printf("���˳�����ϵͳ��\n");
            break;
        } else {
            cin >> numbers;
            t1 = getdata("price", "goods", "name", input) * numbers;
            t2 = getdata("purchasedprice", "goods", "name", input) * numbers;
            sum += t1;
            sumout += t2;
            printf("�������Ʒ��%s������Ϊ��%.2f���ܼ�Ϊ��%.2f\n", input, t1 / numbers, sum);
        }
    } while (1);
}
}
void disguest(){
    char buffer[255];
    printf("\n-----------------------------------\n");
    sprintf(buffer,"select password from guest where account = \'%s\';",idbuffer);
    if (mysql_real_query(&mysql, buffer, (unsigned long) strlen(buffer))) {
        fprintf(stderr, "mysql_real_query err");
    } else {
        result = mysql_store_result(&mysql);
        if (result == NULL) {
            fprintf(stderr, "mysql_store_result failure��\n");
        } else {
            while (row = mysql_fetch_row(result)) {
                printf("��������ǣ�%s\n",
                       row[0]);
            }
        }
    }
    int isvip= getintdata("vip","guest","account",idbuffer);
    double balance= getdata("balance","guest","account",idbuffer);
    if(isvip==0)
        printf("�㻹δ��Ϊvip��\n");
    else
        printf("���Ѿ���vip��\n");
    printf("Ǯ��ʣ����%.2f\n",balance);
    system("pause");
}
void guestbuyer(){
    char buffer[255],input[20];
    double sum=0,balance=0.0,sumout=0.0,t1,t2;
    int numbers;
    buy:
    system("cls");
    disallgoods();
    do {
        printf("-----------------------------------\n"
               "ʱ�䣺%4d��%02d��%02d��\n"
               "��������������Ʒ���ƺ�������������ok��ɽ��㣬next��һ��,exit�˳���\n",y,m,d);
        cin >> input ;
        if(strcmp(input,"ok")==0){
            printf("���ڽ���------\n"
                   "�ܹ����ѣ�%.2fԪ����ѡ��֧����ʽ��\n"
                   "1.��Ա������\n"
                   "2.�ֽ�����\n",sum);
            int op;
            cin >> op;
            switch (op) {
                case 1:
                    balance= getdata("balance","guest","account",idbuffer);
                    if(balance<sum){
                        printf("֧��ʧ�ܣ���ѡ���ֽ�֧��\n");
                        goto cash;
                    }else{
                        printf("֧���ɹ����ѽ�%.2fԪ\n",sum);
                        balance-=sum;
                        //printf("balance=%.2f\n",balance);
                        updoubledate("guest","balance",balance,"account",idbuffer);
                        char buf[255];
                        sprintf(buf,"insert into money (year, month, day, sum, sumout) values (%d,%d,%d,%.2f,%.2f);",y,m,d,sum,sumout);
                        mysql_query(&mysql, buf);
                        system("pause");
                        goto buy;
                    }
                case 2:
                cash:
                    printf("�ɹ�֧����\n");
                    system("pause");
                    goto buy;
            }
        }else if(strcmp(input,"next")==0){
            nextday();
        }else if(strcmp(input,"exit")==0){
            printf("���˳�����ϵͳ��\n");
            break;
        }
        else{
            cin >> numbers;
            t1= getdata("price","goods","name",input)*numbers;
            t2= getdata("purchasedprice","goods","name",input)*numbers;
            sum+=t1;sumout+=t2;
            printf("�������Ʒ��%s������Ϊ��%.2f���ܼ�Ϊ��%.2f\n",input,t1/numbers,sum);
        }
    } while (1);
}
void outputfile(){
    FILE *fp= fopen("C:\\1\\money.csv","w+");
    char buffer[100]="select * from money order by month;";
    if (mysql_real_query(&mysql, buffer, (unsigned long) strlen(buffer))) {
        fprintf(stderr, "mysql_real_query err");

    } else {
        result = mysql_store_result(&mysql);
        if (result == NULL) {
            fprintf(stderr, "mysql_store_result failure��\n");
        } else {
            fprintf(fp,"year,month,day,sum,sumout\n");
            while (row = mysql_fetch_row(result)) {
                fprintf(fp,"%s,%s,%s,%s,%s\n",
                       row[0], row[1], row[2], row[3], row[4]);
            }
        }
    }
    fclose(fp);
    printf("�ļ��ѳɹ�������\n");
    system("pause");
}
void outputgoodsfile(){
    FILE *fp= fopen("C:\\1\\goods.csv","w+");
    char buffer[100]="select * from goods order by price;";
    if (mysql_real_query(&mysql, buffer, (unsigned long) strlen(buffer))) {
        fprintf(stderr, "mysql_real_query err");

    } else {
        result = mysql_store_result(&mysql);
        if (result == NULL) {
            fprintf(stderr, "mysql_store_result failure��\n");
        } else {
            fprintf(fp,"name,numbers,price,purchasedprice\n");
            while (row = mysql_fetch_row(result)) {
                fprintf(fp,"%s,%s,%s,%s\n",
                        row[0], row[1], row[2], row[3]);
            }
        }
    }
    fclose(fp);
    printf("�ļ��ѳɹ�������\n");
    system("pause");
}
void addbalance(){
    system("cls");
    printf("���������ֵ����\n");
    double sum=0.0;
    cin >> sum;
    sum+=getdata("balance","guest","account",idbuffer);
    updoubledate("guest","balance",sum,"account",idbuffer);
    printf("��ֵ�ɹ�����ǰǮ�����ʣ�ࣺ%.2f\n", getdata("balance","guest","account",idbuffer));
    system("pause");
}