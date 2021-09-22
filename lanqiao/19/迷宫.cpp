#include<iostream>
#include<queue>
#include<string>
using namespace std;
int n,m;
char map[100][100];
int min_step = 1000000;
int vis[100][100];
struct point{
    int x,y;
    int step;
    string ans;
    point(int xx, int yy, int s, string a):x(xx), y(yy), step(s), ans(a){};

};
queue<point > a;
int dir[4][2] = {{1,0},{0,-1},{0,1},{-1,0}};  // 方向别搞反了
string path[4] = {"D","L","R","U"};
string final_ans;
int bfs(int x, int y, int step){
    a.push(point(0,0,step,""));
    while(!a.empty()){
        int cur_x = a.front().x;
        int cur_y = a.front().y;
        int cur_step = a.front().step;
        string cur_ans = a.front().ans;
        a.pop();
        vis[cur_x][cur_y] = 1;
        if (cur_x==3&&cur_y==5){
            if(cur_step<min_step){
                min_step = cur_step;
                final_ans = cur_ans;
            }
        }
        for(int i=0;i<4;i++){
            int tx = cur_x + dir[i][0];
            int ty = cur_y + dir[i][1];
            if (tx>=0 && tx<=n-1 && ty >=0 && ty<=m-1 &&map[tx][ty]!='1' && !vis[tx][ty]){
                a.push(point(tx,ty,cur_step+1,cur_ans+path[i]));
            }
        }
    }
    return min_step;
}

int main(){
    freopen("maze.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%s",map[i]);
    }
    int step = bfs(0,0,0);
    cout<<step<<endl;
    cout<<final_ans<<endl;
}

 
// // FILE *p = fopen("","r");

// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <queue>
// using namespace std;

// const int maxn = 55;
// char g[maxn][maxn];
// bool vis[maxn][maxn];
// string ans;
// int n, m;

// struct point
// {
//     int x, y;
//     string path;
//     point(int _x, int _y, string _path)
//     {
//         x = _x;
//         y = _y;
//         path = _path;
//     }
//     point() {}
// };

// int Next[4][2] = {1, 0, 0, -1, 0, 1, -1, 0};
// char ops[5] = {'D', 'L', 'R', 'U'};

// void bfs()
// {
//     queue<point> Q;
//     Q.push(point(0, 0, ""));
//     while (!Q.empty())
//     {
//         point head = Q.front();
//         Q.pop();
//         int x = head.x;
//         int y = head.y;
//         string path = head.path;
//         for (int k = 0; k < 4; k++)
//         {
//             int nx = x + Next[k][0];
//             int ny = y + Next[k][1];
//             if (nx == n - 1 && ny == m - 1)
//             {
//                 ans = path + ops[k];
//                 return;
//             }
//             if (g[nx][ny]=='0' && !vis[nx][ny] && nx < n && ny < m && nx >= 0 && ny >= 0)
//             {
//                 vis[nx][ny] = 1;
//                 Q.push(point(nx, ny, path + ops[k]));
//             }
//         }
//     }
// }

// int main()
// {
// 	// freopen("maze.txt", "r", stdin);  // freopen 最后要有stdin, 这样就相当于把所有的东西都给stdin了
//     // n = 30;
//     // m = 50;
//     cin >>n>>m;
//     for (int i = 0; i < n; i++)
//         scanf("%s", g[i]);
//     bfs();
//     cout << ans << endl;
//     return 0;
// }
