#include<fstream>
#include<iostream>
using namespace std;


int main(int argc, const char* argv[]){
    ifstream fin;
    fin.open("in.txt", ios::in);
    int temp;
    fin>>temp;
    cout<<temp<<endl;
    ifstream fin2("in.txt");
    int temp2;
    fin>>temp2;
    cout<<temp2<<endl;
    
    return 0;
}
