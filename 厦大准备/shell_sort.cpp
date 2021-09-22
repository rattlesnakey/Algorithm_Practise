#include <stdio.h>
#include <math.h>
#include<iostream>
using namespace std;
void shellsort(int A[], int n){
    int dk;
    int i;
    int j;
    for(dk=n/2;dk>=1;dk=dk/2){  // 间隔
        for(i=dk;i<=n;i++){  // 当前i的位置就是待排序的元素
            if(A[i]<A[i-dk]){
                A[0]=A[i];
                // 首先把位置不对的值拿出来暂时放在A[0]
                // 从上一个位置开始遍历
                for(j=i-dk;j>0&&A[0]<A[j];j-=dk){ // 这边其实就是相当于是遍历有序的子序列，只不过子序列里面相邻的元素在原来元素的下角标差dk
                //  这边的这些dk其实都可以理解为-1
                    //  只要比A0大的都往后挪
                    A[j+dk]=A[j];
                }
                A[j+dk] = A[0];
            }
        }
    }
    for(i=1;i<=n;i++){
        printf("%d ", A[i]);
    }
}


void ShellSort(int iRawBuff[], int len)
{
	int gap = len/ 2;//初始增量为数组长度的一半
	while (1 <= gap) 
	{
		for (int i = gap; i < len ; i++) 
		{
            int j = 0;  // 主要是用来初始化的，没其他作用
			int temp = iRawBuff[i];
			for (j = i - gap; j >= 0 && temp < iRawBuff[j]; j = j - gap)
			{
				iRawBuff[j + gap] = iRawBuff[j];
			}
			iRawBuff[j + gap] = temp;
		}
		gap = gap / 2; 
	}
	for (int k = 0; k < len; k++)
	{
		cout << iRawBuff[k] << "   ";
	}
	cout << endl;
}
int main(){
    int a[] = {0,7,6,5,4,3,2,1};
    shellsort(a,7);
    return 0;
}