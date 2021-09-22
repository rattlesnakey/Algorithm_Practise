#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
vector<int > v;
set<int > w;
void print_v(vector<int> x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" "; 
	}
}
void dfs(vector<int> x, int cur_w, int signal, int step){
	if (signal == 0){
		cur_w = cur_w - x[step];
	}
	if(signal == 1){
		cur_w = cur_w + x[step];
	}
	if(step == x.size()-1){
		if(cur_w>0){
			w.insert(cur_w);	
		} 
		return;
	}
	dfs(x,cur_w,0,step+1);  // 0 -  
	dfs(x,cur_w,1,step+1); // 1 + 
} 
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp); 
		w.insert(temp);
	}
	int len = v.size();
	for(int i=2;i<=len;i++){
		vector<int > meiju;
		for(int j=0;j<len-i;j++){
			meiju.push_back(0);
		}
		for(int k=0;k<i;k++){
			meiju.push_back(1);
		}
		do{
			vector<int > cur_num;
			for(int l=0;l<meiju.size();l++){
				if(meiju[l]==0){
					continue;
				}
				if(meiju[l] == 1){
					cur_num.push_back(v[l]);
				}
			}
			sort(cur_num.begin(),cur_num.end(),greater<int>());
			dfs(cur_num, cur_num[0], -1,0);
			
		}while(next_permutation(meiju.begin(),meiju.end()));
	}
	cout<<w.size();
	return 0;
}
