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
        cout<<"������Ϊ��"<<endl;
        cout<<"50Ԫ��"<<count[4]<<"��"<<endl;
        cout<<"20Ԫ��"<<count[3]<<"��"<<endl;
        cout<<"10Ԫ��"<<count[2]<<"��"<<endl;
        cout<<"5Ԫ��"<<count[1]<<"��"<<endl;
        cout<<"1Ԫ��"<<count[0]<<"��"<<endl;
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
    printf("��������޸ĵ��º��գ�\n");
    while(flag==0){
        scanf("%d %d",&b,&c);
        if(b>12||b<1){
            printf("���벻�Ϸ���������������!\n");
        } else if (c>day[b-1]||c<1){
            printf("���벻�Ϸ���������������!\n");
        } else {
            m=b;
            d=c;
            flag=1;
        }
    }
    printf("�޸��ѳɹ�����ǰ����Ϊ%4d��%02d��%02d�ա�\n",y,m,d);
    system("pause");
}