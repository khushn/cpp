#include <iostream>
#include <map>

using namespace std;

#define int long long

signed main() {

	int n;
	cin >> n;


	// store the movie finish time as key, and start time as value
	// in case of clash we store the latest start time (as want shorter movie, to avoid clash)
	// as the map will be sorted (C++ map is a tree map), we can just select greedily after that
	map<int, int> movie_timings;

	for (int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		if (movie_timings.find(b) == movie_timings.end())
			movie_timings[b] = a;
		else {
			int cura = movie_timings[b];
			if (a > cura)
				movie_timings[b] = a;
		}

	}

	int num_full_movies = 0;
	int prev_end_time = 0;
	for (const auto& [key, value] : movie_timings) {
		if (num_full_movies == 0) {
			num_full_movies++;
			prev_end_time = key;
			continue;
		}

		if (value >= prev_end_time) {
			num_full_movies++;
			prev_end_time = key;
		}
	}

	cout << num_full_movies << endl;

	return 0;
}