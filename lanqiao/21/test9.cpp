#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct point{
	int x;
	int y;
	point(int xx, int yy):x(xx),y(yy){};
};
void print_v(vector<int> x){
	for(int i=0;i<x.size();i++){
		if(i == x.size()-1)cout<<x[i];
		else {
			cout<<x[i]<<" ";
		}
	}
	cout<<endl;
} 
int main(){
	int n,m;
	cin>>n;
	cin>>m;
	vector<int> x;
	vector<point> y;
	for(int i=1;i<=n;i++){
		x.push_back(i);
	} 
	for(int j=0;j<m;j++){
		int t1,t2;
		cin>>t1>>t2;
		y.push_back(point(t1,t2));
	}
	for(int i=0;i<y.size();i++){
		int idx = y[i].y;
		if (y[i].x == 0){
			sort(x.begin(),x.begin()+idx,greater<int>());
			print_v(x);
		}
		if(y[i].x == 1){
			sort(x.begin()+y[i].y - 1,x.end());
			print_v(x);
		}
	} 
	print_v(x);
	return 0;
}
