#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


#define int long long

signed main() {



    int n, m;
    cin >> n >> m;

    multiset<int> tick_price;
    for (int i = 0; i < n; ++i) {
    	int tmp;
        cin >> tmp;
        tick_price.insert(tmp);
    }

    /*
    cout << "set: " << endl;
    for (const auto x : tick_price) {
        cout << x << " ";
    }
    cout << endl;
    */
    

    //vector<int> max_offer(m);
    for (int i = 0; i < m; ++i) {
    	int offer;
        cin >> offer;

        int deal_price = -1;

        if (tick_price.size() > 0) {
	        auto it = tick_price.lower_bound(offer);
	        if (it != tick_price.end()) {
	        	int p = *it;
	        	if (p == offer) {
	        		deal_price = p;
	        		tick_price.erase(it);
	        	} else {
	        		if (it != tick_price.begin()) {
	        			// not already at the first element 	        		
		        		--it;
		        		while (true) {
		        			int tmp = *it;
		        			if (tmp <= offer) {
		        				deal_price = tmp;
		        				tick_price.erase(it);
		        				break;
		        			}

		        			if (it == tick_price.begin()) {
		        				break;
		        			}
		        			--it;
		        		}
		        	}
	        	}
	        } else {
	        	// offered price is larger than all ticket prices.
	        	// pick the last one
	        	auto it = --tick_price.end();
	        	deal_price = *it;
	        	tick_price.erase(it);
	        }
	        
	    }

        cout << deal_price << endl;
    }
    
}