#include <vector>
#include <iostream>
#include <string>
//#define ONE "I"
//#define FIVE "V"
//#define TEN "X"
//#define FIFTY "L"
//#define HUNDRED "C"
//#define FH "D"
//#define THOUSANT "M"

using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string result = "";
		vector<vector<char>> number{ {'I', 'V', 'X'},{'X','L','C'},{'C','D', 'M' },{'M'} };
		int count = 0;

		while (num > 0) {
			int temp = num % 10;
			num /= 10;
			if (temp == 9) {
				result = number[count][2] + result;
				result = number[count][0] + result;
			}
			else if (temp >= 5) {
				for (int i = 0; i < temp - 5; ++i) {
					result = number[count][0] + result;
				}
				result = number[count][1] + result;
			}
			else if (temp == 4) {
				result = number[count][1] + result;
				result = number[count][0] + result;
			}
			else {
				for (int i = 0; i < temp; ++i) {
					result = number[count][0] + result;
				}
			}
			++count;
		}
		return result;
	}
};

//int main() {
//	Solution s;
//	cout << s.intToRoman(1994) << endl;
//}