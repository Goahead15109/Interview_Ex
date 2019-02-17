#include<iostream>
#include<vector>

using namespace std;

void PreOrder(vector<int>& root, int rt)
{
	if (rt < root.size() && root[rt] != -1) {
		cout << root[rt] << " ";
		PreOrder(root, 2 * rt + 1);
		PreOrder(root, 2 * rt + 2);
	}
}
int main()
{
	vector<int> root({ 1,2,3,-1,4,5,6 });
	PreOrder(root, 0);
	cout << endl;
	return 0;
}