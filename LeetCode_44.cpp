/*
44.Wildcard Matching

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

解题思路：用dp来解，dp[i][j]表示s的前i个字符串是否与p的前j个字符串匹配
          如果s为空，只需判断p是否为*即可，如果不为*,不用管，如果为*dp[0][i] = dp[0][i-1]
		  如果s不为空，如果p[j]为？或者与s[i]相等，说明当前位一致，只需看dp[i-1][j-1]即可 
		               如果p[j]为*，那么s的前i-1个与p的前j个或者s的前j个与p的前j-1个匹配，那么加上*一定匹配
					   例如:s = abb p = a*
						    s = ab  p = ab* 
							对于当前的i,j位，只要满足dp[i - 1][j] || dp[i][j - 1]一个为true即可
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

