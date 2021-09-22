#include<iostream>
#include<string.h>
using namespace std;
int ans;
// void dfs(int sum, int dian, int hua){
//     if (dian == 0 && hua - 1 == 0 && sum - 1 == 0){
//         ans++;
//         return;
//     }
//     if (dian < 0 || hua < 0) return;
//     dfs(sum + sum, dian-1, hua);
//     dfs(sum - 1, dian, hua - 1);

// }
void dfs(int dian, int hua, int jiu) {
	if (dian == 0 && hua == 0 && jiu == 1) {//jiu等于1相当于就是最后一次遇到花
		ans++;
	}
	if (dian > 0) {
		dfs(dian - 1, hua, jiu * 2);
	}
	if (hua > 0&&jiu-1>=1) {//jiu-1还要大于等于1才可以
		dfs(dian, hua - 1, jiu - 1);
	}
}
int main(){

    // dfs(2, 5, 10);
    // dfs(5,9,2);
    // cout<< ans;
    char dest[100];  // 一定要显示的定义出来
    char src[] = "apple"; // 这样才可以
    // strcpy(dest, src);
    strncpy(dest, src, 3);  // 看要从开头复制几位过来
    cout<<dest;
    return 0;
}