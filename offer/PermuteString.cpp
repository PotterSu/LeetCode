/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/

#include "iostream"
#include <vector>

using namespace std;

void Order(vector<string>& result, string str, string temp, int start)
{
	if(start == str.length())
	{
		result.push_back(temp);
		return;
	}
	//a b c a
	char root = str[start];
	for(int i = start; i < str.length(); i++)
	{
		string stemp = temp;
		if(i > start && str[i] == root)
			continue;
		else
		{
			char t = str[i];
			str[i] = str[start];
			str[start] = t;
			stemp += str[start];
			Order(result, str, stemp, start + 1);
		}
	}
}

vector<string> Permutation(string str)
{
	vector<string> result;
	if(str.length() == 0)
		return result;
	string temp = "";
	Order(result, str, temp, 0);
	return result;
}

int main()
{
	string str = "abca";
	vector<string> result= Permutation(str);
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}

	return 0;
}
