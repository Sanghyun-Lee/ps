#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

map<vector<int>, int> toSort;

void precalc(int n) {
    vector<int> perm(n);
    for (int i = 0; i < n; i++)
        perm[i] = i;
    
    queue<vector<int> > q;
    q.push(perm);
    toSort[perm] = 0;

    while(!q.empty()) {
        vector<int> here = q.front();
        q.pop();

        int cost = toSort[here];

        for(int i = 0; i < n; i++) {
            for(int j = i + 2; j <= n; j++) {
                reverse(here.begin() + i, here.begin() + j);
                if (toSort.count(here) == 0) {
                    toSort[here] = cost + 1;
                    q.push(here);
                }

                reverse(here.begin() + i, here.begin() + j);
            }
        }
    }
}

int solve(const vector<int>& perm) {
    int n = perm.size();
    vector<int> fixed(n);

    for(int i = 0; i < n; i++) {
        int smaller = 0;
        for(int j = 0; j < n; j++) {
            if(perm[j] < perm[i])
                smaller++;
        }
        fixed[i] = smaller;
    }
    return toSort[fixed];
}

int main() {
    int testCase;
    cin >> testCase;

    while(testCase--) {
        int n;
        cin >> n;

        int num = 0;
        vector<int> inputs(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> inputs[i];
        }
        precalc(n);
        cout << solve(inputs) << endl;
        
    }

    return 0;
}