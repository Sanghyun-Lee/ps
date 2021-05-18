#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
int N;
const int MAX_N = 10000;
const int INF = 987654321;
vector<pair<int, double> > adj[MAX_N];

vector<double> dijkstra(int src) {
    vector<double> dist(N, numeric_limits<double>::max());
    dist[src] = 1.0;
    priority_queue<pair<double, int> > pq;
    pq.push(make_pair(-1.0, src));

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here] < cost)
            continue;
        
        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            double nextDist = cost + adj[here][i].second;

            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}

int main() {
    int testCase;
    cin >> testCase;

    while(testCase--) {
        int m;
        cin >> N >> m;

        for(int i = 0; i < N; i++) {
            adj[i].clear();
        }

        int a, b;
        double c;
        for(int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            adj[a].push_back(make_pair(b, c));
            adj[b].push_back(make_pair(a, c));
        }
        cout << dijkstra(0)[N - 1] << endl;
    }
    return 0;
}