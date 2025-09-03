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
		graph[a].push_back(make_pair(b, w));
	}


	// dp array of min cost to any city
	// sum and max(x)
	vector<pair<int, int>> city_cost(n+1, {LONG_MAX, LONG_MAX}); 
	priority_queue<tuple<int, int, int>> q;
	// priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;

	q.push(make_tuple(1, 0, 0));

	while(!q.empty()) {
		auto t = q.top(); q.pop();
		int n1 = get<0>(t);		
		int c = get<1>(t);
		int x = get<2>(t);

		//cout << "incoming n1: " << n1 << ", c: " << c << ", x: " << x << endl;
		// check if incoming city cost is greater than existing 
		// then ignore
		int ac = c - x + x/2;
		auto p2 = city_cost[n1];
		int c2 = p2.first;
		int x2 = p2.second;
		int ec = c2 - x2 + x2/2;
		if (c > c2) {
			continue;
		}

		//cout << "assigning n1: " << n1 << ", c: " << c << ", x: " << x << endl;
		city_cost[n1] = make_pair(c, x);

		// now we know cost is less
		// we can use it
		for( auto p: graph[n1]) {
			int n2 = p.first;
			int c2 = p.second;
			int tc = c + c2;
			int x2 = x;
			if (c2 > x2)
				x2 = c2;
			q.push(make_tuple(n2, tc, x2));

		}
	}


	int tc = city_cost[n].first;
	int x = city_cost[n].second;
	tc = tc - x + x/2;
	cout << tc << endl;

}