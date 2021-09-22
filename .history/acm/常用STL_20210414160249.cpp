#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int main(){
    vector<int > a {1,2,5,4};
    auto it = is_sorted_until(a.begin(),a.end());
    cout<< *it<<endl;
    // cout<<is_sorted_until(a.begin(),a.end());
    return 0;
}