#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    // float y = 3.0/4.0;
    // int yy = int(y);
    // cout<<yy - y;
    string s = "12321";
    stringstream ss = stringstream(s);
    int x;
    ss>>x;
    cout<<x;

    return 0;
}