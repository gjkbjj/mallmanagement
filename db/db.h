//
// Created by 18395 on 2022/6/26.
//

#ifndef JDULTIMATED_DB_H
#define JDULTIMATED_DB_H


#endif //JDULTIMATED_DB_H
#include "iostream"
using namespace std;
void connectDb();
int finduser(char id[],char password[],char table[]);
void findgoods();
void editgoods();
void disallmoney() ;
void limitedmoney();
void findmonthmoney();
void addadmin();
void adduser();
void setvip();
void deleteuser();
void adminbuy();
void disallgoods();
double getdata(char ret[],char table[],char s1[],char s2[]);
void updoubledate(char table[],char select [],double t,char s1[],char s2[]);
void upintdate(char table[],char select [],int t,char s1[],char s2[]);
int getintdata(char ret[],char table[],char s1[],char s2[]);
char * getchardata(char ret[], char table[], char s1[], char s2[]);
void disguest();
void guestbuyer();
void outputfile();
void outputgoodsfile();
void addbalance();