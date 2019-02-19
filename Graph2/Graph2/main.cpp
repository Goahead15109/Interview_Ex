#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

bool ScheduleCourses(vector<vector<int> >& prerequisites)
{
	vector<int> degree(prerequisites.size());	//每个节点的入度
	vector<list<int> > neighbors(prerequisites.size());	//每个节点的后继节点
	queue<int> available;	//当前可以上的课节点（入度为0）

	for (int i = 0; i < prerequisites.size(); ++i) {
		degree[i] = prerequisites[i].size();
		if (degree[i] == 0)
			available.push(i);
	}
	for (int to = 0; to < prerequisites.size(); ++to) {
		for (int from : prerequisites[to]) {
			neighbors[from].push_back(to);
		}
	}

	int ct = 0;	//记录删除节点数目
	while (available.size()) {
		cout << available.front() << endl;
		for (int id : neighbors[available.front()]) {
			--degree[id];	//将该节点后继节点入度-1
			if (degree[id] == 0)
				available.push(id);
		}
		available.pop();
		++ct;
	}
	return ct == prerequisites.size();
}
int main()
{
	vector<vector<int> > prerequisites({ {1},{3},{3},{} });
	if (ScheduleCourses(prerequisites))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}