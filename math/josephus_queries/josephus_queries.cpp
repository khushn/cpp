#include <iostream>

using namespace std;

#define int long long


struct Node {
	int id;
	Node * next;

	Node(int n) {
		this->id = n;
		this->next = NULL;
	}
};


void print(Node *p) {
	Node *node = p;
	while(node != NULL) {
		cout << node->id << " ";
		node = node->next;
	}
	cout << endl;
}

signed main() {

	int q;
	cin >> q;
	for(int i=0; i<q; i++) {
		int n, k;
		cin >> n >> k;
		Node *p = new Node(1);
		Node *cur = p;
		for(int j=1; j<n; j++) {
			Node *node = new Node(j+1);
			cur->next = node;
			cur = node;
		}
		//print(p);

		// make it cyclic
		cur->next = p;

		cur = p;
		for(int j=0; j<k-1; j++) {
			Node *tmp = cur->next;
			cur->next = cur->next->next;
			delete tmp;
			cur = cur->next;
		}
		cout << cur->next->id << endl;
	}

}

