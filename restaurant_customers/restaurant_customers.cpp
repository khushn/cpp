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
        pairs.emplace_back(a, b);  // Store each pair
    }

    sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    
    // Optional: print the pairs to verify input
    cout << "Read " << n << " pairs:\n";
    for (const auto& p : pairs) {
        cout << p.first << " " << p.second << "\n";
    }
    

    int ans = 0;
    for (int i=0; i<n; i++) {
        auto cur = pairs[i];
        int cur_leave_time = cur.second;
        int beg = i+1;
        int end = n;
        while (beg < end) {

            int mid = (beg + end) / 2;
            cout << "beg: " << beg << ", end: " << end << ", mid: " << mid << endl;
            cout << "cur_leave_time: " << cur_leave_time << ", pairs[mid].first: " << pairs[mid].first << endl;
            if (cur_leave_time > pairs[mid].first) {
                beg = mid + 1;
            } else {
                end = mid;
            }

        }

        int tmp = beg - i;
        if (tmp > ans) {
            ans = tmp;
        }

    }

    cout << ans << endl;

    return 0;
}
