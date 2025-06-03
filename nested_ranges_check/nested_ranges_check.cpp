#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define int long long

// Node structure
struct Node {
  int id;
  int x;
  int y; // other end (begin if v is end i.e. opposote) 

  Node(int id, int x, bool start, int y) {
  	this->id = id;
  	this->x = x;
  	this->y = y;
  }

  void print() {
  	cout << "Node: id: " << this->id << ", x: " << this->x << ", y: " << this->y << endl;
  }

};

/**
Implementation of binary indexed tree (or Fenwick tree), 
which is needed to solve this problem
**/
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

	int query(int p1, int p2) {
		int qp1 = query(p1);
		int qp2 = query(p2);

		cout << "query(" << p1 << ") = " << qp1 << endl;
		cout << "query(" << p2 << ") = " << qp2 << endl;
		
		return qp2 - qp1;
	}

	void print() {
		for (int i=0; i<_n; i++) {
			cout << _bit[i] << " ";
		}
		cout << endl;
	}

};




signed main() {
	int n;
	cin >> n;


	vector<Node *> vec(n);

	vector<int> all_y(n);
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		Node *n = new Node(i, x, true, y);
		vec[i] = n;
		all_y[i] = y;
	}

	// we need to have bigger range with same x on top. For that:

	// first sord the y range in descending order
	sort(vec.begin(), vec.end(), [](Node* lhs, Node* rhs) {
	    return lhs->y > rhs->y;
	});
	
	// then the x range in ascedding order
	sort(vec.begin(), vec.end(), [](Node* lhs, Node* rhs) {
	    return lhs->x < rhs->x;
	});

	
	cout << " printing sorted list --- " << vec.size() << "----" << endl;
	for (auto n: vec) {
		n->print();
	}

	cout << "---------- " << endl;
	
	cout << "compressed ys" << endl;
	sort(all_y.begin(), all_y.end());
	map<int, int> compy;
	
	int prev = all_y[0];
	int idx=0;
	compy[all_y[0]] = idx++;
	for (int i=1; i<n; i++) {
		int cur = all_y[i];
		if (prev != cur)
			compy[cur] = idx++;

		prev = cur;
	}

	for (auto it = compy.begin(); it != compy.end() ; it++ ) {
		cout << it->first << " => " << it->second << endl;
	}
	cout << "---" << endl;

	vector<int> has_others(n);
	vector<int> is_inside(n);

	int compy_sz = compy.size();
	BIT bit(compy_sz);
	for (Node * nd: vec) {
		int y = compy[nd->y];
		int qval = bit.query(y, compy_sz);
		cout << "query(" << y << ", " << compy_sz << ") = " << qval << endl;
		if (qval >= 1)
			is_inside[nd->id];

		bit.update(y, 1);
		bit.print();
	}



	

	

	for (int i=0; i<n; i++) {
		cout << has_others[i] << " ";
	}
	cout << endl;

	for (int i=0; i<n; i++) {
		cout << is_inside[i] << " ";
	}
	cout << endl;
}