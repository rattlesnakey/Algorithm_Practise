#include<iostream>
#include<cstdio>
using namespace std;
int n;
int m;
char temp;
char maze[100][100];
int ans;
int visx[100];  // 用来看查看这行是不是引爆过了
int visy[100];  // 用来看查看这列是不是引爆过了
void dfs(int x, int y){
    if(!visy[y]){
        visy[y] = 1;
        for(int i=0;i<n;i++){
        if (maze[i][y] == '1'){
            maze[i][y] = '0';
            dfs(i,y);
        }
    }
    }
    if (!visx[x]){
        visx[x] = 1;
        for(int j=0;j<m;j++){
        if(maze[x][j] == '1'){
            maze[x][j] = '0';
            dfs(x,j);
        }
    }
    }
}
int main(){
    cin>>n>>m;
    for (int i=0;i<n;i++){
        scanf("%s",maze[i]);
    }
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (maze[i][j] == '1'){  // 每一轮都进去，把能扫盲的全部都扫一边
                dfs(i,j);  // 因为maze是全局的，所以相当于是进去大扫除一波
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}