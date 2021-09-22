#include<iostream>
using namespace std;

typedef struct node //栈的结点结构
{
	int data;
	struct node *next;
}*Link;
typedef struct{ //栈顶作链表的头部
	Link top;
}*Stack;
 
Stack init_stack(); // 定义栈
int push_stack(Stack s,int x); // 变量x入栈
int pop_stack(Stack s,int &x); // 出栈顶元素到x
int pop_push(Stack sa,Stack sb); //栈sa出栈一次，数据入栈到sb
void hanoi(int n,Stack sa,Stack sb,Stack sc); //把sa栈顶的n个元素按顺序放到栈sc中
 
int main()
{
	int n;
	scanf("%d", &n); // 汉诺塔的层数
	Stack sa = init_stack();
	Stack sb = init_stack();
	Stack sc = init_stack();
	while(n-->0) // 初始化栈sa，代表最左边柱子和盘子
	{ push_stack(sa,n); }
	hanoi(n,sa,sb,sc); 
}
void hanoi(int n,Stack sa,Stack sb,Stack sc)
{
	if(n == 1) // 盘子数为1
		pop_push(sa,sc);
	else
	{
		hanoi(n-1,sa,sc,sb); // 将栈sa的n-1个盘子顺序移到栈sb
		pop_push(sa,sc); // 将栈sa的第n个盘子移到栈sc
		hanoi(n-1,sb,sa,sc); // 将栈sb的n-1个盘子顺序移到栈sc
	}
}
int pop_push(Stack sa,Stack sb)
{
	int x;
	if(sa->top == NULL)
	{
		printf("栈空");
		return 0;
	}
	else
	{
	pop_stack(sa,x); // 栈sa出栈
	push_stack(sb,x); // 栈sb入栈
	return 1;
	}
}