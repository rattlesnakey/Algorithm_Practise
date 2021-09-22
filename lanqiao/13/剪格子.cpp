#include<iostream>
using namespace std;

int total_sum;
int n,m;
int d[100][100];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int ans = 100;
int vis[100][100];

void dfs(int x, int y, int cur_sum, int step){  // 一般都是x,y然后带着你要的状态变量去走
    if(cur_sum == total_sum/2){
        cout<<1;
        ans = min(ans, step);
    }
    if(cur_sum>total_sum){
        return;
    }
    vis[x][y] = 1;
    for(int i=0;i<4;i++){
        int tx = x+dir[i][0];
        int ty = y+dir[i][1];
        if (!vis[tx][ty] && tx>=0 && tx<=n-1 && ty>=0 && ty<=m-1){  // 记得vis要判断
            dfs(tx,ty,cur_sum + d[x][y],step+1);  // 带着当前加好的数出去试探
            cout<<1;
        }
    }
    vis[x][y] = 0;
    return;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>d[i][j];
            total_sum += d[i][j];
        }
    }
    dfs(0,0,0,0);
    cout<<ans<<endl;
    return 0;
}