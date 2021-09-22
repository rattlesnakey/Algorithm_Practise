#include<iostream>
#include<sstream>
#include<string>
using namespace std;
string judge(string x){
	if (x.size()==2){
		return x;
	}
	else{
		return "0"+x;	
	}
}

int main(){
	long long x;
	cin >>x;
	long long s = x/1000;
	int ss = s%60;
	long long m = s/60;
	int mm = m%60;
	long long h = m /60;
	int hh = h%24;
	stringstream sss;
	string s_;
	sss<<ss;
	sss>>s_; 
	string s__ = judge(s_);
	stringstream aaa;
	aaa<<mm;
	string m_;
	aaa>>m_;
	string m__ = judge(m_);
	stringstream ccc;
	ccc << hh; 
	string h_;
	ccc >> h_;
	string h__ = judge(h_);
	 
	
	cout<<h__<<":"<<m__<<":"<<s__;
	return 0;
}
