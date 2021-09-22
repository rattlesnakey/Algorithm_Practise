#include<iostream>
#include<vector>
using namespace std;

int main(){
    // vector<int> a= {1,2,3,4,5};
    int b[100] = {5,6,7,8};
    int *p = find(b,b+4,6);  // 在某个范围里面找值
    if (p!=b+4){  // a.begin(), a.end()这些都是指针，！=v.end()说明是已经找到了
        cout<< *p<<endl;
    }
    return 0;
}
