/*
This solution uses a greedy approach along with some dynamic programming to find the maximum number of targets that Bessie can hit by changing up to one command in the command string.
Here's a step-by-step explanation of what the solution does:

Input Reading: 
    The solution first reads the number of targets T and the length of the command string C. It then reads the positions of the targets and stores them in a map where the key is the position of the target and the value is its index. It also reads the command string.


Initialization:
    It initializes variables pos to represent Bessie's current position on the number line.
    It initializes a vector earlyBreak of size T to keep track of the earliest time each target is broken. It also initializes total to 0, representing the total number of targets hit without any modifications to the command string.


Main Loop:
    It iterates through each command in the command string.
    If the command is 'L', Bessie moves one unit to the left (decreases pos by 1).
    If the command is 'R', Bessie moves one unit to the right (increases pos by 1).
    If the command is 'F', Bessie fires:
    If there's a target at Bessie's current position (pos), and it hasn't been hit before (earlyBreak[targetInd] == BIG), it updates earlyBreak[targetInd] to the current index i, indicating that the target is hit at this time, and increments total.


Offset Loop:
    It iterates through each possible ending offset (off) from -2 to 2 (excluding 0).
    For each offset, it simulates the effect of changing the command string by this offset and calculates the maximum number of targets Bessie can hit.
    It considers two scenarios:
    Moving back to the main timeline (using left or right moves) and updating the maximum number of targets hit (ans).
    Firing with the offset applied and updating the maximum number of targets hit (ans).
    It adjusts Bessie's position based on the current command and the offset.
    
Output: 
    Finally, it prints the maximum number of targets that Bessie can hit (ans).
    This solution efficiently considers all possible changes to the command string and offsets to determine the maximum number of targets that Bessie can hit after modifying up to one command.


*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int T, C; cin >> T>> C;
    map<int, int> targets; // map position to index
    for (int i = 0; i < T; i++) {
        int x; cin >> x; targets[x] = i;
    }
    
    string moves; cin >> moves;
    // find out ending position
    // and earliest time each target is broken
    int pos = 0;
    int BIG = 1000005;
    vector<int> earlyBreak(T,BIG);
    int total = 0;
    for (int i = 0; i <C; i++) {
        if (moves[i] == 'L') pos--;
        else if (moves[i] == 'R') pos ++;
        else {
            if (targets.count(pos)) {
                int targetInd = targets[pos];
                if (earlyBreak[targetInd] == BIG) {
                    earlyBreak[targetInd] = i;
                    total ++;
                }
            }
        }
    }
    
    // try each ending offset
    int ans = total;
    for (int off = -2; off <=2; off++) {
        if (off == 0) continue;
        
        int ftotal = total;
        int btotal = 0;
        int cpos = pos;
        vector<bool> brokenTargets(T);
        for (int i = C-1; i>=0; i--) {
            // 1. remove main timeline move
            if (moves[i] == 'F' && targets.count(cpos)) {
                int targetInd = targets[cpos];
                if (!brokenTargets[targetInd] && earlyBreak[targetInd] == i) {
                    ftotal--;
                }
            }
        
            // 2. try getting back to main timeline
            // 2a. with left/right move
            if (
                moves[i] == 'R' && off == -2 ||
                moves[i] == 'L' && off == 2 ||
                moves[i] == 'F' && off == 1 || off == -1
            ) {
                ans = max(ans, ftotal + btotal);
            }
            
            //2b. with firing moves
            if (
                moves[i] == 'R' && off == -1 ||
                moves[i] == 'L' && off == 1
            ) {
                // get old position
                int oldPos = cpos + off;
                bool newBreak = false;
                if (targets.count(oldPos)) {
                    int targetInd = targets[oldPos];
                    if (!brokenTargets[targetInd] && earlyBreak[targetInd] >= i) {
                        newBreak = true;
                    }
                }
                ans = max(ans, ftotal + btotal + (newBreak ? 1 : 0));
            }
            
            // 3. add offset timetime move (backwards)
            if (moves[i] == 'R') cpos --;
            else if (moves[i] == 'L') cpos++;
            else {
                
                if (targets.count(cpos +off)) {
                    int targetInd = targets[cpos + off];
                    
                    if (!brokenTargets[targetInd]) {
                        // cout << cpos << ' ' << off << ' ' << cpos + off << ' ' << i<< endl;
                        brokenTargets[targetInd] = true;
                        btotal++;
                        if (earlyBreak[targetInd] < i) {
                            ftotal --;
                        }
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
}

