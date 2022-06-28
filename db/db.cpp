//
// Created by 18395 on 2022/6/26.
//

#include "..\s.h"
using namespace std;
MYSQL mysql, *sock;                 //mysql句柄
const char *host = "127.0.0.1";     //本机地址
const char *dbUser = "root";          //数据库用户名
const char *dbPwd = "657413";         //数据库登陆密码
const char *db = "jd";             //数据库名
unsigned int port = 3306;           //mysql服务器端口
const char *unix_socket = NULL;     //win下设置为空
unsigned long client_flag = 0;      //这个参数一般为0
MYSQL_RES *result;                  //保存结果集的
MYSQL_ROW row;                      //代表的是结果集中的一行


void connectDb() {
    mysql_init(&mysql); //连接之前必须使用这个函数来初始化
    if ((sock = mysql_real_connect(&mysql, host, dbUser, dbPwd, db, port, unix_socket, client_flag)) == NULL) //连接MySQL

    {

//        printf("连接失败 \n");
//
//        fprintf(stderr, " %s1\n", mysql_error(&mysql));

        exit(1);

    } else {

//        fprintf(stderr, "数据库连接成功\n");

    }
}
//查找管理员
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
            fprintf(stderr, "0:mysql_store_result failure！\n");
        } else {
            row = mysql_fetch_row(result);
            while (row) {
                if (strcmp(password, row[0]) == 0) {
                    printf("登陆成功\n");
                    return 1;
                } else {
                    printf("登录失败，请重新输入账号密码！\n");
                    userid=-1;
                    return 0;
                }
                row = mysql_fetch_row(result);
            }
        }
    }
    system("pause");
}
//查找商品
void findgoods(){
    system("cls");
    printf("-----------------------------------\n");
    printf("请输入待查询的商品名称：\n");
    getchar();
    char bufffer[100],input[20];
    cin >> input;
    sprintf(bufffer,"select * from goods where name = \'%s\';",input);
    if (mysql_real_query(&mysql, bufffer, (unsigned long) strlen(bufffer))) {
        fprintf(stderr, "mysql_real_query err");
    } else {
        result = mysql_store_result(&mysql);
        if (result == NULL) {
            fprintf(stderr, "mysql_store_result failure！\n");
        } else {
            printf("名称    库存    售价   进价\n-----------------------------------\n");
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
    printf("请输入要修改的名称:\n");
    cin >> input;
    printf("请输入需要修改的内容：\n1.库存\n2.售价\n3.进价\n");
    cin >> op;
    switch (op) {
        case 1:
            printf("请输入待修改的数量：\n");
            cin >> t;
            sprintf(edit,"numbers = %.2f",t,254);
            break;
        case 2:
            printf("请输入待修改的售价：\n");
            cin >> tf;
            sprintf(edit,"price = %.2f",tf,254);
            break;
        case 3:
            printf("请输入待修改的进价：\n");
            cin >> tf;
            sprintf(edit,"purchasedprice = %.2f",tf,254);
            break;
    }
    sprintf(buffer,"update goods set %s where name = \'%s\';",edit,input);
    //cout << buffer;
    mysql_query(&mysql, buffer);
    printf("修改成功！\n");
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
            fprintf(stderr, "mysql_store_result failure！\n");
        } else {
            printf("\n-----------------------------------\n""时间     收入      支出\n"
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
               "请选择筛选条件：(输入最小，最大值)\n");
    cin >> s >> b;
    sprintf(buffer,"select * from money where sum >= %d and sum <= %d;",s,b);
    if (mysql_real_query(&mysql, buffer, (unsigned long) strlen(buffer))) {
        fprintf(stderr, "mysql_real_query err");

    } else {
        result = mysql_store_result(&mysql);
        if (result == NULL) {
            fprintf(stderr, "mysql_store_result failure！\n");
        } else {
            printf("时间        收入  支出\n"
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
           "请输入待查看的月份：\n");
    cin >> m;
    sprintf(buffer,"select * from money where month = %d;",m);
    if (mysql_real_query(&mysql, buffer, (unsigned long) strlen(buffer))) {
        fprintf(stderr, "mysql_real_query err");

    } else {
        result = mysql_store_result(&mysql);
        if (result == NULL) {
            fprintf(stderr, "mysql_store_result failure！\n");
        } else {
            printf("时间        收入  支出\n");
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
    printf("请输入新增管理员账户名：\n");
    cin >> account;
    printf("请输入新增管理员密码:\n");
    cin >> password;
    sprintf(buffer,"insert into clerk (account,password) values (\'%s\',\'%s\');",account,password);
    mysql_query(&mysql, buffer);
    printf("新增成功！\n");
    system("pause");
}
void adduser(){
    system("cls");
    char buffer[255],account[20],password[20];
    int vip=0;double balance=0.0;
    printf("请输入新增用户账户名：\n");
    cin >> account;
    printf("请输入新增用户密码:\n");
    cin >> password;
    printf("是否设置为vip？(0为否，1为是）\n");
    cin >> vip;
    printf("请输入初始余额：\n");
    cin >> balance;
    sprintf(buffer,"insert into guest (account,password,vip,balance) values (\'%s\',\'%s\',%d,%.2f);",account,password,vip,balance);
    mysql_query(&mysql, buffer);
    printf("新增成功！\n");
    system("pause");
}
void setvip(){
    char buffer[255],name[20];
    system("cls");
    printf("请输入设置为vip的用户名：\n");
    cin >> name;
    sprintf(buffer,"update guest set vip = 1 where account = \'%s\';",name);
    mysql_query(&mysql, buffer);
    printf("已将%s用户设置为vip\n",name);
    system("pause");
}
void deleteuser(){
    char buffer[255],name[20];
    int op;
    printf("\n-----------------------------------\n"
           "请输入删除用户的类型：\n"
           "1.管理员\n"
           "2.用户\n");
    cin >> op;
    printf("请输入待删除的账号名：\n",name);
    cin >> name;
    if(op==1)
        sprintf(buffer,"delete from clerk where account = \'%s\';",name);
    else
        sprintf(buffer,"delete from guest where account = \'%s\';",name);
    mysql_query(&mysql, buffer);
    printf("删除成功！\n");
    system("pause");
}
void disallgoods(){
    char buffer[100]="select name,price from goods order by price asc ;";
    if (mysql_real_query(&mysql, buffer, (unsigned long) strlen(buffer))) {
        fprintf(stderr, "mysql_real_query err");

    } else {
        result = mysql_store_result(&mysql);
        if (result == NULL) {
            fprintf(stderr, "mysql_store_result failure！\n");
        } else {
            printf("\n-----------------------------------\n""名称         价钱\n"
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
            fprintf(stderr, "0:mysql_store_result failure！\n");
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
            fprintf(stderr, "0:mysql_store_result failure！\n");
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
            fprintf(stderr, "0:mysql_store_result failure！\n");
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
    printf("请输入当前购买人：(输入next切换下一天,exit退出)\n");
    cin >> buyer;
    if(strcmp(buyer, "next") == 0){
        nextday();
        printf("日期已进入下一天!当前日期为%04d年%02d月%02d日。\n",y,m,d);
        system("pause");
        goto buy;
    }else if(strcmp(buyer,"exit")==0){
        printf("已退出收银系统！\n");
    }else{
    disallgoods();
    do {
        printf("-----------------------------------\n"
               "时间：%4d年%02d月%02d日\n"
               "请输入待购买的商品名称和数量：（输入ok完成结算，exit退出）\n", y, m, d);
        cin >> input;
        if (strcmp(input, "ok") == 0) {
            printf("正在结算------\n"
                   "总共消费：%.2f元，请选择支付方式：\n"
                   "1.会员卡消费\n"
                   "2.现金消费\n", sum);
            int op;
            cin >> op;
            switch (op) {
                case 1:
                    balance = getdata("balance", "guest", "account", buyer);
                    if (balance < sum) {
                        printf("支付失败，请选择现金支付\n");
                        goto cash;
                    } else {
                        printf("支付成功消费金额：%.2f元\n", sum);
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
                    printf("成功支付！\n");
                    system("pause");
                    goto buy;
            }
        }else if (strcmp(input, "exit") == 0) {
            printf("已退出收银系统！\n");
            break;
        } else {
            cin >> numbers;
            t1 = getdata("price", "goods", "name", input) * numbers;
            t2 = getdata("purchasedprice", "goods", "name", input) * numbers;
            sum += t1;
            sumout += t2;
            printf("已添加商品：%s，单价为：%.2f，总价为：%.2f\n", input, t1 / numbers, sum);
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
            fprintf(stderr, "mysql_store_result failure！\n");
        } else {
            while (row = mysql_fetch_row(result)) {
                printf("你的密码是：%s\n",
                       row[0]);
            }
        }
    }
    int isvip= getintdata("vip","guest","account",idbuffer);
    double balance= getdata("balance","guest","account",idbuffer);
    if(isvip==0)
        printf("你还未成为vip！\n");
    else
        printf("你已经是vip！\n");
    printf("钱包剩余余额：%.2f\n",balance);
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
               "时间：%4d年%02d月%02d日\n"
               "请输入待购买的商品名称和数量：（输入ok完成结算，next下一天,exit退出）\n",y,m,d);
        cin >> input ;
        if(strcmp(input,"ok")==0){
            printf("正在结算------\n"
                   "总共消费：%.2f元，请选择支付方式：\n"
                   "1.会员卡消费\n"
                   "2.现金消费\n",sum);
            int op;
            cin >> op;
            switch (op) {
                case 1:
                    balance= getdata("balance","guest","account",idbuffer);
                    if(balance<sum){
                        printf("支付失败，请选择现金支付\n");
                        goto cash;
                    }else{
                        printf("支付成功消费金额：%.2f元\n",sum);
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
                    printf("成功支付！\n");
                    system("pause");
                    goto buy;
            }
        }else if(strcmp(input,"next")==0){
            nextday();
        }else if(strcmp(input,"exit")==0){
            printf("已退出收银系统！\n");
            break;
        }
        else{
            cin >> numbers;
            t1= getdata("price","goods","name",input)*numbers;
            t2= getdata("purchasedprice","goods","name",input)*numbers;
            sum+=t1;sumout+=t2;
            printf("已添加商品：%s，单价为：%.2f，总价为：%.2f\n",input,t1/numbers,sum);
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
            fprintf(stderr, "mysql_store_result failure！\n");
        } else {
            fprintf(fp,"year,month,day,sum,sumout\n");
            while (row = mysql_fetch_row(result)) {
                fprintf(fp,"%s,%s,%s,%s,%s\n",
                       row[0], row[1], row[2], row[3], row[4]);
            }
        }
    }
    fclose(fp);
    printf("文件已成功导出！\n");
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
            fprintf(stderr, "mysql_store_result failure！\n");
        } else {
            fprintf(fp,"name,numbers,price,purchasedprice\n");
            while (row = mysql_fetch_row(result)) {
                fprintf(fp,"%s,%s,%s,%s\n",
                        row[0], row[1], row[2], row[3]);
            }
        }
    }
    fclose(fp);
    printf("文件已成功导出！\n");
    system("pause");
}
void addbalance(){
    system("cls");
    printf("请输入待充值的余额：\n");
    double sum=0.0;
    cin >> sum;
    sum+=getdata("balance","guest","account",idbuffer);
    updoubledate("guest","balance",sum,"account",idbuffer);
    printf("充值成功，当前钱包余额剩余：%.2f\n", getdata("balance","guest","account",idbuffer));
    system("pause");
}