#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

/*
Algo:
1. from player fill the matrix, with shortest no. of steps. Abandon a path, if meet a monster 
   before reaching the edge.
2. For each possible edge cell (i.e < INFINITY weight), try to reach any monster (and measure steps). 
   Stop if monster found (or steps > player steps from the cell)
3. We have a success case if the nearest monster is farther than the player. 

*/

const int INFINITY = INT_MAX;

vector<vector<int>> dirs = {{0, 1, 'R'}, {1, 0, 'D'}, {0, -1, 'L'}, {-1, 0, 'U'}};

void fill_with_shortest_path(int r, int c, vector<vector<int>> &psp);
int distance_to_nearest_monster(int pr, int pc, int pdist);
char reverse_direction(int ch);

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
	

	/*
	cout << "player costs" << endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout << psp[i][j] << " ";
		}
		cout << endl;
	}
	*/


	// step 2 of algo (described on top of this file)
	bool monster_far = false;
	int mdist = INFINITY;
	int ei = -1;
	int ej = -1;
	for(int i=0; i<n; i++) {
		//cout << "step 2, i: " << i <<  endl;
		if (i ==0 || i == n-1) {
			for(int j=0; j<m; j++) {
				if (psp[i][j] == INFINITY)
					continue;

				mdist = distance_to_nearest_monster(i, j, psp[i][j]);
				// cout << "i: " << i << ", j: " << j << ", mdist: " << mdist << endl;
				if (mdist > psp[i][j]) {
					monster_far = true;
					ei = i;
					ej = j;
					break;
				}
			}
		} else {
			if (psp[i][0] < INFINITY) {
				mdist = distance_to_nearest_monster(i, 0, psp[i][0]);
				// cout << "i: " << i << ", j: " << 0 << ", mdist: " << mdist << endl;
				if (mdist > psp[i][0]) {
					ei = i;
					ej = 0;
					monster_far = true;
				}
			}

			if (psp[i][m-1] < INFINITY) {
				if (!monster_far) {
					mdist = distance_to_nearest_monster(i, m-1, psp[i][m-1]);
					// cout << "i: " << i << ", j: " << m-1 << ", mdist: " << mdist << endl;
				}
				if (mdist > psp[i][m-1]) {
					monster_far = true;
					ei = i;
					ej = m-1;
				}
			}

			
		}

		if (monster_far)
			break;
	}


	//cout << "step 2 over" << endl;

	if (monster_far) {
		cout << "YES" << endl;
		// cout << "ei: " << ei << ", ej: " << ej << ", dist: " << psp[ei][ej] << endl;
		cout << psp[ei][ej] << endl;
		stack<char> st;
		int dist = psp[ei][ej];
		while(dist > 0) {
			for(auto dir: dirs) {
				int ii = ei + dir[0];
				int jj = ej + dir[1];
				if (ii < 0 || ii >= n || jj < 0 || jj >= m)
					continue;

				if (psp[ii][jj] < dist) {
					char ch = dir[2];
					st.push(reverse_direction(ch));
					dist--;
					ei = ii;
					ej = jj;
					break;
				}
			}
		}

		// print the path
		while(!st.empty()) {
			char ch = st.top();
			st.pop();
			cout << ch;
		}
		cout << endl;

	} else {
		cout << "NO" << endl;
	}
	


}

char reverse_direction(int ch) {
	switch(ch) {
		case 'U' : return 'D';
		case 'D' : return 'U';
		case 'L' : return 'R';
		case 'R' : return 'L';
	}
	return '0'; // never reaches here
}

int distance_to_nearest_monster(int pr, int pc, int pdist) {
	//cout << "distance_to_nearest_monster(), pr: " << pr << ", pc; " << pc << ", pdist: " << pdist << endl;
	vector<vector<int>> psp(n, vector<int>(m, INFINITY));
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

				if (ii < 0 || ii >= n || jj < 0 || jj >= m || grid[ii][jj] == '#' || grid[ii][jj] == 'P')
					continue;

				if (grid[ii][jj] == 'M')
					return d+1;

				if ( d+1 > pdist )
					return INFINITY;

				int d2 = d + 1;
				if (psp[ii][jj] > d2) {
					psp[ii][jj] = d2;
					q.push(make_pair(ii, jj));
				}				
			}
	}
	return INFINITY;
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

				if (ii < 0 || ii >= n || jj < 0 || jj >= m || grid[ii][jj] == '#' || grid[ii][jj] == 'M')
					continue;

				int d2 = d + 1;
				if (psp[ii][jj] > d2) {
					psp[ii][jj] = d2;
					q.push(make_pair(ii, jj));
				}
			}
	}
}