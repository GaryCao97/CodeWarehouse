#include<iostream>
using namespace sdt;
typedef struct{
    double x1,y1,x2,y2;
}area;
int main(){
    int n;
    area *a;
    while(cin >> n && n!=0){
        a = (area*)malloc(n*sizeof(area));
        for(int i = 0;i < n;i++){
            cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        }
    }
    return 0;
}
