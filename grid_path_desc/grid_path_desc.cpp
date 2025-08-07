#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>

#define ulong unsigned long long

using namespace std;



const int NUM_STEPS = 48;
const int GRID_SIZE = 7;

int co_ord_to_seq(int x, int y) {
	return x * GRID_SIZE + y + 1;
}

pair<int, int> seq_to_co_ord(int seq) {
	seq--;
	return make_pair(seq/GRID_SIZE, seq%GRID_SIZE);
}

bool is_bit_set(ulong v, int pos) {
	return v&(1ull<<pos);
}

string binary_print(ulong v) {
	int n = GRID_SIZE * GRID_SIZE;
	string str(n, '0');
	for(int i=0; i<n; i++) {
		if (v & (1ull <<i))
			str[n-i-1] = '1';
	}
	return str;
}

// all four directions
// the extra two coordinates are for the 2nd cell in the same direction
vector<vector<int>> dirs = {{0,1, 0, 2}, {0, -1, 0, -2}, {1, 0, 2, 0}, {-1, 0, -2, 0}};

// not to cover all end cells
/*
vector<vector<pair<int, int>>> check_cells = { {{6, 0} },
									{ {5, 0}, {6, 1} },
									{ {4, 0}, {5, 1}, {6, 2} },
									{ {3, 0}, {4, 1}, {5, 2}, {6, 3} }, 
									{ {2, 0}, {3, 1}, {4, 2}, {5, 3}, {6, 4} }, 
									{ {1, 0}, {2, 1}, {3, 2}, {4, 3}, {5, 4}, {6, 5} }, 
									{ {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6} } };
*/

// keep till 3 prev steps only
vector<vector<pair<int, int>>> check_cells = { {{6, 0} },
									{ {5, 0}, {6, 1} },
									{ {4, 0}, {5, 1}, {6, 2} } };									
									

