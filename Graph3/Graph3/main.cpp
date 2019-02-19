#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

struct Node {
	int cost;
	int city;
	int stops;	//还可以走的次数
	bool operator>(const Node& n) const{ return cost > n.cost; }
};
int ScheduleFlights(vector<vector<vector<int> > >& flights, int from, int to, int k)
{
	priority_queue<Node, vector<Node>, std::greater<Node> > pq;
	Node tn = { 0,from,k + 1 };
	pq.push(tn);
	while (!pq.empty()) {
		tn = pq.top();	pq.pop();
		if (tn.city == to) {
			return tn.cost;
		}

		if (tn.stops > 0) {
			for (int i = 0; i < flights[tn.city].size(); ++i) {
				Node node = { flights[tn.city][i][1]+tn.cost,flights[tn.city][i][0],tn.stops - 1 };
				pq.push(node);
			}
		}
	}
	return -1;
}
int main()
{
	vector<vector<vector<int> > > flights({ { {1,1000},{2,2000} }, {{2,500}}, {{1,500}} });
	cout << ScheduleFlights(flights, 0, 2, 1) << endl;
	return 0;
}