#include<iostream>
#include<algorithm>
using namespace std;

int ans;
bool check(int a[]){
    int x = a[3]*100+a[4]*10+a[5];
    int y = a[6]*100+a[7]*10+a[8];
    if((a[1]*y+x*a[2])%(a[2]*y) == 0){
        if(a[0]+(a[1]*y+x*a[2])/(a[2]*y) == 10){
            return true;
        }
    }
    return false;
}

void dfs(int a[], int level){  // 每一次都是当前这一位和它后面的所有位进行交换
    if (level>9){
        return ;
    }
    if(level == 9) {  // a[8]和它后面交换会进入到level 9
        if (check(a)){
            ans++;
        }
    }
    for(int i=level;i<9;i++){
        swap(a[level],a[i]);
        dfs(a, level+1);
        swap(a[level],a[i]);
    }
    return;
}
int main(){
    int a[] = {1,2,3,4,5,6,7,8,9};
    // do{
    //     if(check(a)){
    //         ans++;
    //     }
    // }while(next_permutation(a,a+9));
    dfs(a,0);
    cout<<ans;
    return 0;

    return 0;
}

    