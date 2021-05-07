#include <iostream>
#include <vector>

using namespace std;
int N, M;

struct BipartiteUnionFind {
    vector<int> parent, rank, enemy, size;
    BipartiteUnionFind (int n): parent(n), rank(n, 0), enemy(n, -1), size(n, 1) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find (int u) {
        if (parent[u] == u)
            return u;

        return parent[u] = find(parent[u]);
    }

    int merge (int u, int v) {
        if (u == -1 || v == -1)
            return max(u, v);

        u = find(u);
        v = find(v);

        if (u == v)
            return u;

        if (rank[u] > rank[v])
            swap(u, v);

        if (rank[u] == rank[v])
            rank[v]++;
        
        parent[u] = v;
        size[v] += size[u];
        return v;
    }

    bool dis (int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return false;

        int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
        enemy[a] = b;
        enemy[b] = a;
        
        return true;
    }

    bool ack (int u, int v) {
        u = find(u);
        v = find(v);

        if (enemy[u] == v)
            return false;

        int a = merge(u, v), b = merge(enemy[u], enemy[v]);
        enemy[a] = b;
        if (b != -1)
            enemy[b] = a;

        return true;
    }
};

int maxParty (const BipartiteUnionFind& buf) {
    int ret = 0;
    for (int node = 0; node < N; node++) {
        if (buf.parent[node] == node) {
            int enemy = buf.enemy[node];

            if (enemy > node)
                continue;

            int mySize = buf.size[node];
            int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
            ret += max(mySize, enemySize);
        }
    }

    return ret;
}

int main() {
    int testCase;
    cin.tie(0);
    cin >> testCase;

    while (testCase--) {
        cin >> N >> M;

        string res;
        int a, b;
        bool isContradict = true;
        BipartiteUnionFind buf(N);
        int count = 0;

        for (int i = 0; i < M; i++) {
            cin >> res >> a >> b;

            if (!isContradict)
                continue;

            if (res == "ACK") {
                if (!buf.ack(a, b)) {
                    isContradict = false;
                    count = i + 1;
                }
            } else {
                if (!buf.dis(a, b)) {
                    isContradict = false;
                    count = i + 1;
                }
            }
        }
        if (isContradict)
            cout << "MAX PARTY SIZE IS " << maxParty(buf) << endl;
        else
            cout << "CONTRADICTION AT " << count << endl;
    }
    return 0;
}