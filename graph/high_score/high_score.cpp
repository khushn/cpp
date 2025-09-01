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


	int max_score = LONG_MIN;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(1, 0, 0));
	while(!q.empty()) {
		auto t = q.front(); q.pop();
		int n1 = get<0>(t);
		int plen = get<1>(t);
		int w = get<2>(t);
		//cout << "n1: " << n1 << ", plen: " << plen << ", w: " << w << endl;
		if (plen > n*3) {
			// abandon this path 
			continue;
		}

		if (n1 == n) {
			if (w > max_score) {
				max_score = w;
				//cout << "new max_score: " << max_score << ", plen: " << plen << endl;
			}

			if (w > 0 && plen >= n*2 ) {
				cout << "-1" << endl;
				return 0;
			}
			
		}

		for(auto p: graph[n1]) {
			int n2 = p.first;
			int w2 = p.second;
			q.push(make_tuple(n2, plen+1, w+w2));			
		}

	}

	cout << max_score << endl;

}