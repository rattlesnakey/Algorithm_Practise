#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;
int i;

int aa;
int main(){
    string str = "123456789";
    int n;
    cin >>n;
    int ans = 0;
    do{
        for(int i=1;i<=7;i++){
            string a = str.substr(0,i); // 表示以0开始(闭),向后取i位
            aa = atoi(a.c_str());  // c_str记得加括号  # stoi在cstring里
            if (aa >= n){
                break;
            }
        }
        for (int j=1;j<=9-i-1;j++){  // 最起码还要留一位给分母
            string b = str.substr(i,j);
            int intb = atoi(b.c_str());
            string c = str.substr(i+j);  // i+j为起点，后面所有的元素
            int intc = atoi(c.c_str());
            if (intb %intc == 0 && aa + intb / intc == n) ans++;
        }   
    }while(next_permutation(str.begin(),str.end()));  // 这边记得加分号, permutation没有s
    cout<<ans;
    return 0;
}


// 上面那个有问题
// #include<iostream>
// #include<fstream>
// #include<sstream>
// #include<algorithm>
// #include<cstdlib>
// #include<string>
// #include<set>
// #include<vector>
// using namespace std;
// int main()
// {
// 	int n;
// 	cin >> n;
// 	int ans = 0;
// 	string s = "123456789";
// 	do {
// 		for (int i = 1; i <= 7; i++) {
// 			string a = s.substr(0, i);//起点是开（数字的左边有条杠），i是个数
// 			int inta = atoi(a.c_str());
// 			if (inta >= n) {
// 				break;
// 			}
// 			for (int j = 1; j <= 9 - i - 1; j++) {
// 				string b = s.substr(i, j);//左闭右开
// 				int intb = atoi(b.c_str());//数组到int,首先要把string->数组c_str()也就是c语言的数组
// 				string c = s.substr(i + j);
// 				int intc = atoi(c.c_str());
// 				if (intb % intc == 0 && inta + intb / intc == n)ans++;
// 			}
// 		}
		
// 	} while (next_permutation(s.begin(), s.end()));

// 	cout << ans;
// 	return 0;
// }

