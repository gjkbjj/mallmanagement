//
// Created by 18395 on 2022/6/26.
//

#include "../s.h"

using namespace std;


void loginin(int op){
    do{
        if(userid!=-1)
            break;
        printf("ÇëÊäÈëÄãµÄÕËºÅ£º\n");
        cin >> idbuffer;
        printf("ÇëÊäÈëÄãµÄÃÜÂë£º\n");
        cin >> passwordbuffer;
        if(op==0)
            if(finduser(idbuffer,passwordbuffer,"admin")) userid=0;
        if(op==1)
            if(finduser(idbuffer,passwordbuffer,"clerk")) userid=1;
        if(op==2)
            if(finduser(idbuffer,passwordbuffer,"guest")) userid=2;
    } while (1);
}