signed main() {
	/*
	int i = 1<<18;
	//i+=2;
	int j = i & (1<<18 | 1<<1);
	cout << j << endl;


	int t = 1ULL << 0;
	cout << "test binary print: " << binary_print(t) << endl;

	return 0;
	

	int num_prev_steps = check_cells.size();

	for(int k=0; k<num_prev_steps; k++) {
		vector<pair<int, int>> check_list = check_cells[k];
		cout << "k: " << k << endl;
		for(auto chk: check_list) {
			int x = chk.first;
			int y = chk.second;
			int seq = co_ord_to_seq(x, y);
			cout << "x: " << x << ", y: " << y << ", seq: " << seq << endl;
			cout << "rep: " << binary_print(1ull<<(seq-1)) << endl;
		}
	}

	return 0;
	*/

	string input;
	cin >> input;

	vector<pair<int, ulong>> cur_pos_list;
	cur_pos_list.push_back(make_pair(1, 1ull<<0));

	for(int s=1; s<=NUM_STEPS; s++) {
		int ch = input[s-1];

		vector<pair<int, ulong>> new_cur_pos_list;
		// for each cur position
		for(auto p: cur_pos_list) {
			int x, y;
			tie(x, y) = seq_to_co_ord(p.first);
			ulong route = p.second;

			
			// cout << "x: " << x << ", y: " << y << endl;
			// cout << "route: " << binary_print(route) << endl;


			/*
			// Approach 3
			bool must_follow_this_dir = false;
			// check if its 2nd cell in the same direction is filled, 
			// in that case we need to take it (TBD: Explain on this logic if it works!)
			for(auto dir : dirs) {
				int x1 = x + dir[0];
				int y1 = y + dir[1];
				if (x1 < 0 || y1 <  0 || x1 > GRID_SIZE - 1 || y1 > GRID_SIZE - 1)
					continue;

				int seq = co_ord_to_seq(x1, y1);				
				if (x1 == 0 && x == 1 && y == y1 && !is_bit_set (route, seq-1)) {				
					int x2 = x + dir[2];
					int y2 = y + dir[3];

					ulong new_route = route|(1ull<<(seq-1));

					
					
					//if (x2 < 0 || y2 <  0 || x2 > GRID_SIZE - 1 || y2 > GRID_SIZE - 1)
					//	must_follow_this_dir = true;
					
					//else {
					//	int seq2 = co_ord_to_seq(x2, y2);
					//	if (is_bit_set (route, seq2-1)) {
					//		must_follow_this_dir = true;
					//	}
					//}

					must_follow_this_dir = true;

					if (must_follow_this_dir) {
						new_cur_pos_list.push_back(make_pair(seq, new_route));
						// we don't even want to consider other directions in this case
						break;
					}
					
				}

			}

			if (must_follow_this_dir)
				continue;
				
			*/


			
			for(auto dir : dirs) {
				int x1 = x + dir[0];
				int y1 = y + dir[1];
				if (x1 < 0 || y1 <  0 || x1 > GRID_SIZE - 1 || y1 > GRID_SIZE - 1)
					continue;

				/*
				// ignore the case when reach destination cell before the last step
				if (s < NUM_STEPS) {
					if (x1 == GRID_SIZE - 1 && y1 == 0)
						continue;
				}
				*/


				// approach 2 -- need to make it work. Its fast!!
				bool prev_filled = true;
				// check if it touches the top row, at any time, then 
				// all left of it must be filled
				if ( x1 == 0 ) {
					for (int yy = y1-1; yy>0; yy--) {
						int s1 = co_ord_to_seq(x1, yy);
						if (!is_bit_set(route, s1 - 1)) {
							prev_filled = false;
							break;
						}
					}
				} 

				if (!prev_filled)
					continue;

				prev_filled = true;
				// check if it goes into the left or right most column,
				// then the all top of it on the left or right most column musst be filled
				if (y1 == 0 || y1 == GRID_SIZE-1) {
					for (int xx = x1-1; xx>=0; xx--) {
						int s1 = co_ord_to_seq(xx, y1);
						// cout << "x1: " << xx << ", y1: " << y1 << ", xx: " << xx << ", s1: " << s1 << endl;
						if (!is_bit_set(route, s1 - 1)) {
							// cout << "bit not set" << endl;
							prev_filled = false;
							break;
						}
					}
				}

				if (!prev_filled)
					continue;


				// check bottom row, in this case to the right must be filled previously
				prev_filled = true;
				
				if ( x1 == GRID_SIZE - 1) {
					for (int yy = y1+1; yy<=GRID_SIZE-1; yy++) {
						int s1 = co_ord_to_seq(x1, yy);
						if (!is_bit_set(route, s1 - 1)) {
							prev_filled = false;
							break;
						}
					}

				}

				if (!prev_filled)
					continue;

				// NOW check for the inner sides of 5x5 grid, they should move in the opposite direction
				prev_filled = true;
				if (x1 == 1) {
					// if top row is filled
					int num_filled = 0;
					for(int yy = 0; yy< GRID_SIZE-1; yy++) {
						int s1 = co_ord_to_seq(0, yy);
						if (is_bit_set(route, s1 - 1)) {
							num_filled++;
						}
					}

					if (num_filled == GRID_SIZE) {
						// now check the rhs filled of the current row
						for(int yy=y1+1; yy<GRID_SIZE; yy++){
							int s1 = co_ord_to_seq(x1, yy);
							if (!is_bit_set(route, s1 - 1)) {
								prev_filled = false;
								break;
							}
						}

					}
				}

				if (!prev_filled)
					continue;

				int seq = co_ord_to_seq(x1, y1);
				if (!is_bit_set (route, seq-1)) {
					ulong new_route = route|(1ull<<(seq-1));
					bool can_add = true;


					/*
					// Approach 1 -- keep till 3 prev steps only
					int num_prev_steps = check_cells.size();

					for(int k=0; k<num_prev_steps; k++) {
						vector<pair<int, int>> check_list = check_cells[k];

						if (s < NUM_STEPS - k) {
							int num_filled = 0;
							for(auto chk: check_list) {
								int new_seq = co_ord_to_seq(chk.first, chk.second);
								if (is_bit_set(new_route, new_seq - 1)) {
									num_filled++;
								}
							}

							if (num_filled == check_list.size()) {
								can_add = false;
								break;
							}
						}
					}
					*/
					

						
					if (can_add)
						new_cur_pos_list.push_back(make_pair(seq, new_route));
				}
			}
			
				
			
		}

		cout << "--- after step : " << s << " size of new_cur_pos_list: " << new_cur_pos_list.size() << endl;
		
		/*		
		for(auto p: new_cur_pos_list) {
			int x, y;
			tie(x, y) = seq_to_co_ord(p.first);
			cout << "pos: (" << x << ", " << y << "), bitset: " << binary_print(p.second) << endl;
		}
		*/
		
		if (s >= NUM_STEPS - 4) {
			map<pair<int, int>, int> count_map;
			for(auto p: new_cur_pos_list) {
				int x, y;
				tie(x, y) = seq_to_co_ord(p.first);
				count_map[make_pair(x, y)] += 1;
			}
			for (auto & it: count_map) {
				cout << "x: " << it.first.first << ", y: " << it.first.second << ", count: " << it.second << endl;
			}
		}
		
		
		
		cur_pos_list = new_cur_pos_list;
	}


}


