#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct RNG {
    unsigned seed;
    RNG() : seed(1983) {}
    unsigned next() {
        unsigned ret = seed;
        seed = ((seed * 214013u) + 2531011u);
        return ret % 10000 + 1;
    }
};

int simple(const vector<int>& signals, int k) {
    int ret = 0;

    for (int head = 0; head < signals.size(); head++) {
        int sum = 0;
        for (int tail = head; tail < signals.size(); tail++) {
            sum += signals[tail];
            if (sum == k)
                ret++;
            if (sum >= k)
                break;
        }
    }

    return ret;
}


int optimize(const vector<int>& signals, int k) {
    int ret = 0, tail = 0, rangeSum = signals[0];

    for (int head = 0; head < signals.size(); head++) {
        while (rangeSum < k && tail + 1 < signals.size()) {
            rangeSum += signals[++tail];
            if (rangeSum == k)
                ret++;

            rangeSum -= signals[head];
        }
    }
    return ret;
}

int countRange(int k, int n) {
    RNG rng;
    queue<int> range;

    int ret = 0, rangeSum = 0;

    for (int i = 0; i < n; i++) {
        int newSignal = rng.next();
        rangeSum += newSignal;
        range.push(newSignal);

        while (rangeSum > k) {
            rangeSum -= range.front();
            range.pop();
        }

        if (rangeSum == k)
            ret++;
    }
    return ret;
}

int main() {
    int testCase = 0;
    cin >> testCase;

    while (testCase--) {
        int k, n;
        cin >> k >> n;
        cout << countRange(k, n) << endl;

	}

    return 0;
}