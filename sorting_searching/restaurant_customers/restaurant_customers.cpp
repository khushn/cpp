#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    int n;
    cin >> n;  // Read number of pairs

    vector<pair<int, int>> pairs;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        pairs.emplace_back(a, 1);  // add +1 for arrival 
        pairs.emplace_back(b, -1); // set -1 for departure
    }

    sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    
    /*
    // Optional: print the pairs to verify input
    cout << "Read " << n << " pairs:\n";
    for (const auto& p : pairs) {
        cout << p.first << " " << p.second << "\n";
    }
    */
    

    int ans = 0;
    int cur_custs = 0;

    for (int i=0; i<2*n; i++) {
        auto cur = pairs[i].second;
        cur_custs += cur;
        if (cur_custs > ans) {
            ans = cur_custs;
        }

    }

    cout << ans << endl;

    return 0;
}
