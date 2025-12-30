#include <bits/stdc++.h>
using namespace std;
void selectionsr(vector<int> &ar)
{
    for (int i = 0; i < ar.size() - 1; i++)
    {
        int minid = i;
        for (int j = i + 1; j < ar.size(); j++)
        {
            if (ar[minid] > ar[j])
            {
                minid = j;
            }
        }
        swap(ar[minid], ar[i]);
    }
}
void insertion(vector<int> &ar)
{
    int j = 0;
    for (int i = 1; i < ar.size(); i++)
    {
        int key = ar[i];
        j = i - 1;
        while (j >= 0 && ar[j] > key)
        {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = key;
    }
}
void buble(vector<int> &ar)
{
    for (int i = 0; i < ar.size() - 1; i++)
    {
        bool check = false;
        for (int j = 0; j < ar.size() - 1 - i; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                check = true;
                swap(ar[j], ar[j + 1]);
            }
        }
        if (!check)
            break;
    }
}
int partition(vector<int> &ar, int l, int h)
{
    int j = l;
    int i = j - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (ar[j] < ar[h])
        {
            i++;
            swap(ar[j], ar[i]);
        }
    }
    swap(ar[i + 1], ar[h]);
    return i + 1;
}
void quicksor(vector<int> &ar, int l, int h)
{
    if (l < h)
    {
        int pivot = partition(ar, l, h);
        quicksor(ar, l, pivot - 1);
        quicksor(ar, pivot + 1, h);
    }
}
void mergre(vector<int> &ar, vector<int> &lef, vector<int> &right)
{
    int l = lef.size();
    int r = right.size();
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < l && j < r)
    {
        if (lef[i] < right[j])
        {
            ar[k] = lef[i];
            k++;
            i++;
        }
        else
        {
            ar[k] = right[j];
            k++;
            j++;
        }
    }
    while (i < l)
    {
        ar[k] = lef[i];
        k++;
        i++;
    }
    while (j < r)
    {
        ar[k] = right[j];
        k++;
        j++;
    }
}
void mergesort(vector<int> &ar)
{
    int length = ar.size();
    if (length <= 1)
        return;
    int lefsize = length / 2;
    int rightsize = length - lefsize;
    vector<int> left(lefsize);
    vector<int> right(rightsize);
    int l = lefsize;
    int r = rightsize;
    for (int i = 0; i < length; i++)
    {
        if (i < lefsize)
        {
            left[i] = ar[i];
        }
        else
        {
            right[i - lefsize] = ar[i];
        }
    }
    mergesort(left);
    mergesort(right);
    mergre(ar, left, right);
}

int main()
{
    vector<int> ar(10);
    for (int i = 0; i < 10; i++)
        cin >> ar[i];
    mergesort(ar);
    for (auto x : ar)
        cout << x << " ";
    return 0;
}