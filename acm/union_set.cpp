#include <iostream>
#include <set>
using namespace std;
struct node  
{
    int col;
    int row;
} fg[1001];  // 有1000个点
int pre[1002];  //下标是孩子，数组里面的内容是父亲
int cnt=0;  // 有几个炸弹
int findpre(int n)  //寻找该炸弹的最大boss
{
    while(pre[n]!=n)  // 最顶层的，他们的父亲就是他们自己本身
    {
        n=pre[n];
    }
    return n;
}
void join(int n)
{
    int c=fg[n].col,r=fg[n].row;  // 当前炸弹所在的行和列
    int father=findpre(n);  // 当前炸弹的最顶的boss
    for(int i=0; i<cnt; i++)
    {
        if(fg[i].col==c) // 同列的炸弹的最大boss都被赋值为这个boss
        {
            pre[findpre(i)]=father;
        }
        if(fg[i].row==r)  // 同行的炸弹的最大boss指向该炸弹的最大boss
        {
            pre[findpre(i)]=father;
        }
    }
}
int main()
{
    char str[1002];
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>str;  // 每一行都是一个临时的str数组来存放
        for(int j=0; j<m; j++)
        {
            if(str[j]=='1') // 记录每个炸弹的行和列
            {
                fg[cnt].row=i;
                fg[cnt].col=j;
                cnt++;
            }
        }
    }

    for(int i=0; i<n*m; i++)  // 每个节点的祖先都先赋值成它自己
        pre[i] = i;
    for(int i=0; i<cnt; i++)
    {
        join(i);  // 把与当前炸弹同行同列的炸弹的父亲都赋值成当前这个炸弹的父亲
    }
//    for(int i=0;i<cnt;i++)
//        cout<<"第"<<i<<"的直接boss是"<<findpre(i)<<endl;
//    for(int i=0;i<cnt;i++)
//        cout<<"第"<<i<<"的最大boss是"<<findpre(i)<<endl;
    set<int> s;
    for(int i=0; i<cnt; i++)  // 最后再看下到底有多少个不同的最大的boss
    {
        s.insert(findpre(i));
    }
    cout<<s.size()<<endl;
}
