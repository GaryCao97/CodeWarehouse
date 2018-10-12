#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    int N,M,**total,s;
    total = (int**)malloc(T*sizeof(int*));
    for(int i = 0;i < T;i++){
            cin >> N >> M;
            int num[N];
            for(int j = 0;j < N;j++)cin >> num[j];
            total[i] = (int*)malloc((M+1)*sizeof(int));
            total[i][0] = M;
            for(int j = 0;j < M;j++){
                    cin >> s;
                    int max = 0;
                    for(int k = 1;k < N;k++){
                            if((s|num[max]) < (s|num[k]))max = k;
                    }
                    total[i][j+1] = num[max];
            }
    }
    for(int i = 0;i < T;i++){
            cout << "Case #" << i+1 << ":" << endl;
            for(int j = 1;j <= total[i][0];j++){
                    cout << total[i][j] << endl;
            }
    }
    system("pause");
    return 0;
}
