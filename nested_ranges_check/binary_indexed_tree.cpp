#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define int long long

class BIT {

public: 

	vector<int> _bit;
	int _n;

	BIT(int n):_n(n), _bit(n) {
	}

	void update(int pos, int v) {
		
		pos +=1; // to make it 1 based index for the math to work
		while ( pos <= _n) {
			_bit[pos-1] += v;
			pos += pos&-pos; // find the lowest bit set and increment by that
		}
	}

	int query(int pos) {

		int sum;

		// to make it 1 based index for the math to work
		pos +=1;
		while (pos >= 1) {
			sum += _bit[pos-1];
			pos -= pos&-pos; // find the parent
		}

		return sum;
	}

	void print() {
		for (int i=0; i<_n; i++) {
			cout << _bit[i] << " ";
		}
		cout << endl;
	}

};

signed main() {

	cout << "input vector size n <enter> followed by n values" << endl;
	int n;
	cin >> n;
	vector<int> testv(n);
	BIT bit(n);
	for (int i=0; i<n; i++) {
		cin >> testv[i];
		bit.update(i, testv[i]);
	}

	bit.print();

	cout << "querying the binary indexed tree " << endl;
	for (int pos=0; pos<n; pos++)
		cout << bit.query(pos) << " ";

	cout << endl;

}