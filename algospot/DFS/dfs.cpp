#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int> > adj;
vector<bool> visited;

void dfs(int here) {
    cout << "DFS visits " << here << endl;
    visited[here] = true;

    for (int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];

        if (!visited[there])
            dfs(there);
    }
}

vector<int> discovered, finished;
int counter;

void dfs2(int here) {
    discovered[here] = counter++;

    for (int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];
        cout << "(" << here << "," << there << ") is a ";

        if (discovered[there] == -1) {
            cout << "tree edge" << endl;
            dfs2(there);
        } else if (discovered[here] < discovered[there]) {
            cout << "forward edge" << endl;
        } else if (finished[there] == 0) {
            cout << "back edge" << endl;
        } else {
            cout << "cross edge" << endl;
        }
    }

    finished[here] = 1;
}

vector<bool> isCurVertex;

int findCurVertex(int here, bool isRoot) {
    discovered[here] = counter++;
    int ret = discovered[here];
    int children = 0;

    for (int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];
        if (discovered[there] == -1) {
            children++;

            int subtree = findCurVertex(there, false);
            if (!isRoot && subtree >= discovered[here])
                isCurVertex[here] = true;
            ret = min(ret, subtree);
        } else {
            ret = min(ret, discovered[there]);
        }
    }

    if (isRoot)
        isCurVertex[here] = (children >= 2);
    return ret;
}

vector<int> sccId;
stack<int> st;
int sccCounter, vertexCounter;

int scc(int here) {
    int ret = discovered[here] = vertexCounter++;

    st.push(here);
    for (int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];

        if (discovered[there] == -1)
            ret = min(ret, scc(there));
        else if (sccId[there] == -1)
            ret = min(ret, discovered[there]);
    }

    if (ret == discovered[here]) {
        while (true) {
            int t = st.top();
            st.pop();
            sccId[t] = sccCounter;
            if (t == here)
                break;
        }
        sccCounter++;
    }
    return ret;
}

vector<int> tarjanSCC() {
    sccId = discovered = vector<int>(adj.size(), -1);
    sccCounter = vertexCounter = 0;
    
    for (int i = 0; i < adj.size(); i++)
        if (discovered[i] == -1)
            scc(i);

    return sccId;
}

void dfsAll() {
    visited = vector<bool>(adj.size(), false);

    for (int i = 0; i < adj.size(); i++) {
        if (!visited[i])
            dfs(i);
    }
}

int main() {
    return 0;
}