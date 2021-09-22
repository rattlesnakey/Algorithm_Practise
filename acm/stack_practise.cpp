#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> c(10);  //一维数组

int main(int argc, char *argv[]){
    vector<int> a[10];  // 二维数组
    a[0] = c;
    vector<int >b(10,1);  // 一维数组赋初值
    a[1] = b;
    for (int i = 0; i<2;i++){
        for (int j=0;j<a[i].size();j++){
            cout<<(a[i][j])<< " ";
        }
        cout<<endl;
    }
    stack<int > s;
    s.push(1);
    s.push(2);
    cout<<s.top()<<endl;
    return 0;
}