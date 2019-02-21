#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int GetMemo(int id, vector<int>& memo, vector<int>& houses)
{
	if (id >= memo.size())
		return 0;
	if (memo[id] == -1) {
		int selectFirstElement = houses[id] + GetMemo(id + 2,memo,houses);
		int unselectFirstElement = GetMemo(id + 1, memo, houses);
		memo[id] = max(selectFirstElement, unselectFirstElement);
	}
	return memo[id];
}
int GetGlod(vector<int>& houses)
{
	vector<int> memo(houses.size(), -1);	//memo是从第id房间到最后一房间能偷到的最大金子价值
	return GetMemo(0, memo, houses);
}
int main()
{
	vector<int> houses({ 3,5,2,10 });
	cout << GetGlod(houses) << endl;
	return 0;
}