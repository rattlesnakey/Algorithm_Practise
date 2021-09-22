#include<iostream>
using namespace std;
int a[100];
int n;
int ans;
int cnt[100];  // 记录被交换的次数
int min_sum = 1000;

// 并不是按顺序从左向右依次交换就能成功的，应该还要从后往前一次才行，或者说像交换排序那样n-1次趟从左往右

void swap_(int a[], int x, int y){
    int temp = a[y];
    a[y] = a[x];
    a[x] = temp;
}
int check(int a[]){
    int flag = 1;
    for(int i=0;i<n-1;i++){
        if (a[i]>a[i+1]){
            flag = 0;
            break;
        }
    }
    return flag;
}

int get_sum(int cnt[]){
    int temp_sum = 0;
    for(int i=0;i<=n;i++){
        for(int j=1;j<=cnt[i];j++){
            temp_sum += j;
        }   
    }
    return temp_sum;
}

void print_a(int a[]){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void dfs(int a[], int step, int dir){
    if (step == -1 && dir == -1){
        if(check(a)==1){
            // print_a(a);
            // print_a(cnt);
            int temp_sum = get_sum(cnt);
            if (temp_sum < min_sum){
                min_sum = temp_sum;
            }
        }
        return;
    }
    if(step == n-1 ){
        if (check(a) == 1){
            int temp_sum = get_sum(cnt);
            if (temp_sum < min_sum){
                min_sum = temp_sum;
            }
        }
        dir = -1;  // 往左走
        dfs(a,step+dir,dir);
    }
    dfs(a, step+dir,dir);
    cnt[a[step]]++;
    cnt[a[step+1]]++;
    swap_(a,step,step+1);  
    dfs(a, step+dir,dir);
    swap_(a,step,step+1);
    cnt[a[step]]--;
    cnt[a[step+1]]--;
    return;
}
// 3:1+2, 2:1+2, 1:1+2
int main(){
    cout<<1<<endl;
    cin >>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(a, 0, 1);
    cout<<min_sum;
    return 0;
}