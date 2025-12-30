#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left, *right;
    node(int x) : val(x), left(nullptr), right(nullptr) {}
};

node* buildBalancedBST(vector<int> &arr, int l, int r) {
    if (l > r) return nullptr;
    int mid = (l + r) / 2;
    node* root = new node(arr[mid]);
    root->left = buildBalancedBST(arr, l, mid - 1);
    root->right = buildBalancedBST(arr, mid + 1, r);
    return root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());

        node* root = buildBalancedBST(arr, 0, n - 1);
        cout << root->val << "\n";
    }
    return 0;
}
