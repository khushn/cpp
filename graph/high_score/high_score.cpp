#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>

using namespace std;

#define int long long

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
	priority_queue<tuple<int, int, int>> q;
	q.push(make_tuple(1, 0, 0));
	while(!q.empty()) {
		auto t = q.top(); q.pop();
		int n1 = get<0>(t);
		int plen = get<1>(t);
		int w = get<2>(t);
		//cout << "n1: " << n1 << ", plen: " << plen << ", w: " << w << endl;
		/*
		if (plen > n*3) {
			// abandon this path 
			continue;
		}
		*/

		if (n1 == n && w == LONG_MAX)
			break;

		
		if (w > max_scores[n1]) {
			if (plen > n) {
				w = LONG_MAX;
			}
			max_scores[n1] = w;
			// cout << "new max_scores[" << n1 << "] = " << w << ", plen: " << plen << endl;

		} else {
			continue;
		}
			
		

		for(auto p: graph[n1]) {
			int n2 = p.first;
			int w2 = p.second;
			int nw;
			if (w == LONG_MAX)
				nw = w;
			else
				nw = w + w2;
			q.push(make_tuple(n2, plen+1, nw));			
		}

	}

	int res = max_scores[n];
	if (res == LONG_MAX)
		res = -1;
	cout << res << endl;

}