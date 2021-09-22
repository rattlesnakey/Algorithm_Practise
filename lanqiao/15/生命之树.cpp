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
const int maxn = 1e5;
int n;
int w[maxn+1];
vector<int > edge[maxn + 1];
int dfs(int root, int father) {
	int ans_temp=0;//每一层返回一个数值
	ans_temp += w[root];
	for (int i = 0; i < edge[root].size(); i++) {
		if (edge[root][i] != father) {//只有有边才能往下走(这边是取出该节点所有邻接的点，应该是不要成环)
			int son = edge[root][i];
			if (dfs(son, root) > 0) {//只有大于0才能加上去, 就算是连通的结点，也必须是大于0我才加上去
				ans_temp += dfs(son, root);  // 该层加上上一层返回的值就可以了
			}
		}
	}
	return ans_temp;  // 每一层返回自己的一个值
}
int main()
{
	int x, y;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		edge[x].push_back(y);//每个点只链接一个点，所以一维数组就可以
		edge[y].push_back(x);
	}
	int final_ans = 0;
	for (int i = 1; i <= n; i++) {//dfs就是去求一个树的最大和罢了
		final_ans = max(dfs(i, 0), final_ans);//算以每个顶点为根的最大的和，然后再多棵树里面再求最大
	}
    // dfs一次就是相当于进去里面遍历一次，其实本质上就是得到一个连通的部分
	cout << final_ans;
	return 0;
		
}

