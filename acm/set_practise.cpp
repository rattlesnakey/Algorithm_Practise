#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
// set里面的元素它会默认帮你排好序

int main(int argc, char *argv[]){
    set<string> country;
    country.insert("张恒源");
    country.insert("李大卫"); 
    // 定义一个迭代器指针
    for (set<string>::iterator it = country.begin();it!=country.end();it++){
        cout<<*it<<endl;
    }
    country.erase("张恒源");
    cout<<endl;
    for (set<string>::iterator it = country.begin();it!=country.end();it++){
        cout<<*it<<endl;
    }
    cout<<country.count("张恒源");  // 是看存在不存在这个值
    return 0;
}