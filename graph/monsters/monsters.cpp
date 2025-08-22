#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

/*
Approach 2
Algo:
1. Fill the graph with how many min steps it takes to get to the edge by any monster. In one-shot it will 
account for all the monsters.
2. Then check if the player has any path to edge in fewer steps than the monster. 
    - Abandon and print "NO", if player stuck before moving to edge
    - else print "YES" and pathrint te path

*/

const int INFINITY = INT_MAX;

vector<vector<int>> dirs = {{0, 1, 'R'}, {1, 0, 'D'}, {0, -1, 'L'}, {-1, 0, 'U'}};

void fill_with_shortest_path(int r, int c, vector<vector<int>> &psp);
void fill_monster_weights(int mr, int mc, vector<vector<int>> &psp);
char reverse_direction(int ch);

int n, m;
vector<vector<int>> grid;

signed main() {
	
	cin >> n >> m;

	int pr, pc, mr, mc;	
	mr = -1;
	mc = -1;
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

	// step 1. Monster(s) shortest path to edges
	vector<vector<int>> psp(n, vector<int>(m, INFINITY));
	fill_monster_weights(mr, mc, psp);
	
	//cout << "step 1 over" << endl;

	/*
	cout << "monster edge costs" << endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout << psp[i][j] << " ";
		}
		cout << endl;
	}
	*/
	


	// step 2 of algo (described on top of this file)
	psp[pr][pc] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(pr, pc));
	bool monster_far = false;
	int ei = -1;
	int ej = -1;
	while (!q.empty()) {
			auto p = q.front(); q.pop();
			int i = p.first;
			int j = p.second;

			int d = psp[i][j];

			// check if player is on any edge
			if (i == 0 || i == n-1 || j == 0 || j == m-1) {
				monster_far = true;
				ei = i;
				ej = j;
				break;
			}

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

void fill_monster_weights(int mr, int mc, vector<vector<int>> &psp) {
	
	if (mr < 0 || mc < 0)
		return;

	psp[mr][mc] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(mr, mc));
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
				if (grid[ii][jj] == 'M')
					d2 = 0;
				
				if (psp[ii][jj] > d2) {
					psp[ii][jj] = d2;
					q.push(make_pair(ii, jj));
				}		
			}
	}
	return;
}

