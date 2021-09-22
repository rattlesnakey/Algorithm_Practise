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
int ans;
int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main()
{
	// int fenzi1;
	// int fenzi2;
	// int fenmu1;
	// int fenmu2;
	
	// for (int a = 1; a < 10; a++) {
	// 	for (int b = 1; b < 10; b++) {
	// 		if (a == b) {
	// 			continue;
	// 		}
	// 		for (int c = 1; c < 10; c++) {
	// 			for (int d = 1; d < 10; d++) {
	// 				if (c == d) continue;
	// 				fenzi1 = a * c;
	// 				fenmu1 = b * d;
	// 				stringstream ss;
	// 				//cout << a << b << c << d << endl;
	// 				ss << a<<" "<<b<<" "<<c<<" "<<d;//记得要分开传入要不就会整到一起了
	// 				string a_, b_, c_, d_;
	// 				ss >> a_ >> b_ >> c_ >> d_;//进去什么顺序，出来就是什么顺序，像队列
	// 				//cout << a_ <<" "<< b_ << " " << c_ << " " << d_<<endl;
	// 				//cout<< a_ + c_ <<" "<< b_ + d_<<endl;
	// 				ss.clear();//要记得转换完一次就得clear()
	// 				ss << a_ + c_ <<" "<< b_ + d_;//记得在传入的时候要以空格隔开
	// 				ss >> fenzi2 >> fenmu2;//stringstream 用来将字符串转化为Int
	// 			//	cout << fenzi2 << " " << fenmu2 << endl;
	// 				if (fenzi1 * fenmu2 == fenzi2 * fenmu1) {//如果两个分式相等的话，就满足这个等式
	// 				//	cout << fenzi1 << fenmu1 << fenzi2 << fenmu2 << endl;
	// 					ans++;
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	// cout << ans;
    stringstream ss;
    int a,b,c,d;
    int e,f,g,h;
    string a_, b_,c_,d_;
    //string aa = "1 2 3 4";
    ss<<"1 2 3 4";
    ss>>a>>b>>c>>d;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    ss.clear();
    ss<<1<<" "<<2<<" "<<3<<" "<<4;
    ss>>e>>f>>g>>h;
    cout<<e<<" "<<f<<" "<<g<<" "<<h<<endl;
    ss.clear();
    ss<<1<<" "<<2<<" "<<3<<" "<<4;
    ss>>a_>>b_>>c_>>d_;
    cout<<a_<<" "<<b_<<" "<<c_<<" "<<d_<<endl;
    return 0;
}
