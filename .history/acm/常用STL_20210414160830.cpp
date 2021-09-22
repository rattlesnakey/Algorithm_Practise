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

    auto iter = set_difference(b.begin(),b.end(),c.begin(),c.end(),r);
    cout<<*iter<<endl;

    return 0;
}