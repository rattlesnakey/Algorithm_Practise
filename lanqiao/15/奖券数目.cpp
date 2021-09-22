#include<iostream>
#include<sstream>
#include<string>
using namespace std;

bool check(int num){
    while(num){
        int cur_num = num % 10;
        if (cur_num == 4) return false;
        num = num / 10;
    }
    return true;
}

string i2s(int x){
    stringstream ss;
    ss << x;
    string temp_s;
    ss >> temp_s;
    return temp_s;
}

int main(){
    int ans = 0;
    for(int i=10000;i<=99999;i++){
        // if(check(i))ans++;
        string cur = i2s(i);
        if(cur.find('4') == string::npos){ // 注意是两个冒号
            ans++;
        }
    }
    cout<<ans;
    return 0;
}