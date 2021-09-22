#include<iostream>
using namespace std;
int main(){
	long long a[100][100];
	for(int i=0;i<100;i++){
		for(int j=0;j<=i;j++){
			if (j==0||i==j){
				a[i][j] = 1;
			}
			else{
				a[i][j] = a[i-1][j] + a[i-1][j-1];
			}
		}
	}
	int t;
	cin>>t;
	int c = 0;
	int flag = 0;
	for(int i=0;i<100;i++){
		if (flag == 1){
			break;
		}
		for(int j=0;j<=i;j++){
			c += 1;
			if (a[i][j] == t){
				cout<<c;
				flag = 1;
				break;
			}
		}
	}
	return 0;
}
