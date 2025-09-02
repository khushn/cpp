#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>

using namespace std;

#define int long long

/*
Algo: 
This one was bit tough. Had to make several tries (after getting the basic idea)
Final approach put below:
0. Initialize all incoming edges (paths) to -ve infinity for all nodes
1. Use a priority queue (instead of just queue) based on weights (incoming to a node). 
    We don't have to do anything special. Just keep weight second in the tuple, and it works on its own
    as node is the same (test case 25 showed this need)
2. Ignore incoming edges if weight is less than existing
3. Add some cases to break early (not sure if its essential)
4. In the end print high_scores[n]


*/

signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n+1);
	for(int i=0; i<m; i++) {
		int a, b, x;
		cin >> a >> b >> x;
		graph[a].push_back(make_pair(b, x));
		//mp[make_pair(a, b)] = x;		
	}


	vector<int> max_scores(n+1, LONG_MIN);
	// queue<tuple<int, int, int>> q;
	priority_queue<tuple<int, int, int>> q;
	q.push(make_tuple(1, 0, 0));
	while(!q.empty()) {
		// auto t = q.front(); q.pop();
		auto t = q.top(); q.pop();
		int n1 = get<0>(t);		
		int w = get<1>(t);
		int plen = get<2>(t);
		// cout << "incoming node, n1: " << n1 << ", plen: " << plen << ", w: " << w << endl;
		/*
		if (plen > n*3) {
			// abandon this path 
			continue;
		}
		*/

		
		if (w > max_scores[n1]) {
			if (plen > n) {
				w = LONG_MAX;
			}
			max_scores[n1] = w;
			// cout << "new max_scores[" << n1 << "] = " << w << ", plen: " << plen << endl;

		} else {
			continue;
		}
		
		if (n1 == n && w == LONG_MAX)
			break;
		

		for(auto p: graph[n1]) {
			int n2 = p.first;
			int w2 = p.second;
			int nw;
			if (w == LONG_MAX)
				nw = w;
			else
				nw = w + w2;

			// case of 1 1 2 (edge to self having positive weight as in test case no. 25)
			if (n1 == n2 && w2 > 0)
				nw = LONG_MAX;

			q.push(make_tuple(n2, nw, plen+1));			
		}

	}

	int res = max_scores[n];
	if (res == LONG_MAX)
		res = -1;
	cout << res << endl;

}