/*
44.Wildcard Matching

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") �� false
isMatch("aa","aa") �� true
isMatch("aaa","aa") �� false
isMatch("aa", "*") �� true
isMatch("aa", "a*") �� true
isMatch("ab", "?*") �� true
isMatch("aab", "c*a*b") �� false

����˼·����dp���⣬dp[i][j]��ʾs��ǰi���ַ����Ƿ���p��ǰj���ַ���ƥ��
          ���sΪ�գ�ֻ���ж�p�Ƿ�Ϊ*���ɣ������Ϊ*,���ùܣ����Ϊ*dp[0][i] = dp[0][i-1]
		  ���s��Ϊ�գ����p[j]Ϊ��������s[i]��ȣ�˵����ǰλһ�£�ֻ�迴dp[i-1][j-1]���� 
		               ���p[j]Ϊ*����ôs��ǰi-1����p��ǰj������s��ǰj����p��ǰj-1��ƥ�䣬��ô����*һ��ƥ��
					   ����:s = abb p = a*
						    s = ab  p = ab* 
							���ڵ�ǰ��i,jλ��ֻҪ����dp[i - 1][j] || dp[i][j - 1]һ��Ϊtrue����
          ���շ���dp[sl][pl]

*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

bool isMatch(string s, string p) {
	int sl = s.length();
	int pl = p.length();
	vector<vector<bool>> dp(sl + 1, vector<bool>(pl + 1, false));//3 2
	dp[0][0] = true;
	for (int i = 1; i <= pl; i++)
		if (p[i - 1] == '*')
			dp[0][i] = dp[0][i - 1];
	for (int i = 1; i <= sl; i++)
	{
		for (int j = 1; j <= pl; j++)
		{
			if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
				dp[i][j] = dp[i - 1][j - 1];
			if (p[j - 1] == '*')
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
		}
	}
	return dp[sl][pl];
}

int main()
{
	string s = "abb";//ab
	string p = "a*"; //ab*
	bool temp = isMatch(s, p);
	cout << temp << endl;
	while (1);
	return 0;
}

