#include<bits/stdc++.h>
using namespace std;

int CountLessorEqual (vector<vector<int>>& matrix, int mid) {
    int n = matrix.size();
    int row = n - 1, col = 0;
    int cnt = 0;
    while (row >= 0 && col < n) {
        if (matrix[row][col] <= mid) {
            cnt += (row + 1);
            col++;
        }
        else {
            row--;
        }
    }
    return cnt;
}

// Binary Search Approach
int KthsmallestElement(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int m = matrix[0].size();

    int low = matrix[0][0];
    int high = matrix[n-1][m-1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = CountLessorEqual(matrix, mid);

        if (count < k) {    // Mid needs to be increased
            low = mid + 1;
        } else {            // Mid may be decreased
            high = mid;
        }
    }
    return low;     // low points to the kth smallest element
}

struct compare {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0];
    }
};

// Heap Approach
int KthsmallestElementHeap(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();

    // Min-Heap to store {value, row, col}
    priority_queue<vector<int>, vector<vector<int>>, compare> minHeap;
    
    // Push first element of each row
    for(int i = 0; i < n; i++) {
        minHeap.push({matrix[i][0], i, 0});
    }

    // Extract min k-1 times
    for (int i = 0; i < k - 1; i++) {
        auto curr = minHeap.top();
        minHeap.pop();
        int r = curr[1];
        int c = curr[2];

        // If next element in the same row exists, push it
        if (c + 1 < n) {
            minHeap.push({matrix[r][c + 1], r, c + 1});
        }
    }
    return minHeap.top()[0];
}

int main()
{
    vector<vector<int>> matrix = {
        {1,5,9},
        {10,11,13},
        {12,13,15}
    };
    int k = 7;
    cout << KthsmallestElement(matrix, k) << endl;

    cout << KthsmallestElementHeap(matrix, k) << endl;
 return 0;
}