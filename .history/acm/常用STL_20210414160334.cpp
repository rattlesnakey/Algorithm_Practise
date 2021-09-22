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
    cout<< *it<<endl;
    // cout<<is_sorted_until(a.begin(),a.end());
    d = set_difference(b,c);
    return 0;
}