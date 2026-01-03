#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    int count = 0;
    for (char c : s) {
        if (c == '(') {
            count++;
        } else if (c == ')') {
            count--;
            if (count < 0) {
                return false; // More closing parentheses than opening
            }
        }
    }
    return count == 0;
}

vector<string> removeInvalidParentheses(string s) {
    vector<string> result;
    if (s.empty()) {
        result.push_back("");
        return result;
    }

    unordered_set<string> visited;
    queue<string> q;
    bool found = false;

    q.push(s);
    visited.insert(s);

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (isValid(current)) {
            result.push_back(current);
            found = true;
        }

        if (found) continue; // Stop generating further strings once a valid string is found

        for (int i = 0; i < current.length(); i++) {
            if (current[i] != '(' && current[i] != ')') continue;

            string next = current.substr(0, i) + current.substr(i + 1);
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push(next);
            }
        }
        if (found) break;
    }
    
    return result;
}

int main()
{
    string s = "()())()";
    vector<string> res = removeInvalidParentheses(s);
    for (const string& str : res) {
        cout << str << endl;
    }
 return 0;
}