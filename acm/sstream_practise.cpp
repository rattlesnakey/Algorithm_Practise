#include<sstream>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;  // 别忘了


string line;  
int main(){
    while(getline(cin,line)){  // cin是标准输入流，把标准输入流的内容给line
        int sum = 0; int x; int count = 0;
        int temp[100];
        stringstream ss (line); // 把string包装成 stringstream对象
        while(ss>>x) {
            sum += x;
            temp[count++] = x;
        }
        cout<<sum<<endl;
        sort(temp,temp+count);
        int p = lower_bound(temp,temp + count,11) - temp;  // lower_bound是用来找大于等于x的值的
        cout<<p<<endl;
    }
    return 0;
}