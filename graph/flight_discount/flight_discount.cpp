#include <iostream>
#include <vector>
#include <queue>
//#include <priority_queue>
#include <climits>
#include <tuple>

using namespace std;

#define int long long

signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> graph(m+1);
	for(int i=0; i<m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back(make_pair(b, -w));
	}


	// dp array of min cost to any city
	// sum and max(x)
	vector<pair<int, int>> city_cost(n+1, {LONG_MIN, LONG_MIN}); 
	priority_queue<vector<int>> q;
	//queue<tuple<int, int, int>> q;
	// priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;

	q.push({1, 0, 0, 0});

	while(!q.empty()) {
		auto t = q.top(); q.pop();
		// auto t = q.front(); q.pop();
		int n1 = t[0];		
		int c = t[1];
		int x = t[2];
		int nn = t[3];

		if (nn >= n)
			continue;

		//cout << "incoming n1: " << n1 << ", c: " << c << ", x: " << x << endl;
		// check if incoming city cost is greater than existing 
		// then ignore
		//int ac = c - x + x/2;
		auto p2 = city_cost[n1];
		int c2 = p2.first;
		int x2 = p2.second;
		//int ec = c2 - x2 + x2/2;
		
		if (c <= c2 && x <= x2) {
			continue;
		} else {
			if (c > c2)
				c2 = c;
			if (x > x2)
				x2 = x;
			cout << "assigning n1: " << n1 << ", c: " << c2 << ", x: " << x2 << endl;
			city_cost[n1] = make_pair(c2, x2);

		}
		

		
		// now we know cost is less
		// we can use it
		for( auto p: graph[n1]) {
			int n2 = p.first;
			int w2 = p.second;
			int ndc = c2 + w2;
			int dc = c2 + w2/2;
			if (x2 + w2 > dc)
				dc = x2 + w2;
			q.push({n2, ndc, dc, nn+1});

		}
	}

	cout << -city_cost[n].second << endl;

}