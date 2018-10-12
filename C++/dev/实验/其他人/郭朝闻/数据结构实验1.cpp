#include<iostream>
using namespace std;
#include<iomanip>

struct student
{
	long long number;
	char name[20];
	float score[5];
};


void input(struct student *p,int n){
	int i,j;
	for(i=0;i<n;i++){
		cout<<"请输入学生姓名，然后按下<enter>键:"<<endl;
		cin>>(p+i)->name;
		cout<<"请分别输入学号以及 语文、数学、英语、物理4门成绩,"<<endl;
		cout<<"中间用空格隔开，然后按下<enter>键:"<<endl;
		cin>>(p+i)->number;   //输入学号 
		for(j=0;j<4;j++)//输入四科成绩 
			cin>>(p+i)->score[j];
	}
}

void average(struct student *p,int n){
	int j;
	struct student *q;
	for(q=p;q<=p+n;q++){
		q->score[4]=0.0;
		for(j=0;j<4;j++)
		    q->score[4]+=q->score[j];
	q->score[4]=q->score[4]/4;
	}
	
}

void bujige(struct student *p,int n) {
	int i,j;
	cout<<"不及格的同学有： ";
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
			if((p+i)->score[j]<60){
		    	cout<<(p+i)->name<<" ";
		    	break;
			}
	    }
	}
	cout<<endl;
}

void gaofen(struct student *p,int n){
	int i,j;
	cout<<"90分以上的同学有： ";
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
	    	if((p+i)->score[j]>90){
		    	cout<<(p+i)->name<<" ";
		    	break;
			}
		}
    }
    cout<<endl;
}


void output (struct student *p,int n){
    int i,j;
    cout<<"-------------------------------------------------------------------------"<<endl;
    //输出水平线 
    cout<<setiosflags(ios::right)<<setw(15)<<"姓名" 
        <<setw(8)<<"学号"<<setw(8)<<"语文"
        <<setw(8)<<"数学"<<setw(8)<<"英语"<<setw(8)<<"物理"
        <<setw(15)<<"平均成绩"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
        for (i=0;i<n;i++){
        	//输出姓名和学号 
            cout<<setiosflags(ios::right)<<setw(15)<<(p+i)->name
			    <<setw(8)<<(p+i)->number;
            cout<<setiosflags(ios::fixed)<<setprecision (2);
            for(j=0;j<4;j++)
            
			   //输出语文、数学、英语、物理成绩 
			    cout<<setw(8)<<(p+i)->score[j];
			   
			//输出每个学生平均成绩 
			cout<<setw(15)<<(p+i)->score[j];
            
            cout<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
		}
	    
	}
		
int main()
{
	int N;
	cout<<"请输入有多少学生：";
	cin>>N;
	struct student stu[N];
	
	input(stu,N);
	average(stu,N);
	output(stu,N);
    bujige(stu,N);
    gaofen(stu,N);
}

