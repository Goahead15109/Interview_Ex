#include<iostream>
#include<vector>

using namespace std;

int FirstOne(vector<int> nums)
{
	int l = 0;
	int r = nums.size() - 1;
	if (nums.empty() || nums[r] == 0)
		return -1;
	while (l < r) {
		int m = l + (r - l) / 2;
		if (nums[m]) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	return l;
}
int main()
{

	cout << FirstOne({ 0,0,0,1,1,1,1 }) << endl;
	cout << FirstOne({ 0,0,0 }) << endl;
	cout << FirstOne({ 1,1,1,1 }) << endl;
	cout << FirstOne({ }) << endl;

	return 0;
}