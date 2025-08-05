#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
Simple cycle detection algo. 
Need to use DFS for this (although I am prefering BFS for all graph problems so far i CSES)
Maintain a visited list, to process fast
*/

const int N = 1e5+1;
vector<int> graph[N];
vector<bool> visited(N);
//map<int, int> g_portion;

vector<int> g_portion(N);


bool find_cycle(int nd1) {

	visited[nd1] = true;

	for(int nd2: graph[nd1]) {

		/*
		auto it = g_portion.find(nd2);
		if (it != g_portion.end() && it->second == nd1)
			continue;

		g_portion[nd1] = nd2;
		*/

		if (g_portion[nd2] == nd1)
			continue;
		
		g_portion[nd1] = nd2;

		//cout << nd1 << "->" << nd2 << endl;
		
		//if (g_portion.find(nd2) != g_portion.end()) {	
		if (g_portion[nd2] != 0) {		
			// found cycle !!
			
			/*
			// debug
			for (const auto & it: g_portion) {
				cout << it.first << "->" << it.second << endl;
			}
			*/
		
			
			vector<int> print_vec;
			print_vec.push_back(nd2);
			int cur_node = g_portion[nd2];
			while (cur_node != nd2 && cur_node != 0) {
				print_vec.push_back(cur_node);
				cur_node = g_portion[cur_node];
			}
			print_vec.push_back(nd2);

			cout << print_vec.size() << endl;
			for(int k: print_vec)
				cout << k << " ";
			cout << endl;
			
			return true;			
		}

		if (!visited[nd2]) {
			if (find_cycle(nd2))
				return true;
		}

		g_portion[nd1]=0;
		//cout << "------ erasing for " << nd1 << endl;
	}
	return false;
}

signed main() {

	int n, m;
	cin >> n >> m;

	for(int i=0; i<m; i++) {
		int l, r;
		cin >> l >> r;
		graph[l].push_back(r);
		graph[r].push_back(l);
	}

	for(int i=1; i<=n; i++) {

		//cout << "coming in for node " << i << endl;

		if (visited[i])
			continue;

		bool found = find_cycle(i);
		if (found)
			return 0;

		//g_portion.clear();

		// cout << "=====" << endl;

	}
	
	cout << "IMPOSSIBLE" << endl;
}