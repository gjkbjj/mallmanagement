//
// Created by 18395 on 2022/6/26.
//

#ifndef JDULTIMATED_S_H
#define JDULTIMATED_S_H

#endif //JDULTIMATED_S_H

#include "iostream"
#include "string.h"
#include "mysql.h"
#include "db/db.h"
#include "user/user.h"
#include "windows.h"
#include "stdlib.h"

extern int userid;
extern int y,m,d;
extern char idbuffer[20],passwordbuffer[20];
extern int vip;

int backmoney(int money);
void nextday();
void editday();