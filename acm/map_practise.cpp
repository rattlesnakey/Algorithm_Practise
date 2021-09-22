#include<iostream>
#include<map>
#include<utility>
using namespace std;

int main(int argc, char *argv[]){
    map<string, int> m;
    m["张恒源"] = 1;
    m["李大卫"] = 2;
    m.insert(make_pair("杨士平",3));
    for (map<string, int> :: iterator it = m.begin(); it!= m.end(); it++){
        cout<<it->first<<":"<<it->second<<endl;
    }
    cout<<m.size()<<endl; // key的种类数的不同
    return 0;
}