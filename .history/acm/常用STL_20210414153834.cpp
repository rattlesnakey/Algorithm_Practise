#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int > a = {1,2,5,4};
    cout<<is_sorted(a.begin(),a.end());
    return 0;
}