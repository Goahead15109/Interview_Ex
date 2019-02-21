#include<iostream>
#include<vector>

using namespace std;

struct Solution {
	vector<int> memo;
	Solution() {
		memo.assign(1000, -1);
		memo[0] = 0;
		memo[1] = 1;
	}

	int F1(int n) {	//备忘模型：未知-->已知
		if (memo[n] == -1)
			return F1(n - 1) + F1(n - 2);
		return memo[n];
	}

	int F2(int n) {	//演绎模型：已知-->未知
		for (int i = 2; i <= n; ++i) {
			memo[i] = memo[i - 1] + memo[i - 2];
		}
		return memo[n];
	}
};
int main()
{
	Solution solution;
	cout << solution.F1(15) << endl;
	cout << solution.F2(15) << endl;
	return 0;
}