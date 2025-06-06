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
		/*
		cout << "BIT constructor, _bit vector: " << endl;
		for (int i=0; i<n; i++) {
			cout << "_bit[" <<  i << "] = " << _bit[i] << endl;;
		}
		*/
	}

	void update(int pos, int v) {
		
		pos +=1; // to make it 1 based index for the math to work
		while ( pos <= _n) {
			_bit[pos-1] += v;
			pos += pos&-pos; // find the lowest bit set and increment by that
		}
	}

	int query(int pos) {

		int sum = 0;

		// to make it 1 based index for the math to work
		pos +=1;
		while (pos >= 1) {
			sum += _bit[pos-1];
			pos -= pos&-pos; // find the parent
		}

		return sum;
	}

	int query(int p1, int p2) {

		int qp1 = 0;
		p1--;
		if (p1 >= 0) {
			qp1 = query(p1);
		}
		int qp2 = query(p2);

		// cout << "query(" << p1 << ") = " << qp1 << endl;
		// cout << "query(" << p2 << ") = " << qp2 << endl;
		
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
	
	// then the x range in ascedding order
	sort(vec.begin(), vec.end(), [](Node* lhs, Node* rhs) {

		// this is important to check again, as it may do it randomly for equal x (otherwise)
		if (lhs->x == rhs->x)
			return lhs->y > rhs->y;

	    return lhs->x < rhs->x;
	});

	/*
	cout << " printing sorted list --- " << vec.size() << "----" << endl;
	for (auto n: vec) {
		n->print();
	}

	cout << "---------- " << endl;
	*/
	
	// cout << "compressed ys" << endl;
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

	/*
	for (auto it = compy.begin(); it != compy.end() ; it++ ) {
		cout << it->first << " => " << it->second << endl;
	}
	cout << "---" << endl;
	*/


	// cout << "--- filling has_others --- " << endl;
	vector<int> has_others(n);
	BIT bit1(compy.size());
	int compy_max = compy.size() - 1;	
	for (int i=n-1; i>=0; i--) {
		Node *nd = vec[i];
		int y = compy[nd->y];
		int q = bit1.query(y);
		// cout << "query(" << y << ") = " << q << endl;		
		has_others[nd->id] += q;		
		bit1.update(y, 1);
		// bit1.print();
	}
	// cout << "------- " << endl;


	// cout << "--- filling is_inside --- " << endl;
	vector<int> is_inside(n);
	BIT bit(compy.size());
	compy_max = compy.size() - 1;	
	for (Node * nd: vec) {
		int y = compy[nd->y];
		int qval = bit.query(y, compy_max);
		// cout << "query(" << y << ", " << compy_max << ") = " << qval << endl;
		// cout << "setting is_inside for nd->id: " << nd->id << endl;
		is_inside[nd->id] += qval;		
		bit.update(y, 1);
		// bit.print();
	}
	// cout << "------- " << endl;


	for (int i=0; i<n; i++) {
		cout << has_others[i] << " ";
	}
	cout << endl;

	for (int i=0; i<n; i++) {
		cout << is_inside[i] << " ";
	}
	cout << endl;
}