/*
58. Length of Last Word

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.

����˼·���ַ������ײ���ʼ�����������Ϊ�ո���ôcount++,result = count,
          ���Ϊ�ո�count = 0��������result
		  ���շ���result
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

int lengthOfLastWord(string s) {
	int count = 0;
	int result = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ')
		{
			count++;
			result = count;
		}
		else{
			count = 0;
		}
	}
	return result;
}

int main()
{
	int result = 0;
	result = lengthOfLastWord("s bb kkk   ");
	cout << result << endl;
	while (1);
	return 0;
}

