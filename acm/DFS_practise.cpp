#include<iostream>
#include<cstdio>
using namespace std;
int buffer[100];
int m;
int s;
int n;
int ans;
void dfs(int sum, int k, int layer){  // 我这个是顺序的从上往下的，也就说是固定次序的，所以不存在多种, 答案就是为2
    if (layer == n+1){
        return;
    }
    if((sum == s) && (k == m)){
        ans += 1;
        return;
    }
    dfs(sum, k, layer + 1);
    dfs(sum + buffer[layer], k+1, layer+1);
    return;
}
bool xuan[100];
void dfs_2(int sum, int k){
    if((sum == s) && (k == m)){
        ans += 1;
        return;
    }
    for(int i=0;i<n;i++){ // 每一层里面都是这些数供你选择，这个其实是有点像全排列了
        if (xuan[i]!=1){
            xuan[i]=1;
            dfs_2(sum+buffer[i],k+1);
            xuan[i]=0;
        }
    }
}
int main(int argc, char *argv[]){
    cin>>n>>m>>s;
    for (int i=0; i < n;i++){
        cin>>buffer[i];
    }
    dfs_2(0,0);
    cout<<ans;
    return 0;
}