#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void PreOrder(vector<int>& root)
{
	stack<int> s;
	if (!root.empty()) {
		s.push(0);
		while (!s.empty()) {
			int rt = s.top();	s.pop();
			if (2 * rt + 2 < root.size() && root[2 * rt + 2] != -1)
				s.push(2 * rt + 2);	//先添加右孩子
			if (2 * rt + 1 < root.size() && root[2 * rt + 1] != -1)
				s.push(2 * rt + 1);	//后添加左孩子
			cout << root[rt] << " ";
		}
	}
	cout << endl;
}
int main()
{
	vector<int> root({ 1,2,3,-1,4,5,6 });
	PreOrder(root);
	return 0;
}