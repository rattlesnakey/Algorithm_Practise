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
int n, m, k;
int cache[50][50][15][15];  // cache的意思就是从当前状态到最终能被接受的状态的ans数量有多少
int dfs(int x,int y,int max,int cnt) {//因为max一开始传入进来的是-1,又因为max又代表的是数组的下标，所以要+1，其实我觉得这里一开始把max设成0传入进来也是没什么问题的
	int ans = 0;//每种情况都要单独记
	if (cache[x][y][max+1][cnt] != -1) {//因为max会等于-1所以就对应都右移一步存储
		return cache[x][y][max+1][cnt];
	}
	int cur = arr[x][y];
	if (x == n - 1 && y == m - 1) {
		//这个地方应该包含两种情况，就是达到最后一格以后如果当前max比它大的话也要++
		if ((cur > max&&cnt==k-1)||cnt==k) {
			return 1;//每一种子情况都是return 1
		}
	}

	if (x + 1 <n)
	{
		if (cur > max) {
			ans+=dfs(x + 1, y, cur, cnt + 1);//加上别人return 过来的
		}
		ans+=dfs(x + 1, y, max, cnt);
	}
	if (y + 1 < m)
	{
		if (cur > max) {
			ans+=dfs(x, y+1, cur, cnt + 1);
		}
		ans+=dfs(x, y+1, max, cnt);
	}
	cache[x][y][max + 1][cnt] = ans;//在retrun之前要存到数组里面去
	return ans;
}
int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	cout<<dfs(0, 0, -1, 0);
	return 0;
}
