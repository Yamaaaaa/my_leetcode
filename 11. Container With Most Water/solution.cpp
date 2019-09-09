#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxSqu = 0;
		int index = 0;
		int next = -1;

		vector<int> helper(height.size());
		for (int i = 0; i < helper.size(); ++i) {
			helper[i] = i;
		}

		while (helper.size() - index > 1) {
			vector<int> higher;
			int flag = false;

			for (int i = index + 1; i < helper.size(); ++i) {
				if (height[helper[index]] < height[helper[i]]) {
					higher.push_back(helper[i]);
					next = i + 1;
				}
			}

			int i;
			if (higher.size() > 0) {
				int tempSqu = height[helper[index]] * (higher[higher.size() - 1] - helper[index]);
				if (tempSqu > maxSqu) {
					maxSqu = tempSqu;
					flag = true;
				}
				i = next;
			}
			else {
				i = index + 1;
			}

			for (; i < helper.size(); ++i) {
				int tempSqu = height[helper[i]] * (helper[i] - helper[index]);
				if (tempSqu > maxSqu) {
					maxSqu = tempSqu;
					flag = true;
				}
			}

			if (flag) {
				helper = higher;
				index = 0;
			}
			else {
				++index;
			}
		}
		return maxSqu;
	}
};

int main() {
	vector<int> lala{ 68,113,143,194,176,62,158,162,103,75,104,179,189,150,151,180,76,158,158,19,198,42,119,13,127,158,193,59,146,80,41,15,193,184,161,121,198,71,83,102,146,139,33,135,89,184,115,117,142,25,136,93,67,7,106,146,165,100,6,64,180,47,31,125,183,192,46,182,63,129,36,161,68,69,96,110,54,164,27,148,189,116,41,9,123,100,155,89,152,113,153,84,160,184,9,144,128,55,78,143};
	Solution s;
	cout << s.maxArea(lala) << endl;
}