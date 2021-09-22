#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<cmath>
using namespace std;
int arr[50][50];
int ans;
int n, m, k;
void dfs(int x,int y,int max,int cnt) {
	int cur = arr[x][y];
	if (x == n - 1 && y == m - 1) {
		//这个地方应该包含两种情况，就是达到最后一格以后如果当前max比它大的话也要++
		if (cur > max&&cnt==k-1) {
			ans++;
		}
		if (cnt == k) {
			ans++;
		}
		return;
	}

	if (x + 1 <n)  // 先看看能不能走
	{
		if (cur > max) {
			dfs(x + 1, y, cur, cnt + 1);
		}
		dfs(x + 1, y, max, cnt);  // if 执行完也是会出来执行这条语句的
	}
	if (y + 1 < m)
	{
		if (cur > max) {
			dfs(x, y+1, cur, cnt + 1);
		}
		dfs(x, y+1, max, cnt);
	}

}
int main()
{

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 0, -1, 0);  // x,y,cur_max,cnt
	cout << ans;
	return 0;
}
