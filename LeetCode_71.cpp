/*
71. Simplify Path

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

����˼·����/�ָ��ַ��������ָ��Ƭ��Ϊ/. /�ո�ʱ������
                         ���ָ��Ƭ��Ϊ/*��*Ϊ����. �ո� ..���ַ���ʱ����/*ѹ��ջ
						 ���ָ��Ƭ��Ϊ/..ջ����һ��
		  ע���ж�β����������ʣ��/*Ҫѹ��ջ
		                ������ʣ��/..ջ����һ��
						������ʣ��ջΪ�գ�ѹ��/
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
