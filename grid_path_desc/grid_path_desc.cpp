#include <iostream>
#include <vector>
#include <string>
#include <tuple>

#define int unsigned long long

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

bool is_bit_set(int v, int pos) {
	return v&(1ull<<pos);
}

string binary_print(int v) {
	int n = GRID_SIZE * GRID_SIZE;
	string str(n, '0');
	for(int i=0; i<n; i++) {
		if (v & (1ull <<i))
			str[n-i-1] = '1';
	}
	return str;
}

// all four directions
vector<pair<int, int>> dirs = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

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

vector<vector<pair<int, int>>> check_cells = { {{6, 0} },
									{ {5, 0}, {6, 1} },
									{ {4, 0}, {6, 2} },
									{ {3, 0}, {6, 3} }, 
									{ {2, 0}, {6, 4} }, 
									{ {1, 0}, {6, 5} }, 
									{ {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6} } };

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

	vector<pair<int, int>> cur_pos_list;
	cur_pos_list.push_back(make_pair(1, 1ull<<0));

	for(int s=1; s<=NUM_STEPS; s++) {
		int ch = input[s-1];

		vector<pair<int, int>> new_cur_pos_list;
		// for each cur position
		for(auto p: cur_pos_list) {
			int x, y;
			tie(x, y) = seq_to_co_ord(p.first);
			int route = p.second;

			/*
			cout << "x: " << x << ", y: " << y << endl;
			cout << "route: " << binary_print(route) << endl;
			*/

			
			for(auto dir : dirs) {
				int x1 = x + dir.first;
				int y1 = y + dir.second;
				if (x1 < 0 || y1 <  0 || x1 > GRID_SIZE - 1 || y1 > GRID_SIZE - 1)
					continue;

				int seq = co_ord_to_seq(x1, y1);
				if (!is_bit_set (route, seq-1)) {
					int new_route = route|(1ull<<(seq-1));
					bool can_add = true;

					int num_prev_steps = check_cells.size();

					for(int k=0; k<num_prev_steps; k++) {
						vector<pair<int, int>> check_list = check_cells[k];

						if (s < NUM_STEPS - k) {
							int num_filled = 0;
							for(auto chk: check_list) {
								if (is_bit_set(new_route, co_ord_to_seq(chk.first, chk.second))) {
									num_filled++;
								}
							}

							if (num_filled == check_list.size()) {
								can_add = false;
								break;
							}
						}
					}


					if (can_add)
						new_cur_pos_list.push_back(make_pair(seq, new_route));
				}
			}
			
				
			


			/*
			cout << x << ", " << y << ", " << route << endl;
			cout << "is_bit_set(1): " << is_bit_set(route, 1) << endl;
			cout << "is_bit_set(0): " << is_bit_set(route, 0) << endl;
			cout << "is_bit_set(2): " << is_bit_set(route, 2) << endl;
			*/
		}

		cout << "--- after step : " << s << " size of new_cur_pos_list: " << new_cur_pos_list.size() << endl;
		
		/*
		for(auto p: new_cur_pos_list) {
			int x, y;
			tie(x, y) = seq_to_co_ord(p.first);
			cout << "pos: (" << x << ", " << y << "), bitset: " << binary_print(p.second) << endl;
		}
		*/
		
		
		
		cur_pos_list = new_cur_pos_list;
	}


}


