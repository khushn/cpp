#include <iostream>

using namespace std;

#define int long long

// Node structure
struct Node {
  int v;
  Node* next;
};

signed main() {
	int n;
	cin >> n;

	Node *beg = NULL;
	Node *prev = NULL;
	for(int i=1; i<=n; i++) {		
		Node *n = new Node();
		n->v = i;
		if (i==1)
			beg = n;
		else {
			prev->next = n;
		}
		prev = n;
	}


	// cyclic
	if (prev != beg) // edge case
		prev->next = beg;
	else {
		cout << beg->v << endl;
		return 0;
	}

	Node *nd = beg;

	while (nd!= NULL) {

		if (nd->next == NULL)
			break;

		cout << nd->next->v << " ";
		// cout << nd->v << " ";

		if (nd != nd->next->next)
			nd->next = nd->next->next;
		else {
			cout << nd->v << " ";
			nd->next = NULL;
		}
		nd = nd->next;
	}
	cout << endl;
}