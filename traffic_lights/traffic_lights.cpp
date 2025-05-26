#include <iostream>
#include <map>
#include <set>

using namespace std;

#define int long long

void debugprint(map<int, int> & mp);

signed main() {

	int x, n;
	cin >> x >> n;

	string concat_output;

	map<int, int> mp;
	multiset<int> myset;
	mp[x] = x;
	//debugprint(mp);
	myset.insert(x);
	for (int i = 0; i<n; i++) {
		int t;
		cin >> t;
		auto it = mp.lower_bound(t);		
		
		//cout << "trying to find in set, it->second: " << it->second << endl;
		auto setit = myset.find(it->second);
		if (setit != myset.end())
			myset.erase(setit);

		int next_light = it->first;
		int part2 = next_light - t;
		mp[next_light] = part2;
		myset.insert(part2);

		int part1 = t;
		if (it != mp.begin()) {
			it--;
			part1 = t - it->first;
		} 
		mp[t] = part1;
		myset.insert(part1);

		//debugprint(mp);
		//cout << *myset.rbegin() << " ";
		concat_output += to_string(*myset.rbegin()) + " ";
	}
	cout << concat_output << endl;

}

void debugprint(map<int, int> & mp) {
	cout << "map: " << endl;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		cout << "key: " << it->first << ", value: " << it->second << endl;
	}
}