#include<string.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<iostream>

using namespace std;

int team_num;
vector<pair<int,int> > meetings;
vector<vector<int> > adj;
vector<int> scc_label;

vector<int> visited_order;
stack<int> st;
int order = 0, scc_order = 0;

bool Disjoint(const pair<int,int>& a, const pair<int,int>& b ) {
    return a.second <= b.first || b.second <= a.first;
}

void MakeGraph(){
    adj = vector<vector<int> >(meetings.size() * 2); 

    int month_meeting = 0;
    for(int week_meeting = 0; week_meeting < meetings.size(); week_meeting += 2) {
        month_meeting = week_meeting + 1;
        adj[week_meeting * 2 + 1].push_back(month_meeting * 2);
        adj[month_meeting * 2 + 1].push_back(week_meeting * 2);
        adj[week_meeting * 2].push_back(month_meeting * 2 + 1);
        adj[month_meeting * 2].push_back(week_meeting * 2 + 1);
    }

    for(int i = 0; i < meetings.size(); ++i) {
        for(int j = 0; j < i; ++j) {
            if(!Disjoint(meetings[i], meetings[j])) {
                adj[i * 2].push_back(j * 2 + 1);
                adj[j * 2].push_back(i * 2 + 1);
            }
        }
    }
}

int FindSCC(int now_node) {
    int min_order = visited_order[now_node] = ++order;
    int next_node;
    st.push(now_node);

    for(int i = 0; i < adj[now_node].size(); ++i) {
        next_node = adj[now_node][i];

        if(visited_order[next_node] == -1)
            min_order = min(min_order, FindSCC(next_node));
        else if(scc_label[next_node] == -1)
            min_order = min(min_order, visited_order[next_node]);
    }

    if(min_order == visited_order[now_node]){
        int temp;
        while(1) {
            temp = st.top();
            st.pop();
            scc_label[temp] = scc_order;
            if(temp == now_node)
                break;
        }
        ++scc_order;
    }

    return min_order;
}

void tarjanSCC() {
    visited_order = vector<int>(meetings.size() * 2, -1);
    scc_label = vector<int>(meetings.size() * 2, -1);
    order = 1;
    scc_order = 1;

    for(int i = 0; i < visited_order.size(); ++i)
        if(visited_order[i] == -1)
            FindSCC(i);
}

vector<int> Solve2SAT() {
    int meeting_num = meetings.size();

    tarjanSCC();

    for(int i = 0; i < meeting_num * 2; i += 2)
        if(scc_label[i] == scc_label[i + 1])
            return vector<int>();
    
    vector<int> result(meeting_num * 2, -1);
    vector<pair<int,int> > sat_order;

    for(int i = 0; i < meeting_num * 2; ++i)
        sat_order.push_back(make_pair(-scc_label[i], i));

    sort(sat_order.begin(), sat_order.end());

    for(int i = 0; i < meeting_num * 2; ++i) {
        int vertex = sat_order[i].second;
        int meeting_idx = vertex / 2;
        int is_true = (vertex % 2 == 0);

        if(result[meeting_idx] != -1)
            continue;
        result[meeting_idx] = !is_true; 
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    int test_num;
    cin >> test_num;

    while(test_num--) {
        cin >> team_num;
        meetings = vector<pair<int,int> >(team_num * 2);

        for(int i = 0; i < team_num; ++i) {
            int ws, wd, ms, me;
            cin >> ws >> wd >> ms >> me;

            meetings[2 * i] = make_pair(ws, wd);
            meetings[2 * i + 1] = make_pair(ms, me);
        }

        MakeGraph();

        vector<int> result = Solve2SAT();

        if(result.size() == 0)
            cout << "IMPOSSIBLE" << endl;
        else {
            cout << "POSSIBLE" << endl;
            for(int i = 0; i < meetings.size(); ++i) {
                if(result[i])
                    cout << meetings[i].first << ' ' << meetings[i].second << endl;
            }
        }
    }
    return 0;
}