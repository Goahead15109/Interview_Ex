#include<iostream>
#include<vector>

using namespace std;

//备忘模型
int GetMemo(vector<int>& coins,vector<int>& memo, int target)
{
	if (memo[target] == -2) {
		int result = -1;
		for (int coin : coins) {
			if (coin <= target) {
				int temp = GetMemo(coins, memo, target - coin);
				if (temp != -1 && (result == -1 || temp + 1 < result))
					result = temp + 1;
			}
		}
		memo[target] = result;
	}
	return memo[target];
}
int GetCoins(vector<int>& coins,int target)
{
	vector<int> memo(target + 1, -2);	//-2表示未计算，-1表示无解
	memo[0] = 0;
	return GetMemo(coins,memo, target);
}

//演绎模型
int GetCoins1(vector<int>& coins, int target)
{
	vector<int> memo(target + 1);
	memo[0] = 0;

	for (int i = 1; i < memo.size(); ++i) {
		int result = -1;
		for (int coin : coins) {
			if (coin <= i) {
				int temp = memo[i - coin];
				if (temp != -1 && (result == -1 || result > temp + 1))
					result = temp + 1;
			}
		}
		memo[i] = result;
	}
	return memo[target];
}

int main()
{
	vector<int> coins({ 1,2,3,4 });
	vector<int> coins1({ 1,5,11 });
	cout << GetCoins(coins1, 20) << endl;
	cout << GetCoins1(coins1, 20) << endl;
	return 0;
}