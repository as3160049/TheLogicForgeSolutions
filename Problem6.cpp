#include<bits/stdc++.h>
using namespace std;

void TowerofHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 0) return;

    // Move n-1 disks from from_rod to aux_rod using to_rod
    TowerofHanoi(n - 1, from_rod, aux_rod, to_rod);

    // Move nth disk from from_rod to to_rod
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;

    // Move the n-1 disks at aux_rod to to_rod using from_rod
    TowerofHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n = 3;
    TowerofHanoi(n, 'A', 'C', 'B');
 return 0;
}