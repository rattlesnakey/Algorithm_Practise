#include<iostream>
using namespace std;
int ans;
bool Check(int x){
    while(x!=0){
        int cur = x%10;
        x = x/10;
        if(cur == 2 || cur == 4){
            return false;
        }
    }
    return true;
}

// // 题目说的是各不相同
// int main(){
//     for(int i=1;i<2019;i++){
//         if (judge(i)){
//             for(int j=i+1; i+j<2019;j++){
//                 if(judge(j)){
//                     int k = 2019 - i - j;
//                     if (k<=0)continue;
//                     if(k==i || k==j)continue;
//                     if (judge(k))ans++;
//                 }
//             }
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }
int main()
{
    int N = 2019;
    int ans = 0;
    for (int i = 1; i < N / 3; ++i)  //因为是3个递增序列，所以肯定到平均分
        if (Check(i))
            for (int j = i + 1; N - i - j > j; ++j)  // 意思就是我的k也要大于j
                if (Check(j) && Check(N - i - j))
                    ans++;
    cout << ans << endl;
    return 0;
}
