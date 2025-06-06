#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

#define int long long


struct cust {
	int day;
	bool arrival;
	int id;

	cust(int day, bool arr, int id) {
		this->day = day;
		this->arrival = arr;
		this->id = id;
	}

	void print() {
		cout << "id: " << this->id << ", day: " << this-> day << ", arrival: " << this->arrival << endl; 
	}
};

signed main() {
	int n;
	cin >> n;

	vector<cust *> custs(2 * n);
	for (int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		cust *ca = new cust(a, true, i);
		cust *cb = new cust(b, false, i);
		custs[2*i] = ca;
		custs[2*i+1] = cb;
	}

	//cout << "pass 1: custs.size(): " << custs.size() <<  endl;

	// NOTE:
	// This was easier than previous. Faced issue in sort not being balanced. 
	// Any specific check for lhs with rhs need to be made the other way also. Else gives issues
	
	sort(custs.begin(), custs.end(), [](cust *lhs, cust * rhs) {


		if (lhs->day == rhs->day) {
			// have arrivals before departure, as room is not empty on same day clash
			if (!lhs->arrival && rhs->arrival)
				return false;
			else if (lhs->arrival && !rhs->arrival)
				return true;
			else 
				return lhs->id < rhs->id;
		}

		
		return lhs->day < rhs->day;
	});


	/*
	cout << "print debug sort" << endl;
	for (cust *c: custs) {
		c->print();
	}
	*/

	int nrooms = 0;
	map<int, int> cust_room;
	stack<int> mystack;
	for (cust *c: custs) {
		if (c->arrival) {
			// arrival
			if (mystack.empty()) {
				nrooms++;
				cust_room[c->id] = nrooms;
			} else {
				int roomno = mystack.top();
				mystack.pop();
				cust_room[c->id] = roomno;
			}
		} else {
			// departure
			int roomno = cust_room[c->id];
			mystack.push(roomno);
		}

	}

	cout << nrooms << endl;
	for (int i=0; i<n; i++) {
		cout << cust_room[i] << " ";
	}
	cout << endl;
}