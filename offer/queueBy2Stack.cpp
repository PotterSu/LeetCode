/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

#include "iostream"
#include <stack>

using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int result;
        if(!stack2.empty())
        {
            result = stack2.top();
            stack2.pop();
            return result;
        }
        else
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        result = stack2.top();
        stack2.pop();
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    Solution solution;
    solution.push(1);
    solution.push(2);
    solution.push(3);
    solution.push(4);

    cout << solution.pop() << endl;
    cout << solution.pop() << endl;
    cout << solution.pop() << endl;
    cout << solution.pop() << endl;

	return 0;
}
