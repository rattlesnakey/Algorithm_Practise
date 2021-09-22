#include<iostream>
#include<cmath>
using namespace std;

int map[5][6];
bool used[10];
int ans;
bool check(int x, int y){
    for(int i=x-1;i<=x+1;i++){
        for(int j=y-1;j<=y+1;j++){
            if (abs(map[i][j]-map[x][y]) == 1){
                return false;
            }
        }
    }
    return true;
}

void dfs(int row, int col){
    if(row == 3 && col == 4){  // 每一行都是从左往右放的，我只要放到3，3就行了，所以3，4是结束的地方
        ans++;
        return;
    }
    for(int i=0;i<10;i++){
        if (!used[i]){
            map[row][col] = i;  
            if(check(row,col)){
                used[i] = true;
                if (col == 4){
                    dfs(row+1, 1);
                }
                else{
                    dfs(row,col+1);
                }
            }
            map[row][col] = -10;  // 感觉其实可以不用放，但是答案不一样
            used[i] = false;  // 我下一波要换一个数用了
        }
    }
}
int main(){
    int size = sizeof(int);
    int point_size = sizeof(int *);
    // memset(map,-1,sizeof(map));
    // memset(map, -10, point_size*5 + size*5*6); 好像就是赋值不了-10，只能赋值-1才行
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            map[i][j] = -10;
        }
    }
    dfs(1,2);
    cout<<ans;
    return 0;
}