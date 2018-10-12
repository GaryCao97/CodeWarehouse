#include<iostream>
using namespace std;
int getDay(int yy,int mm,int dd){
    int day = 0;
    switch(mm){
    case 12:day+=30;
    case 11:day+=31;
    case 10:day+=30;
    case 9:day+=31;
    case 8:day+=31;
    case 7:day+=30;
    case 6:day+=31;
    case 5:day+=30;
    case 4:day+=31;
    case 3:
         if((yy % 400 == 0) || ((yy %100 !=0) && (yy %4 == 0)))day+=29;
         else day+=28;
    case 2:day+=31;
    case 1:day+=dd;
    }
    return day;
}
int getAllDay(int yy){
    int day = 0;
    for(int i = yy-1;i > 0;i--){
         if((i % 400 == 0) || ((i %100 !=0) && (i %4 == 0)))day+=366;
         else day+=365;
    }
    return day;
}
int main(){
    int Y,M,D,day;
    while(cin >> Y >> M >> D){
        day = getDay(Y,M,D) + getAllDay(Y);
        printf("%d:%02d:%02d is %d\n",Y,M,D,day%7);
    }
    return 0;
}
