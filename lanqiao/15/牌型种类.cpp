#include<iostream>
using namespace std;

int ans;
void dfs(int level, int cnt){
    if (level>13 || cnt > 13){
        return;
    }
    if(level == 13 && cnt == 13){
        ans++;
    }
    for(int i=0;i<5;i++){
        dfs(level+1,cnt+i);
    }
}

int main(){
    dfs(0,0);
    cout<<ans;
}
