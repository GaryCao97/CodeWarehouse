#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

int main(){
    char a[82],b[82],c[82],d;
    int n=0,i,j=0,k=0,flag;
    scanf("%s %s",a,b);
    for(i=0;i<strlen(a);i++){
        if((a[i]==b[j])&&(j<strlen(b)))
            j++;
        else{
            flag = 0;
            if(a[i]>='a'&&a[i] <='z')
                a[i]=a[i]+'A'-'a';
            for(k=0;k<n;k++)
                if(a[i]==c[k])
                    flag=1;
            if(flag==0)
                c[n++]=a[i];
        }
    }
    for(i=0;i<n;i++)
        printf("%c",c[i]);
    return 0;
}
