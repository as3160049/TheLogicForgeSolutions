#include<bits/stdc++.h>
using namespace std;

double MedianofSortedArrays(vector<int>& a, vector<int>& b) {
    int n1 = a.size();
    int n2 = b.size();
    int n = n1 + n2;    // total number of elements

    int ind2 = n / 2;   // second median index
    int ind1 = ind2 - 1;    // first median index (only for even n)

    int cnt = 0, i = 0, j = 0;
    int ind1el = -1, ind2el = -1;

    // Traverse both arrays
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            i++;
        } else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            j++;
        }
        cnt++;
    }

    // Add any remaining elements in a[]
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        i++;
        cnt++;
    }

    // Add any remaining elements in b[]
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        j++;
        cnt++;
    }

    return n % 2 == 1 ? double(ind2el) : double(ind1el + ind2el) / 2.0;
}

int main()
{
    vector<int> a = {1,4,5,7}, b = {2,3,4,8};
    cout << MedianofSortedArrays(a, b);
 return 0;
}