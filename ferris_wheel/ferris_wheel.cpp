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

    // Just to verify input was read correctly
    //cout << "n = " << n << ", x = " << x << endl;
    //cout << "Numbers: ";
    multimap<int, int> my_set;

    sort(numbers.rbegin(), numbers.rend());
    for (int num : numbers) {
        //cout << num << " ";

        if (my_set.empty()) {
            my_set.insert(std::pair<int,int>(num, 1));
            continue;
        }

        int rem = x - num;
        if (rem > num) {
            rem = num;
        }
        auto it = my_set.lower_bound(rem);
        if (it != my_set.end()) {
            auto nv = it->first + num;
            int count = it->second;
            //cout << endl << "num: " << num << ", nv: " << nv << ", x: " << x << endl;
            if (nv <= x && count < 2) { 
                
                //cout << "my_set before erase... size() " << my_set.size() << ", *it: " << *it << endl;
                my_set.erase(it);
                //cout << "my_set after erase... size() " << my_set.size() << endl;
                my_set.insert(std::pair<int,int>(nv, count+1));
                //cout << "my_set after replace... size() " << my_set.size() << ", nv: " << nv << endl;
            } else {
                my_set.insert(std::pair<int,int>(num, 1));
                //cout << "my_set after inserting(path 1)... size() " << my_set.size() << ", num: " << num << endl;
            }
        } else {
            my_set.insert(std::pair<int,int>(num, 1));
            //cout << "my_set after inserting(path 2)... size() " << my_set.size() << ", num: " << num << endl;
        }
        //my_set.insert(num);
    }
    //cout << endl;


    /*    
    cout << "set: " << endl;
    for (const auto& [x, val] : my_set) {
        cout << x << " ";
    }
    cout << endl;
    */
    

    cout << my_set.size() << endl;
    return 0;
}
