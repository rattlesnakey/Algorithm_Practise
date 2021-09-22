#include<numeric>
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int > a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    int sum = accumulate(a.begin(),a.end(),0);
    for(int i=0;i<3;i++){
        cout<<a[i]<<endl;
    }    
    cout<<sum;
    return 0;
}