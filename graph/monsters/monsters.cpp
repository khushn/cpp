#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INFINITY = 10000;

vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void fill_with_shortest_path(int r, int c, vector<vector<int>> &psp);

int n, m;
vector<vector<int>> grid;

signed main() {
	
	cin >> n >> m;

	int pr, pc, mr, mc;	
	for(int i=0; i<n; i++) {
		vector<int> row(m);
		for(int j=0; j<m; j++) {
			char ch;
			cin >> ch;
			row[j] = ch;
			if (ch == 'A') {
				pr = i; 
				pc = j;
			}
			else if (ch == 'M') {
				mr = i; 
				mc = j;
			}
		}
		grid.push_back(row);
	}

	// player shortest path to edges
	// grid 1 for player shortest path to edges
	vector<vector<int>> psp(n, vector<int>(m, INFINITY));
	fill_with_shortest_path(pr, pc, psp);
	

	cout << "player costs" << endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout << psp[i][j] << " ";
		}
		cout << endl;
	}



	// grid 2 for monster shortest path to edges
	vector<vector<int>> msp(n, vector<int>(m, INFINITY));
	fill_with_shortest_path(mr, mc, msp);
	

	cout << "monster costs" << endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout << msp[i][j] << " ";
		}
		cout << endl;
	}


}

void fill_with_shortest_path(int pr, int pc, vector<vector<int>> &psp) {
	psp[pr][pc] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(pr, pc));
	while (!q.empty()) {
			auto p = q.front(); q.pop();
			int i = p.first;
			int j = p.second;

			int d = psp[i][j];

			for(auto dir: dirs) {
				int ii = i + dir[0];
				int jj = j + dir[1];

				if (ii < 0 || ii >= n || jj < 0 || jj >= m || grid[ii][jj] == '#')
					continue;

				int d2 = d + 1;
				if (psp[ii][jj] > d2) {
					psp[ii][jj] = d2;
					q.push(make_pair(ii, jj));
				}
			}
	}
}