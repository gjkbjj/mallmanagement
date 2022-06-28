//
// Created by 18395 on 2022/6/26.
//
#include "s.h"

int userid=-1;
int y=2022,m=6,d=28;
char idbuffer[20],passwordbuffer[20];
int vip=-1;

int single_money[7] = {1,5,10,20,50};
int number_money[7] = {23,13,44,56,49};
using namespace std;

int backmoney(int money)
{
    int count[5] = {};
    if (money >= 0)
    {
        for (int i = 6; i >= 0; i--)
        {
            count[i] = min(number_money[i],money/single_money[i]);
            money = money - count[i]*single_money[i];
        }
        cout<<"找零结果为："<<endl;
        cout<<"50元："<<count[4]<<"张"<<endl;
        cout<<"20元："<<count[3]<<"张"<<endl;
        cout<<"10元："<<count[2]<<"张"<<endl;
        cout<<"5元："<<count[1]<<"张"<<endl;
        cout<<"1元："<<count[0]<<"张"<<endl;
        return 0;
    }
    else
    {
        return money;
    }
}
void nextday(){
    if(d==30&&(m==4||m==6||m==9||m==11)){
        m++;
        d=1;
    } else  if(d==31&&(m==1||m==3||m==5||m==7||m==8||m==10)){
        m++;
        d=1;
    } else if(d==31&&m==12){
        y++;
        m=1;
        d=1;
    } else if(d==28&&m==2){
        m++;
        d=1;
    } else {
        d++;
    }
}
void editday(){
    int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int a,b,c,flag=0;
    printf("请输入待修改的月和日：\n");
    while(flag==0){
        scanf("%d %d",&b,&c);
        if(b>12||b<1){
            printf("输入不合法，请您重新输入!\n");
        } else if (c>day[b-1]||c<1){
            printf("输入不合法，请您重新输入!\n");
        } else {
            m=b;
            d=c;
            flag=1;
        }
    }
    printf("修改已成功！当前日期为%4d年%02d月%02d日。\n",y,m,d);
    system("pause");
}