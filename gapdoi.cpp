#include <bits/stdc++.h>
using namespace std;

long long len[51];

void init() {
    len[1] = 1;
    for (int i = 2; i <= 50; i++)
        len[i] = len[i - 1] * 2 + 1;
}

int solve(int n, long long l, long long r, long long k) {
    if (n == 1) return 1;

    long long mid = l+(r-l)/2;

    if (k == mid) return n;
    if (k < mid)
        return solve(n - 1, l, mid - 1, k);
    else
        return solve(n - 1, mid + 1, r, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        cout << solve(n, 0, len[n]-1, k-1) << '\n';
    }
    return 0;
}
