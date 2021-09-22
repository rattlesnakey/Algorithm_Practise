#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main(){

    stringstream ss;
    ss<<1;
    string temp;
    ss>>temp;
    cout<<temp<<endl;
    return 0;
}