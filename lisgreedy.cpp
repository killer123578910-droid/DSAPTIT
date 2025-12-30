#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    cin >> n;
    
    vector<long long> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    vector<vector<long long>> result;

    while (!ar.empty()) {
        vector<long long> currentLIS;
        long long last = LLONG_MIN;
        
        for (auto it = ar.begin(); it != ar.end(); ++it) {
            if (*it > last) {
                currentLIS.push_back(*it);
                last = *it;
            }
        }

        result.push_back(currentLIS);

        unordered_set<long long> lisElements(currentLIS.begin(), currentLIS.end());
        vector<long long> remaining;
        for (auto num : ar) {
            if (lisElements.find(num) == lisElements.end()) {
                remaining.push_back(num);
            }
        }
        ar = remaining;
    }

    cout << result.size() << endl;
    for (const auto& lis : result) {
        for (auto x : lis) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main() {
    solution();
    return 0;
}
