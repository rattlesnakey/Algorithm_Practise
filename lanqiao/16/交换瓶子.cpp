#include<iostream>
using namespace std;

int min_step = 10000;

int find_i(int a[],int i){
    for(int j=0;j<5;j++){
        if(a[j]-1 == i){
            return j;
        }
    }
    return -1;
}
// dfs方法是不行的，因为他不能直接交换最后的两个位置，这样就会多出交换的次序
// bool check_sort(int a[]){
//     for(int i=0;i<4;i++){
//         if (a[i]>a[i+1])return false;
//     }
//     return true;
// }

// void dfs(int a[], int cur_loc, int swap_times){
//     if (cur_loc >=5)return;
//     if(check_sort(a)){
//         if(swap_times < min_step){
//             min_step = swap_times;
//         }
//     }
//     for(int k=0;k<5;k++){
//         if (k==cur_loc)continue;  // 不用跟自己换
//         swap(a[k],a[cur_loc]);
//         dfs(a, cur_loc+1, swap_times+1);
//         swap(a[k],a[cur_loc]);
//     }
// }

int main(){
    int a[] = {3,1,2,5,4};
    int step = 0;
    for(int i=0;i<5;i++){
        int cur_i = find_i(a,i);
        if(cur_i == i){
            continue;
        }
        swap(a[i],a[cur_i]);
        step++;
    }
    // dfs(a,0,0);
    cout<<step;
    cout<<min_step;
    return 0;
}