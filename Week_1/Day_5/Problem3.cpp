#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> strs = {"flower", "flow", "flight"};

    
    sort(strs.begin(), strs.end());

   
    string first = strs[0];
    string last = strs[strs.size() - 1];

    
    int i = 0;
    while(i < first.length() && i < last.length() && first[i] == last[i]){
        i++;
    }

    cout << "Longest Common Prefix: " << first.substr(0, i);

    return 0;
}