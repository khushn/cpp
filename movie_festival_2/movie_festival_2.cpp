#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Thought this problem for several days. 
Today morning the solution came to me (as it often does at a specific place and time after morning tea)

Need to just sort based on movie end times. 
And allot to all prople in a greedy way. If a movie can't be placed, move to next movie
After assigning the movie to one person move to the next person. 

Time complexity: 
Sorting : N(log(N)) and one look of N + K so O(N+K). N movies and K people
N(log(N)) + O(N+K)


*/
signed main() {
	int n, k;

	cin >> n >> k;

	vector<pair<int, int>> vec(n);
	for(int i=0; i<n; i++) {
		int s, e;

		cin >> s >> e;
		vec[i] = pair(e, s);
	}	

	sort(vec.begin(), vec.end());

	int cur_watcher = 0;
	// end time of the current movie they are watching
	vector<int> watchers(k); 
	int num_watched = 0;
	for(int i=0; i<n; i++) {
		cout << vec[i].first << " : " << vec[i].second << endl;
		int start = vec[i].second;
		int end = vec[i].first;
		if (start >= watchers[cur_watcher]) {
			num_watched++;
			watchers[cur_watcher] = end;
			cur_watcher++;
			cur_watcher = cur_watcher % k;
		} 
	}

	cout << num_watched << endl;
}