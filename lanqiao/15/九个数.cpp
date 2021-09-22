#include<iostream>
#include<algorithm>
using namespace std;
int a[4] = {1,2,3,4};
int ans;
void swap(int a[], int x, int y){
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}
void f(int a[], int cur_level){
    if(cur_level == 4){
        ans++;
        return;
    }
    for(int i = cur_level;i<4; i++){
        swap(a,cur_level, i);
        f(a, cur_level+1);
        swap(a, cur_level, i);
    }
}

int main(){

    // do{
    //     ans++;
    // }while(next_permutation(a, a + 4));
    f(a,0);
    cout<<ans;
    return 0;
}