#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    // float y = 3.0/4.0;
    // int yy = int(y);
    // cout<<yy - y;
    int x = 12321;
    stringstream ss = stringstream(x);
    int s;
    ss>>s;
    cout<<s;

    return 0;
}