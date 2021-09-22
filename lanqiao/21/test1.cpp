#include<iostream>
#include<map>
using namespace std;
map<int, int > m;
int check(int x){
	while(x){
		int cur_num = x % 10;
		m[cur_num] --;
		if(m[cur_num]<0){
			return 0;
		}		
		x /= 10;
	}
	return 1;
}
int main(){
	m[0] = 2021;
	m[1] = 2021;
	m[2] = 2021;
	m[3] = 2021;
	m[4] = 2021;
	m[5] = 2021;
	m[6] = 2021;
	m[7] = 2021;
	m[8] = 2021;
	m[9] = 2021;
	for(int i=1;i<=10000;i++){
		int flag = check(i);
		if(!flag){
			cout<<i-1<<endl;
			break;
		}
	}
}
