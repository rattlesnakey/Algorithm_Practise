#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    // float y = 3.0/4.0;
    // int yy = int(y);
    // cout<<yy - y;
    int x = 12321;
    stringstream ss;
    ss<<x;
    string s;
    ss>>s;
    cout<<s;
    for(int i=0;i<s.size()/2;i++){
        if(s[i] != s[s.size()-i])
    }
    return 0;
}