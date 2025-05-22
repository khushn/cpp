#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define int long long 

signed main() {

	int n, m;
	cin >> n >> m;

	vector<int> vec(n);
	map<int, int> mp;
	for (int i=0; i<n; i++) {
		cin >> vec[i];
		mp.insert(pair(vec[i], i));
	}


	// use another vector instead of costly map (using map in later loop gave TLE)
	vector<int> vec2(n+1);

	int num_spans = 0;
	int prev_ind = -1;
	for (auto it = mp.rbegin(); it != mp.rend(); ++it) {

		vec2[it->first] = it->second;

		//cout << "it->second: " << it->second << endl;
		if (num_spans == 0) {
			num_spans++;
			prev_ind = it->second;
			continue;
		}

		if (it->second > prev_ind) {
			num_spans++;
		}

		//cout << "num_spans: " << num_spans << endl;
		prev_ind = it->second;

	}

	//cout << num_spans << endl;

	/*

	cout << "initial vec: ";
	for (const int& v: vec) {
		cout << v << " ";
	}
	cout << endl;
	*/

	for (int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;

		if (a == b) {
			cout << num_spans << endl;
			continue;
		}

		// make them 0 based index
		a--;
		b--;

		//cout << "----" << endl;


		int num1 = vec[a];
		int num2 = vec[b];


		//cout << "num1: " << num1 << ", num2: " << num2 << endl;
		//cout << "a: " << a << ", b: " << b << endl;

		if (num1 > num2) {
			// ensure a is less than b
			swap(num1, num2);
			swap(a, b);

			/*
			cout << "swapped" << endl;
			cout << "num1: " << num1 << ", num2: " << num2 << endl;
			cout << "a: " << a << ", b: " << b << endl;
			*/
		}

		

		// check num1's above and below
		if (num1 > 1) {
			int topind = vec2[num1-1];
			//cout << "num1 topind: " << topind << endl;
			if (topind < a && topind > b)
				num_spans++;
			else if (topind > a && topind < b)
				num_spans--;

			//cout << "num_spans (after top check for num1): " << num_spans << endl;
		}

		
		if (num2 == num1 + 1) {
			if (a > b)
				num_spans--;
			else 
				num_spans++;

			//cout << "num_spans (after adj num check): " << num_spans << endl;

		} else {

			int botind = vec2[num1+1];
			//cout << "num1 botind: " << botind << endl;
			if (botind > a && botind < b)
				num_spans++;
			else if (botind < a && botind >= b)
				num_spans--;
			
			//cout << "num_spans (after bottom check for num1): " << num_spans << endl;
			
			// ensure not contigous
			int topind = vec2[num2-1];
			//cout << "num2 topind: " << topind << endl;
			if (topind < b && topind > a)
				num_spans++;
			else if (topind > b && topind < a)
				num_spans--;

			//cout << "num_spans (after top check for num2): " << num_spans << endl;
			
		}

		if (num2 < n) {
			int botind = vec2[num2+1];
			//cout << "num2 botind: " << botind << endl;
			if (botind > b && botind < a)
				num_spans++;
			else if (botind < b && botind > a)
				num_spans--;

			//cout << "num_spans (after bottom check for num2): " << num_spans << endl;
		}

		vec2[num1] = b;
		vec2[num2] = a;
		//cout << "before swap, a: " << a << ", b: " << b << endl;
		int t = vec[b];
		vec[b] = vec[a];
		vec[a] = t;

		/*
		cout << "vec after swap: ";
		for (const int& v: vec) {
			cout << v << " ";
		}
		cout << endl;
		*/
		cout << num_spans << "\n";	
	}

}