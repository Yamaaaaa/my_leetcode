class Solution {
public:
	string convert(string s, int numRows) {
		if (s.length() <= 1) return s;
		string ns[numRows];
		int current = 0;
		while (true) {
			for (int i = 0; i < numRows; ++i) {
				ns[i] += s[current++];
				if (current == s.size()) {
					string result;
					for (int j = 0; j < numRows; ++j) {
						result += ns[j];
					}
					return result;
				}
			}
			for (int i = numRows - 2; i > 0; --i) {
				ns[i] += s[current++];
				if (current == s.size()) {
					string result;
					for (int j = 0; j < numRows; ++j) {
						result += ns[j];
					}
					return result;
				}
			}
		}
	}
};

//Runtime: 16 ms, faster than 90.50% of C++ online submissions for ZigZag Conversion.
//Memory Usage: 10.3 MB, less than 99.79% of C++ online submissions for ZigZag Conversion.