#include <iostream>
#include <map>

using namespace std;

#define int long long

/*
Thought about it for long. Then today morning at 5:30 AM got a good idea. 
1. Maintain a map of latest position of int occurence. Also another map of index to value. 
2. map length can't exeed x. 
3. As soon as it does do some book keeping, and delete the first one. 
4. Bookkeeping is counting the no. of subarrays so far. 

NOTE: 2 maps are needed to properly book keep. 
*/
void print_map(const map<int, int> & mp1);

signed main() {
	int n, x;
	cin >> n >> x;

	int num_subarrays = 0;
	// value to index (max size x)
	map<int, int> mp1;
	// index to value (max size x)
	map<int, int> mp2;
	int left = 0;
	int mid = -1;
	int right = 0;
	for (int i=0; i<n; i++) {
		int v;
		cin >> v;

		auto it = mp1.find(v);
		if ( it != mp1.end()) {
			int old_ind = it->second;
			mp2.erase(old_ind);
		}

		mp1[v] = i;
		mp2[i] = v;
		/*
		cout << "mp1 ---" << endl;
		print_map(mp1);
		cout << "mp2 ---" << endl;
		print_map(mp2);
		*/

		if (mp2.size() > x) {
			auto last = mp2.end();
			last--; last --;
			right = last->first;
			int mul = 0;
			if (mid >= left) {
				mul = (mid-left + 1) * (right - mid);
			}
			int t = right - mid;
			int permutations = t * (t+1) / 2;

			/*
			cout << "left: " << left << ", mid: " << mid << ", right: " << right << endl;
			cout << "mul: " << mul << endl;
			cout << "permutations: " << permutations << endl;
			*/

			num_subarrays += mul + permutations;

			// move the indices
			mid = right;
			auto first = mp2.begin();
			int val_to_delete = first->second;
			left = first->first + 1;

			// remove the first element			
			mp1.erase(val_to_delete);
			mp2.erase(first);
		}
	}


	// process upto end of array
	right = n-1;
	int mul = 0;
	if (mid >= left) {
		mul = (mid-left + 1) * (right - mid);
	}
	int t = right - mid;
	int permutations = t * (t+1) / 2;

	/*
	cout << "left: " << left << ", mid: " << mid << ", right: " << right << endl;
	cout << "mul: " << mul << endl;
	cout << "permutations: " << permutations << endl;
	*/
	
	num_subarrays += mul + permutations;

	cout << num_subarrays << endl;
}

void print_map(const map<int, int> & mp1) {
	for (auto it: mp1) {
		cout << it.first << " : " << it.second << endl;
	}
	cout << "====" << endl;
}