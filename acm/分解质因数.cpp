#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
    int n = 120;
    for(int i=2;i<=(n);i++){
        if(n%i==0){  // 默认的数学规则就是，只有素数才能不断地被整除下去
            while(n%i==0){  // 如果能整除，就用这个质数一直整除下去，直到它不能整除了为止
                n /= i;
                cout<<i<<endl;
            }
        }
    }
    // for(int i=2;i<=sqrt(n);i++){
    //     if(n%i==0){
    //         while(n%i==0){  // 如果能整除，就用这个质数一直整除下去，直到它不能整除了为止
    //             n /= i;
    //             cout<<i<<endl;
    //         }
    //     }
    // }
    // if(n!=1){  // 最后一直整除下去n会变成1，但是有的数可能就不在sqrt(n)里面，所以这边得多一个判断，但是我觉得可以遍历所有的n应该就可以省掉这一个判断了, 比如11, sqrt（11）是没有11的
    //     cout<<n<<endl;
    // }
    return 0;
}