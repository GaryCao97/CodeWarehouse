#include <cstdio>  
#include <algorithm>  
#include <vector>  
#include <string>  
using namespace std;  
typedef struct Student{  
    string  ID;  
    int  De;  
    int Cai;  
}Student;  
inline bool compare(Student a,Student b){  
    if ((a.Cai+a.De)!=(b.Cai+b.De))  
    return a.Cai+a.De>b.Cai+b.De;  
    else if (a.De!=b.De)  
    return a.De>b.De;  
    else  
    return a.ID<b.ID;  
}
inline void print(Student s){  
    printf("%s %d %d\n",s.ID.c_str(),s.De,s.Cai);  
}
int main(){  
     int N,L,H;
     char id[10];
     Student  S;
     string  ID;
     vector<Student>    vec1;
     vector<Student>    vec2;
     vector<Student>    vec3;
     vector<Student>    vec4;  
     scanf("%d %d %d",&N,&L,&H);
     while(N--){ 
         scanf("%s%d%d",id,&S.De,&S.Cai);  
         S.ID.assign(id);  
        if (S.De>=L&&S.Cai>=L)  
        {  
            if (S.De>=H&&S.Cai>=H)  
                vec1.push_back(S);  
            else  
            if (S.De>=H&&S.Cai<H)  
                vec2.push_back(S);  
            else  
           if (S.De<H&&S.Cai<H&&S.De>=S.Cai)  
                vec3.push_back(S);  
            else  
                vec4.push_back(S);      
        }  
     }  
     sort(vec1.begin(),vec1.end(),compare);  
     sort(vec2.begin(),vec2.end(),compare);  
     sort(vec3.begin(),vec3.end(),compare);  
     sort(vec4.begin(),vec4.end(),compare);   
     printf("%d\n",vec1.size()+vec2.size()+vec3.size()+vec4.size());
     for_each(vec1.begin(),vec1.end(),print);  
     for_each(vec2.begin(),vec2.end(),print);  
     for_each(vec3.begin(),vec3.end(),print);  
     for_each(vec4.begin(),vec4.end(),print);  
    return 0;  
}  
