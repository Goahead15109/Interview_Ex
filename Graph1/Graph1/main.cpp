#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct Node {
	vector<Node *> neighbors;
};
Node* BuildGraph(vector<vector<int> >& relationships)
{
	vector<Node *> nodes(relationships.size());
	for (int i = 0; i < relationships.size(); ++i) {
		nodes[i] = new Node();
	}
	for (int i = 0; i < relationships.size(); ++i) {
		for (int j = 0; j < relationships[i].size(); ++j) {
			(nodes[i]->neighbors).push_back(nodes[relationships[i][j]]);
		}
	}
	return nodes[0];
}

Node* CloneGraph(Node* node, unordered_map<Node*, Node*>& map)
{
	if (map.count(node) > 0)	//该节点已克隆
		return map[node];		//返回克隆节点

	Node * clone = new Node();
	map.insert({ node, clone });
	for (int i = 0; i < node->neighbors.size(); ++i) {
		Node* & neighbor = node->neighbors[i];
		clone->neighbors.push_back(CloneGraph(neighbor, map));
	}
	return clone;
}
Node* CloneGraph(Node* node)
{
	unordered_map<Node*, Node*> map;	//<原节点，克隆节点>
	return CloneGraph(node, map);
}

int main()
{
	vector<vector<int> > relationships({ {1,2},{0},{0,2} });
	Node* node = BuildGraph(relationships);
	cout << CloneGraph(node) << endl;
	/*对于内存释放，可以遍历记录每个节点指针到一个向量，再释放*/
	return 0;
}