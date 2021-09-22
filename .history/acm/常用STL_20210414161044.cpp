#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int main(){
    vector<int > a {1,2,5,4};
    set<int >b {2,3,4};
    set<int >c {4,5,6};
    auto it = is_sorted_until(a.begin(),a.end());
    vector<int > r;
    cout<< *it<<endl;
    // cout<<is_sorted_until(a.begin(),a.end());

	int iarr1[]={1,2,3,3,6,7,4,5};
	int iarr2[]={1,4,3,10,9};
	std::sort(begin(iarr1),end(iarr1));
	std::sort(begin(iarr2),end(iarr2));
	vector<int> ivec(10);  
	auto iter=set_difference(begin(iarr1),end(iarr1),begin(iarr2),end(iarr2),ivec.begin());	//ivec为：2,3,5,6,7
	ivec.resize(iter-ivec.begin());//重新确定ivec大小
	return 0;
}