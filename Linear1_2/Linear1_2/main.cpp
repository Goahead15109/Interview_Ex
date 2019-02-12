#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

bool BeSum(vector<int>& nums, int target)
{
	unordered_set<int> appeared;	//构建哈希表（STL中unorder_set使用哈希实现，set使用红黑树实现）
	for (int i = 0; i < nums.size(); ++i) {
		if (appeared.count(target - nums[i]))
			return true;
		appeared.insert(nums[i]);
	}
	return false;
}
int main()
{
	vector<int> nums;
	int n, t;
	cin >> n;	//输入数组元素个数
	for (int i = 0; i < n; ++i)
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