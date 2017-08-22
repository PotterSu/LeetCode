/*
10.Regular Expression Matching

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

解题思路：用dp来解，dp[i][j]表示s的前i个字符串是否与p的前j个字符串匹配
          如果s为空，只需判断p是否为*即可，如果不为*,不用管，如果为*dp[0][i] = dp[0][i-2]
		  如果s不为空，如果p[j]为.或者与s[i]相等，说明当前位一致，只需看dp[i-1][j-1]即可 
		               如果p[j]为*，有两种情况
					   1.p[j-1]!=s[i]或者p[j-1]!='.'，那么只需要判断p的前j-2位是否与s的前i位匹配即可，此时*为0
					   2.p[j-1]==s[i]或者p[j-1]=='.'，那么需要看p的前j-2位是否与s的前i位相等
													  或者p的前j-1位是否与s的前i位相等或者
													  或者p的前j位是否与s的前i-1位匹配
          最终返回dp[sl][pl]
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
	vector<vector<bool>> dp(sl + 1, vector<bool>(pl + 1, false));
	dp[0][0] = true;
	for (int i = 1; i <= pl; i++)
	{
		if (p[i - 1] == '*')
		{
			dp[0][i] = dp[0][i - 2 >= 0 ? i - 2 : 0];
		}
	}
	for (int i = 1; i <= sl; i++)
	{
		for (int j = 1; j <= pl; j++)
		{
			if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			if (p[j - 1] == '*')
			{
				if (p[j - 2 >= 0 ? j - 2 : 0] != s[i - 1] && p[j - 2 >= 0 ? j - 2 : 0] != '.')
					dp[i][j] = dp[i][j - 2 >= 0 ? j - 2 : 0];
				else{
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2 >= 0 ? j - 2 : 0];
				}
			}

		}

	}
	return dp[sl][pl];
}

int main()
{
	string s = "aaaaa";
	string p = "*";
	bool temp = isMatch(s, p);
	cout << temp << endl;
	while (1);
	return 0;
}
