#include<iostream>
#include<set>
using namespace std;
int x[21] = {0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0,13.0,14.0,15.0,16.0,17.0,18.0,19.0};
int y[22] = {0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0,13.0,14.0,15.0,16.0,17.0,18.0,19.0,20.0};
struct point{
	int x;
	int y;
	point(int xx, int yy):x(xx),y(yy){};
}
struct line{
	float a;
	float b;
	line(float x, float y):a(x),b(y){};
};
set<line> s;
int main(){
	for(int i=0;i<20;i++){
		for(int j=0;j<21;j++){
			line()
		}
	}
	return 0;
}
