#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


#define int long long

signed main() {



    int n, x;
    cin >> n >> x;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int ans = 0;

    // Just to verify input was read correctly
    //cout << "n = " << n << ", x = " << x << endl;
    //cout << "Numbers: ";
    multimap<int, int> my_map;

    sort(numbers.rbegin(), numbers.rend());
    for (int num : numbers) {
        //cout << "--- " << num << " " << endl;

        if (my_map.empty()) {
            my_map.insert(std::pair<int,int>(x - num, 1));
            continue;
        }

        /*
        int rem = x - num;
        if (rem > num) {
            rem = num;
        }
        */
        auto it = my_map.lower_bound(num);
        if (it != my_map.end()) {
            auto nv = it->first - num;
            int count = it->second;
            //cout << endl << "num: " << num << ", nv: " << nv << ", x: " << x << endl;
            if (nv >= 0 && count < 2) { 
                
                //cout << "my_map before erase... size() " << my_map.size() << ", *it: " << *it << endl;
                my_map.erase(it);
                ans += 1;
                //cout << "deleting value of " << nv << " from map as it reached count 2" << endl;
                //cout << "my_map after erase... size() " << my_map.size() << endl;
                //my_map.insert(std::pair<int,int>(nv, count+1));
                //cout << "my_map after replace... size() " << my_map.size() << ", nv: " << nv << endl;
            } else {
                my_map.insert(std::pair<int,int>(x - num, 1));
                //cout << "my_map after inserting(path 1)... size() " << my_map.size() << ", nv: " << x - num << endl;
            }
        } else {
            my_map.insert(std::pair<int,int>(x - num, 1));
            //cout << "my_map after inserting(path 2)... size() " << my_map.size() << ", nv : " << x - num << endl;
        }
        //my_map.insert(num);
    }
    //cout << endl;


    /*
    cout << "set: " << endl;
    for (const auto& [x, val] : my_map) {
        cout << x << " ";
    }
    cout << endl;
    */

    ans += my_map.size();
    cout << ans << endl;
    return 0;
}
