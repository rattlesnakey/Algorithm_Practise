#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int > a {1,2,5,4};
    is_sorted_until(a.begin(),a.end());
    // cout<<is_sorted_until(a.begin(),a.end());
    return 0;
}