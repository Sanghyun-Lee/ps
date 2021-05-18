#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <memory.h>

using namespace std;

const int MAX_DISCS = 12;

vector<int> split(string input, char delimiter) {
    vector<int> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(atoi(temp.c_str()));
    }
 
    return answer;
}

int get(int state, int index) {
    return (state >> (index * 2)) & 3;
}

int set(int state, int index, int value) {
    return (state & ~(3 << (index * 2))) | (value << (index * 2));
}

int sgn(int x) {
    if(!x)
        return 0;
    return x > 0 ? 1 : -1;
}

int incr(int x) {
    if(x < 0)
        return x - 1;
    return x + 1;
}

int c[1 << (MAX_DISCS * 2)];

int bidir(int discs, int begin, int end) {
    if(begin == end)
        return 0;
    
    queue<int> q;
    memset(c, 0, sizeof(c));
    q.push(begin);
    c[begin] = 1;
    q.push(end);
    c[end] = -1;

    while(!q.empty()) {
        int here = q.front();
        q.pop();
        int top[4] = {-1, -1, -1, -1};
        for(int i = 0; i < 4; i++) {
            if(top[i] != -1) {
                for(int j = 0; j < 4; j++) {
                    if(i != j && (top[j] == -1 || top[j] > top[i])) {
                        int there = set(here, top[i], j);
                        if(c[there] == 0) {
                            c[there] = incr(c[here]);
                            q.push(there);
                        } else if(sgn(c[there]) != sgn(c[here]))
                            return abs(c[there]) + abs(c[here]) - 1;
                    }

                }
            }
        }
    }
    return -1;
}

int main() {
    int testCase;
    cin >> testCase;

    while(testCase--) {
        int n;
        cin >> n;

        vector<vector<int> > inputs, outputs;
        string strInput;
        for(int i = 0; i < 4; i++) {
            cin.ignore();
            getline(cin, strInput);
            inputs.push_back(split(strInput, ' '));
        }

        for(int i = 0; i < 4; i++) {
            getline(cin, strInput);
            outputs.push_back(split(strInput, ' '));
        }
    }
    return 0;
}