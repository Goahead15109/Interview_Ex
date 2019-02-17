#include<iostream>
#include<vector>

using namespace std;

int FindAncestor(vector<int>& root, int value1, int value2,int rt)
{
	if (rt > root.size() - 1 || root[rt] == -1)
		return -1;

	if (root[rt] == value1 || root[rt] == value2)
		return root[rt];	//若当前值匹配，则一定返回该值
	int l = FindAncestor(root, value1, value2, 2 * rt + 1);
	int r = FindAncestor(root, value1, value2, 2 * rt + 2);

	//find 0 或 1
	//若没匹配，返回-1			
	//若匹配1个，返回该匹配值
	//二者都可描述为l+r+1
	if (l == -1 || r == -1)
		return l + r + 1;
	//find 2
	//有两个匹配，则返回节点自身值
	else
		return root[rt];
}
int main()
{
	vector<int> root({ 1,2,3,-1,4,5,6 });
	int value1 = 3;
	int value2 = 2;
	cout << FindAncestor(root, value1, value2, 0) << endl;
	return 0;
}