#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*
Thought this problem for several days. 
Today morning the solution came to me (as it often does at a specific place and time after morning tea)

Need to just sort based on movie end times. 
And allot to all prople in a greedy way. If a movie can't be placed, move to next movie
After assigning the movie to one person move to the next person. 

Another change, had to make:
Store the current watcher end times in a map, and assign the watcher who has most recently finished.
This gets all the test cases correct. 

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

	
	// end time of the current movie they are watching
	// sorted so that, we can assign the latest end time to the 
	// current movie to be assigned
	multimap<int, int> watchers; 
	for(int i=0; i<k; i++){
		watchers.insert(make_pair(0, i));
	}
	
	int num_watched = 0;
	for(int i=0; i<n; i++) {
		// cout << vec[i].first << " : " << vec[i].second << endl;
		int start = vec[i].second;
		int end = vec[i].first;
		auto it = watchers.lower_bound(start);

		if (it == watchers.begin())
			if (it->first != start)
				continue;

		if (it == watchers.end())
			it--;
		else if (it->first > start)
			it--;

		int watcher = it->second;
		watchers.erase(it);
		watchers.insert(make_pair(end, watcher));
		num_watched++;
		
	}

	cout << num_watched << endl;
}