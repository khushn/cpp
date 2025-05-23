#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define int long long

/*
Algo: Just store all the song ids in a map, with value as index. 
On repeat occurance, do calculations. Also in the end. 

First tried with hashmap (unordered_map), but it failed in the 19th test case as constant time is very high, 
and data was given such that buckets are not reused. 

Switched to tree map (just map in C++) and it worked. 19th test case passed in .19 seconds!
*/

signed main() {
	int n;
	cin >> n;

	vector<int> vec(n);
	map<int, int> hashmap;
	int max_uniq = 0;
	int uniq_beg_ind = 0;
	for(int i=0; i<n; i++) {
		int song_id;
		cin >> song_id;
		vec[i] = song_id;

		if (i == 0) {
			hashmap[song_id] =  i;
			continue;
		}

		if (hashmap.find(song_id) != hashmap.end()) {
			int ind = hashmap[song_id];
			for (int j=uniq_beg_ind; j<=ind; j++) 
				hashmap.erase(vec[j]);

			int cur_uniq = i - uniq_beg_ind;
			if (cur_uniq > max_uniq) {				
				max_uniq = cur_uniq;
				//cout << "setting max_uniq: " << max_uniq << ", i: " << i << ", ind: " << ind << ", song id: " << vec[i] << endl;				
			}

			uniq_beg_ind = ind+1;
		}
		
		hashmap[song_id] =  i;		
	}

	int cur_uniq = n - uniq_beg_ind;
	if (cur_uniq > max_uniq) {		
		max_uniq = cur_uniq;
		//cout << "setting max_uniq: " << max_uniq << ", uniq_beg_ind: " << uniq_beg_ind  << endl;
	}

	cout << max_uniq << endl;
}