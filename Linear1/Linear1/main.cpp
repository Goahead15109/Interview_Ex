#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool BeSum(vector<int>& nums, int target)
{
	sort(nums.begin(), nums.end());	//对数组排序
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] > target)	//如果当前元素大于target，后面元素也必定大于target
			break;
		bool b = binary_search(nums.begin() + i + 1, nums.end(), target-nums[i]);	//对后面元素二分查找
		if (b)
			return true;
	}
	return false;
}
int main()
{
	vector<int> nums;
	int n,t;	
	cin >> n;	//输入数组元素个数
	for(int i = 0; i < n; ++i)
	{
		cin >> t;
		nums.push_back(t);
	}
	int target;	
	cin >> target;

	if (BeSum(nums, target))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}