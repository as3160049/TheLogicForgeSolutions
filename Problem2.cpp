#include<bits/stdc++.h>
using namespace std;

string minWindow(string log, string pattern) {      // log : "ADOBECODEBANC", pattern : "ABC"
    if (pattern.length() > log.length())                            
        return "";

    unordered_map<char, int> freq;
    for (char c : pattern)
        freq[c]++;

    int left = 0, matched = 0;
    int minLen = INT_MAX, start = 0;

    for (int right = 0; right < log.length(); right++) {
        char c = log[right];

        // Decrease frequency and check match
        if (freq[c] > 0)
            matched++;
        freq[c]--;

        // When all characters match
        while (matched == pattern.length()) {
            // Update minimum window
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            // Shrinking from left
            char leftChar = log[left];
            freq[leftChar]++;
            if (freq[leftChar] > 0)
                matched--;

            left++;
        }
    }

    return minLen == INT_MAX ? "" : log.substr(start, minLen);
}

int main()
{
    cout << minWindow("ADOBECODEBANC", "ABC");
 return 0;
}