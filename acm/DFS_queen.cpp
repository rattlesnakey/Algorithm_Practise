#include<iostream>
using namespace std;
int ans;
int col[10], x1[20],x2[20];
bool check(int x, int y){
    return !col[y] && !x1[x+y] && !x2[x-y+8];
}

void dfs(int r){
    if(r==8){
        ans++;
        return;
    }
    for(int i=0;i<8;i++){ // 每一行的8列都要遍历一下
        if(check(r, i)){
            col[i] = x1[r+i] = x2[r-i+8] = true;
            dfs(r+1);
            col[i] = x1[r+i] = x2[r-i+8] = false;
        }
    }
}

int main(){
    dfs(0);
    cout<<ans;
}