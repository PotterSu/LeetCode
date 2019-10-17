/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true
 */

#include "iostream"
#include "vector"
#include "string"
#include "stack"

using namespace std;

bool isValid(string s)
{
    //字符串为0
    if(s.length() == 0)
    {
        return true;
    }
    //字符串奇数
    if(s.length() % 2 != 0)
    {
        return false;
    }
    stack<char> s_stack;
    for(int i =0; i < s.length(); i++)
    {
        if(s[i] == ')' && !s_stack.empty() && s_stack.top() == '(')
        {
            cout << "pop" << s_stack.top() << endl;
            s_stack.pop();
            continue;
        }
        if(s[i] == ']' && !s_stack.empty() && s_stack.top() == '[')
        {
            cout << "pop" << s_stack.top() << endl;
            s_stack.pop();
            continue;
        }
        if(s[i] == '}' && !s_stack.empty() && s_stack.top() == '{')
        {
            cout << "pop" << s_stack.top() << endl;
            s_stack.pop();
            continue;
        }

        s_stack.push(s[i]);
        cout << "push" << s[i] << endl;
    }
    if(!s_stack.empty())
    {
        return false;
    }

    return true;

}

int main()
{
    string s;
    cin >> s;

    bool result = isValid(s);
    cout << result << endl;

	return 0;
}
