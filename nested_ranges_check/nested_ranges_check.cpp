#include <iostream>
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

struct NodeComparator {
    bool operator() (const Node* lhs, const Node* rhs) const {

	if (lhs->v < rhs->v) 
		return true;

	if (lhs->v > rhs->v)
		return false;


	// we come here only when v values are same
	if (lhs->start && rhs->start)
		return lhs->v1 < rhs->v1;

	if (!lhs->start && !rhs->start) {
		// for end same choose later start to go ahead	
		return lhs->v1 > rhs->v1;
	}

	
	if (lhs->start && !rhs->start)
		return false;
	
	if (!lhs->start && rhs->start)
			return true;
	

	return false;
	}

};




signed main() {
	int n;
	cin >> n;


	set<Node *, NodeComparator> ndset;
	map<int, Node *> mp;
	for (int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		Node *na = new Node(i, a, true, b);
		Node *nb = new Node(i, b, false, a);
		ndset.insert(na);
		mp[i] = na;
		ndset.insert(nb);
	}

	/*
	cout << " printing sorted list --- " << ndset.size() << "----" << endl;
	for (auto n: ndset) {
		n->print();
	}

	cout << "---------- " << endl;
	*/


	vector<int> has_others(n);
	vector<int> is_inside(n);

	set<int> container;
	for (auto n: ndset) {
		// n->print();
		if (n->start) {			
			container.insert(n->id);
			//cout << "insert id: " << n->id << ", size: " << container.size() << endl;
		} else {
			//vector<int> tvec;
			for (auto cid: container) {
				if (cid != n->id) {
					//cout << "looking in map for id: " << cid << endl;
					Node * c = mp[cid];
					//cout << "in map, c->id: " << cid << ", c: " << c << endl;
					
					if (c->v <= n->v1) {
						//cout << "n->id: " << n->id << ", cid: " << cid << endl;
						is_inside[n->id] = 1;

						has_others[cid] = 1;
						//tvec.push_back(cid);
						//cout << "has_others, cid: " << cid << ", value: " << has_others[cid] << endl;
					}
				}
			}

			/*
			for (int tid: tvec) {
				container.erase(tid);
			}
			*/
			container.erase(n->id);
			//cout << "erasing id: " << n->id << ", size: " << container.size() << endl;
		}
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