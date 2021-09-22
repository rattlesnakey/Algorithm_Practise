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
bool conflict[7][7];
const int mod = 1000000007;
int up[7];
void init() {
	up[1] = 4;
	up[2] = 5;
	up[3] = 6;
	up[4] = 1;
	up[5] = 2;
	up[6] = 3;
}
int n, m;
int dp[2][7];//滚动数组，每次只要两行的数据
int main()
{
	init();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		conflict[x][y] = true;
		conflict[y][x] = true;//注意是相对的
	}
	for (int i = 1; i <= 6; i++) {
		dp[0][i] = 1;//先不考虑每次4个
	} // 初始化
	int cur = 0;
	for (int level = 2; level <= n; level++) {
		cur = 1 - cur;//考虑另一层
		for (int j = 1; j <= 6; j++) {
			dp[cur][j] = 0;
			for (int i = 1; i <= 6; i++) {
				if (conflict[up[j]][i])continue;//conflict这里要ip
				dp[cur][j] = (dp[cur][j] + dp[1 - cur][i]) % mod;
			}
		}
	}
	long long sum = 0;
	for (int i = 1; i <= 6; i++) {
		sum =(sum+ dp[cur][i])%mod;  // 把最后的那一层全部加起来
	}
	long long ans = 1;
	long long temp = 4;
	long long p = n;
	while (p != 0) {
		if ((p & 1)==1)ans = (ans * temp)%mod;//1代表是要包括进来的
		
			temp = (temp * temp) % mod;//每移一次就乘一次，来记录temp
			p >>= 1;
		
	}
	cout << ans * sum;  // 最后再乘以4的n次方
	return 0;
}
