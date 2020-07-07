#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:

	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result(2);
		vector<int> mid(nums);
		sort(mid.begin(), mid.end());
		int i = 0, j = mid.size()-1;
		int temp;
		while (i < j ) {
			temp = mid[i] + mid[j];
			if (temp < target)
				i++;
			else if (temp > target)
				j--;
			else
				break;
		}
		bool first = false;
		if (mid[i] <= mid[j])
		{
			for (int k = 0; k < nums.size(); k++) {
				if (nums[k] == mid[i] && !first) {
					result[0] = k;
					first = true;
				}
				if (nums[k] == mid[j])
					result[1] = k;
			}
		}
		else {
			for (int k = 0; k < nums.size(); k++) {
				if (nums[k] == mid[j] && !first) {
					result[0] = k;
					first = true;
				}
				if (nums[k] == mid[i])
					result[1] = k;
			}
		}
		return result;
	}
private:
	
};
int main()
{
	int num, temp;
	cin >> num;
	vector<int> nums;
	for (int i = 0; i < num; i++)
	{
		cin >> temp;
		nums.emplace_back(temp);
	}
	int target;
	cin >> target;
	Solution sol;
	vector<int> re = sol.twoSum(nums, target);
	for (int i = 0; i < 2; i++)
		cout << re[i] << " ";
	return 0;
}