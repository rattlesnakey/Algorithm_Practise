#include<iostream>
#include<vector>
int maze[100][100] = {0};
int vis[100][100] = {0};
int ans = 100000;
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n, m;
bool in(int x, int y){
    return x>=0 && x<=n-1 && y>=0 && y<=m-1;
}
void dfs(int x, int y, int step){
    if (maze[x][y] == 'T'){
        if (step<ans){
            ans = step;
        }
        return;
    }

    vis[x][y] = 1;
    for (int i=0;i<4;i++){
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (in(tx,ty)){
            dfs(tx,ty,step+1);
        }
    }
    vis[x][y] = 1
    return;
}


int main(int argc, char *argv[]){
    int x,y;
    scanf("%d %d",x,y);
    return 0;
}