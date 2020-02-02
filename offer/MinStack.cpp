/*
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

#include "iostream"
#include <vector>
#include <stack>

using namespace std;

stack<int> s1;
stack<int> s2;
int minNumber;

void push(int value)
{
    if(s1.size() == 0)
    {
        minNumber = value;
    }
    s1.push(value);
    if(value <= minNumber)
    {
         s2.push(value);
         minNumber = value;
    }
    else
        s2.push(minNumber);
}

void pop()
{
    s1.pop();
    s2.pop();
}

int top()
{
    return s1.top();
}

int min()
{
    return s2.top();
}

int main()
{
    push(1);
    push(2);
    push(0);

    pop();
	int result = min();
    cout << result << endl;

	return 0;
}
