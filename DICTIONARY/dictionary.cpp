#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;
vector<int> seen, order;

void makeGraph(const vector<string>& words) {
    adj = vector<vector<int> >(26, vector<int>(26, 0));

    for (int j = 1; j < words.size(); j++) {
        int i = j - 1;
        int len = min(words[i].size(), words[j].size());

        for (int k = 0; k < len; k++) {
            if (words[i][k] != words[j][k]) {
                int a = words[i][k] - 'a';
                int b = words[j][k] - 'a';
                adj[a][b] = 1;
                break;
            }
        }
    }
}

void dfs(int here) {
    seen[here] = true;

    for (int there = 0; there < adj[here].size(); there++) {
        if (adj[here][there] && !seen[there])
            dfs(there);
    }
    order.push_back(here);
}

vector<int> topologicalSort() {
    int m = adj.size();
    seen = vector<int>(m, 0);
    order.clear();

    for (int i = 0; i < m; i++) {
        if (!seen[i])
            dfs(i);
    }
    reverse(order.begin(), order.end());

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (adj[order[j]][order[i]])
                return vector<int>();
        }
    }
    return order;
}

int main() {
    int testCase;

    cin >> testCase;

    while (testCase--) {
        int n;
        cin >> n;
        vector<string> words(n, "");

        for (int i = 0; i < n; i++) {
            cin >> words[i];
        }

        makeGraph(words);
        vector<int> result;
        result = topologicalSort();

        if (result.empty())
            cout << "INVALID HYPOTHESIS" << endl;
        else {
            for (int i = 0; i < result.size(); i++) {
                cout << char(result[i] + 'a');
            }
            cout << endl;
        }
            
    }
    return 0;
}