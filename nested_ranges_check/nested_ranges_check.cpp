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
  int v;
  bool start;
  int v1; // other end (begin if v is end i.e. opposote) 

  Node(int id, int v, bool start, int v1) {
  	this->id = id;
  	this->v = v;
  	this->start = start;
  	this->v1 = v1;
  }

  void print() {
  	cout << "Node: id: " << this->id << ", v: " << this->v << ", start: " << this->start << ", v1: " << this->v1 << endl;
  }

};





signed main() {
	int n;
	cin >> n;


	vector<Node *> vec(n);
	for (int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		Node *n = new Node(i, a, true, b);
		vec[i] = n;
	}


	
	sort(vec.begin(), vec.end(), [](Node* lhs, Node* rhs) {
	    return lhs->v < rhs->v;
	});

	/*
	cout << " printing sorted list --- " << vec.size() << "----" << endl;
	for (auto n: vec) {
		n->print();
	}

	cout << "---------- " << endl;
	*/

	/*
	sort(vec.begin(), vec.end(), [](Node* lhs, Node* rhs) {

		
	    if (lhs->v <= rhs->v && lhs->v1 >= rhs->v1)
	        return true;
	    // Ensure the opposite is false, so sort has consistent decisions
	    if (rhs->v <= lhs->v && rhs->v1 >= lhs->v1)
	        return false;
	     
	    // Fallback: sort by a ascending
	    return (lhs->v1 - lhs->v < rhs->v1 - rhs->v);
	});
	*/

	sort(vec.begin(), vec.end(), [](Node* lhs, Node* rhs) {
	    return lhs->v1 > rhs->v1;
	});

	
	cout << " printing sorted list --- " << vec.size() << "----" << endl;
	for (auto n: vec) {
		n->print();
	}

	cout << "---------- " << endl;
	


	vector<int> has_others(n);
	vector<int> is_inside(n);

	

	for (int i=0; i<n; i++) {
		cout << has_others[i] << " ";
	}
	cout << endl;

	for (int i=0; i<n; i++) {
		cout << is_inside[i] << " ";
	}
	cout << endl;
}