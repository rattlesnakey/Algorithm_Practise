#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int vis[100];
int sum;
int pp[100];
int n;
int flag;

void dfs(int p, int s){
    if (flag){
        return;
    }
    if (s>sum/3) return;
    if (p==3){
        flag = 1;
        vector<int> result;
        for(int i = 0;i<n;i++){
            if(vis[i]==1){
                result.push_back(pp[i]);
            }
        }
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
        }
        return;
    }
    if (s == sum/3){
        dfs(p+1, 0);
    }
    for(int i=0;i<n;i++){  // 相当于是每一层进来都要重新再从这些可选树里面进行选择
        if(vis[i]!=1){
            vis[i]=1;
            dfs(p, s+pp[i]);
            vis[i]=0;
        }
    }
}

int main(){
    cin>>sum;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>pp[i];
    }
    dfs(0,0);
    return 0;
}