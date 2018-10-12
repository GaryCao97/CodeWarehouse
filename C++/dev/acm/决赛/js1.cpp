#include<iostream>
#include<string>
#include<stdlib.h>
#include <algorithm>
#include<string.h>
#include <cctype>
using namespace std;
int isAllEng(string str){
      int tag = 1;
      for(int i = 0;i < str.length();i++){
              if(str[i] >= '0' && str[i] <= '9'){
                         tag = 0;
                         break;
              }
      }
      return tag;
}
int isAllNum(string str){
      int tag = 1;
      for(int i = 0;i < str.length();i++){
              if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
                         tag = 0;
                         break;
              }
      }
      return tag;
}
void toUp(string &str){
      for(int i = 0;i < str.length();i++){
              if((str[i] >= 'a' && str[i] <= 'z')){
                         str[i]+='A'-'a';
              }
      }
}
int main(){
    string str1,str2,std = "ncu666";
    while(cin >> str1 >> str2){
              if(str1 == str2){
                      if(str1 == std) cout << '6' << endl;
                      else if(isAllNum(str1)) cout << '5' << endl;
                      else if(isAllEng(str1)) cout << '1' << endl;
                      else cout << '9' << endl;
              }
              else{
                   int tag = 0;
                   if(str1.length() == 1 && str2.length() == 1){
                       if(str1[0] >= '0' && str1[0] <= '9' && str2[0] >= 'A' && str2[0] <= 'Z'){cout << '7' << endl;tag = 1;}
                       if(str1[0] >= 'a' && str1[0] <= 'z' && str2[0] >= '0' && str2[0] <= '9'){cout << '8' << endl;tag = 1;}
                   }
                   if(isAllEng(str1)&&isAllEng(str2)){
                       if(str1.length()==str2.length()){
                       toUp(str1);toUp(str2);
                           if(str1 == str2){
                                   cout << '3'<< endl;
                                   tag = 1;
                           }
                       }
                       else {
                           cout <<'2'<< endl;
                           tag = 1;
                       }
                   }
                   reverse(str1.begin(),str1.end());
                   if(isAllEng(str1)&&isAllEng(str1))
                       if(str1 == str2){cout << '0' << endl;tag = 1;}
                   if(tag == 0){
                          if(str1.length()==str2.length())cout << '9'<< endl;
                          else {
                               if(!isAllNum(str1)&&!isAllEng(str1)&&!isAllNum(str2)&&!isAllEng(str2)) cout << '4'<< endl;
                               else cout << '9' << endl;
                          }
                   }
              }
    }
    return 0;
} 
