#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <deque>
#include <string>

using namespace std;

class Solution {
public:
	static string longestPalindrome(string s) {
		if (s.length() <= 1) return s;
		int rbegin = 0;
		int rend = -1;
		bool flag = true;
		unordered_map<char, vector<int>> lm;
		for (int i = 0; i < s.length(); ++i) {
			lm[s[i]].push_back(i);
			flag = true;
			for (int j = 0; j < lm[s[i]].size() - 1; ++j) {
				int begin = lm[s[i]][j];
				int end = i;
				if (end - begin > rend - rbegin) {
					while (s[begin] == s[end]) {
						if (end - begin <= 1) {
							rbegin = lm[s[i]][j];
							rend = i;
							flag = false;
							break;
						}
						++begin;
						--end;
					}
					if (!flag)
						break;
				}
			}
		}
		if (rend == -1)
			return s.substr(0, 1);
		return s.substr(rbegin, rend - rbegin + 1);
	}
};

int main() {
	string s = "babad";
	cout << "result = " << Solution::longestPalindrome("babad");
	char c;
	cin >> c;
}

//https://leetcode.com/submissions/detail/224195150/
//the defferent between me and other answer is that they begin with center
//because Palindromic Substring is little, their runtime is faster than mine