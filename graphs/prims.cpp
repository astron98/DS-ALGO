/*
 * Prims algorithm
 * time complexity: O((V + E)*logV) using priority-queue or (min-heap).
 * */

#include<bits/stdc++.h>
using namespace std;
#define l(i,n) for(int i=0;i< (int)n;i++)
#define l1(i,n) for(int i=1;i< (int)n;i++)
typedef long long ll;
typedef pair<ll, int> P;
const int MAX = 1e4 + 5;
bool marked[MAX];

vector<P> adj[MAX];

ll prim(int x) {
	priority_queue<P, vector<P>, greater<P> > q;

	int y;
	ll minCost = 0;

	P p;
	q.push(make_pair(0, x));

	while (!q.empty()) {
		p = q.top();
		q.pop();

		x = p.second;

		if (!marked[x]) {
			minCost += p.first;
			marked[x] = true;

			l(i, static_cast<int>(adj[x].size())) {
				y = adj[x][i].second;
				if (!marked[y])
					q.push(adj[x][i]);
			}
		}
	}

	return minCost;
}

int main() {
	int nodes, edges, x, y;
	ll weight, minCost;
	cin >> nodes >> edges;
	l(i, edges) {
		cin >> x >> y >> weight;
		adj[x].push_back(make_pair(weight, y));
		adj[y].push_back(make_pair(weight, x));
	}

	// using 1 as the root/starting node.
	minCost = prim(1);

	cout << "The minimum cost is: " << minCost << "\n";
	return 0;
}

/*
	test cases:
* 
1. input
5 7
0 1 2
0 3 6
1 3 8
1 4 5
1 2 3
2 4 7
3 4 9
* output: 16 
*/
