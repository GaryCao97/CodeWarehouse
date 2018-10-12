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
		cout<<"������ѧ��������Ȼ����<enter>��:"<<endl;
		cin>>(p+i)->name;
		cout<<"��ֱ�����ѧ���Լ� ���ġ���ѧ��Ӣ�����4�ųɼ�,"<<endl;
		cout<<"�м��ÿո������Ȼ����<enter>��:"<<endl;
		cin>>(p+i)->number;   //����ѧ�� 
		for(j=0;j<4;j++)//�����ĿƳɼ� 
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
	cout<<"�������ͬѧ�У� ";
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
	cout<<"90�����ϵ�ͬѧ�У� ";
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
    //���ˮƽ�� 
    cout<<setiosflags(ios::right)<<setw(15)<<"����" 
        <<setw(8)<<"ѧ��"<<setw(8)<<"����"
        <<setw(8)<<"��ѧ"<<setw(8)<<"Ӣ��"<<setw(8)<<"����"
        <<setw(15)<<"ƽ���ɼ�"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
        for (i=0;i<n;i++){
        	//���������ѧ�� 
            cout<<setiosflags(ios::right)<<setw(15)<<(p+i)->name
			    <<setw(8)<<(p+i)->number;
            cout<<setiosflags(ios::fixed)<<setprecision (2);
            for(j=0;j<4;j++)
            
			   //������ġ���ѧ��Ӣ�����ɼ� 
			    cout<<setw(8)<<(p+i)->score[j];
			   
			//���ÿ��ѧ��ƽ���ɼ� 
			cout<<setw(15)<<(p+i)->score[j];
            
            cout<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
		}
	    
	}
		
int main()
{
	int N;
	cout<<"�������ж���ѧ����";
	cin>>N;
	struct student stu[N];
	
	input(stu,N);
	average(stu,N);
	output(stu,N);
    bujige(stu,N);
    gaofen(stu,N);
}

