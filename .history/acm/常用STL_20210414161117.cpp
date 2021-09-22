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

	int iarr1[]={1,2,3,3,4,5,6,7};
	int iarr2[]={1,4,3,9,10};
	multiset<int> iset1(begin(iarr1),end(iarr1));
	multiset<int> iset2(begin(iarr2),end(iarr2));
	vector<int> ivec(10);  
	auto iter=set_difference(iset1.begin(),iset1.end(),iset2.begin(),iset2.end(),ivec.begin());	//ivec为：2,3,5,6,7
	ivec.resize(iter-ivec.begin());//重新确定ivec大小

	return 0;
}