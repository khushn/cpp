#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

signed main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n+1, vector<int>());
	for(int i=0; i<m; i++) {
		int l, r;
		cin >> l >> r;
		graph[l].push_back(r);
		graph[r].push_back(l);
	}

	
	queue<int> q;
	map<int, int> team_allotment;
	int pcount = 1;
	team_allotment[1] = pcount;
	q.push(1);

	while(!q.empty()) {
		int pupil_no = q.front();
		q.pop();

		vector<int> connections = graph[pupil_no];
		if (connections.size() > 0) {
			int team_id = team_allotment[pupil_no];
			int other_team_id = 1;
			if (team_id == 1)
				other_team_id = 2;

			for( int p2: connections) {
				if (team_allotment.find(p2) != team_allotment.end()) {
					if ( team_allotment[p2] == team_id ) {
						cout << "IMPOSSIBLE" << endl;
						return 0;
					}
				} else {
					team_allotment[p2] = other_team_id;
					q.push(p2);
				}
			}
		}  


		if (q.empty() && pcount < n) {
			pcount++;
			if (team_allotment.find(pcount) == team_allotment.end())
				team_allotment[pcount] = 1;
			q.push(pcount);
		}
				
	}

	for(int i=1; i<=n; i++)
		cout << team_allotment[i] << " ";

	cout << endl;
}