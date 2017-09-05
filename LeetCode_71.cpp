/*
71. Simplify Path

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

解题思路：以/分割字符串，当分割的片段为/. /空格时不处理
                         当分割的片段为/*（*为除了. 空格 ..的字符）时，将/*压入栈
						 当分割的片段为/..栈弹出一次
		  注意判断尾部，如果最后剩了/*要压入栈
		                如果最后剩了/..栈弹出一次
						如果最后剩了栈为空，压入/
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

string simplifyPath(string path) {
	if (path == "/")
		return "/";
	string temp = "/";
	stack<string> st;
	for (int i = 0; i < path.length(); i++)
	{
		if (path[i] == '/'&&temp != "/.."&&temp != "/ "&&temp != "/."&&temp != "/")
		{
			st.push(temp);
			temp = "/";
		}
		if (path[i] == '/' && (temp == "/ " || temp == "/."))
		{
			temp = "/";
		}
		if (path[i] == '/'&&temp == "/..")
		{
			temp = "/";
			if (!st.empty())
				st.pop();
		}
		if (path[i] != '/')
		{
			temp += path[i];
		}
	}
	if (temp != "/.."&&temp != "/ "&&temp != "/."&&temp != "/")
		st.push(temp);
	if (temp == "/.."&&!st.empty())
		st.pop();
	if (st.empty())
		st.push("/");
	string result;
	while (!st.empty())
	{
		result = st.top() + result;
		st.pop();
	}
	return result;
}

int main()
{
	string result = simplifyPath("///abc/..");
	cout << result << endl;
	while (1);
	return 0;
}
