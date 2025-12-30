#include <bits/stdc++.h>
using namespace std;

void mergre(vector<int> &ar, int start, vector<int> &lef, vector<int> &right)
{
    int l = lef.size();
    int r = right.size();
    int i = 0, j = 0, k = start;

    while (i < l && j < r)
    {
        if (lef[i] < right[j])
            ar[k++] = lef[i++];
        else
            ar[k++] = right[j++];
    }
    while (i < l)
        ar[k++] = lef[i++];
    while (j < r)
        ar[k++] = right[j++];
}

void mergesort(vector<int> &ar, int start, int end)
{
    int length = end - start + 1;
    if (length <= 1)
        return;

    int lefsize = length / 2;
    int rightsize = length - lefsize;

    vector<int> left(lefsize);
    vector<int> right(rightsize);

    // Copy subarrays with offset 'start'
    for (int i = 0; i < length; i++)
    {
        if (i < lefsize)
            left[i] = ar[start + i];
        else
            right[i - lefsize] = ar[start + i];
    }

    // Recursive calls with proper indices
    mergesort(left, 0, lefsize - 1);
    mergesort(right, 0, rightsize - 1);

    // Merge back into ar starting at 'start'
    mergre(ar, start, left, right);
}
void testcase(){
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    mergesort(ar, 0, n - 1);
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        testcase();
        cout<<endl;
    }
    return 0;
}
