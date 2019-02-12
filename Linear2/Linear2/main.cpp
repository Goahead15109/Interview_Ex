#include<iostream>
#include<vector>

using namespace std;

void MergeArray(vector<int>& nums1, int length1, vector<int>& nums2, int length2)
{
	int pos1 = length1 - 1;
	int pos2 = length2 - 1;
	int last = nums1.size() - 1;
	while (last >= 0) {
		if (pos1<0 || pos2>=0 && nums1[pos1]<nums2[pos2]) {
			nums1[last--] = nums2[pos2--];
		}
		else {
			nums1[last--] = nums1[pos1--];
		}
	}
}
int main()
{
	vector<int> nums1{ 1,2,3,0,0,0 };
	vector<int> nums2{ 4,5,6 };
	MergeArray(nums1, 3, nums2, 3);
	for (int i = 0; i < nums1.size(); ++i)
		cout << nums1[i] << " ";
	cout << endl;
	return 0;
}