#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution
vector<int> TeamContributionBrute(vector<int>& contributions) {
    int n = contributions.size();
    vector<int> impact(n,1);                  // {4,1,5,3}
    for(int i = 0; i < n; i++) {              // {15,60,12,20}
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            impact[i] *= contributions[j]; 
        }
    }
    return impact;
}


//Better Solution
vector<int> TeamContribution(vector<int>& contributions) {
    int n = contributions.size();
    vector<int> impact(n);

    // Prefix product
    impact[0] = 1;
    for (int i = 1; i < n; i++) {
        impact[i] = impact[i - 1] * contributions[i - 1];  // {4,1,5,3}
    }                                                      // {1,4,4,20}   {15,60,12,20}

    // Suffix product and final result
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        impact[i] *= suffix;
        suffix *= contributions[i];
    }

    return impact;
}
