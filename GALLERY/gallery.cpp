#include <iostream>
#include <vector>

using namespace std;

int V, E;
const int MAX_V = 1000;
vector<vector<int> > adj;
vector<bool> visited;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;

int installed;

int dfs(int here) {
    visited[here] = true;
    int children[3] = {0, 0, 0};

    for (int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];
        if (!visited[there])
            children[dfs(there)]++;
    }

    if (children[UNWATCHED]) {
        installed++;
        return INSTALLED;
    }

    if (children[INSTALLED])
        return WATCHED;

    return UNWATCHED;
}

int installCamera() {
    installed = 0;
    visited = vector<bool>(V, false);

    for (int u = 0; u < V; u++) {
        if (!visited[u] && dfs(u) == UNWATCHED)
            installed++;
    }  
    return installed;  
}

int main() {
    int testCase;
    cin >> testCase;

    while(testCase--) {
        cin >> V >> E;

        int x, y;
        adj = vector<vector<int> >(V);
        for (int i = 0; i < E; i++) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        cout << installCamera() << endl;
    }
    return 0;
}