#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Kuhns algorithm for max bipartite matching
// Based on https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html


int n, k;
vector<vector<int>> g;
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
    if (used[v]) return false;
    used[v] = true;

    for (int to : g[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }

    return false;
}

vector<pair<int, int>> match() {
    vector<pair<int, int>> ret;

    mt.assign(k, -1);
    for (int v = 0; v < n; ++v) {
        used.assign(n, false);
        try_kuhn(v);
    }

    for (int i = 0; i < k; ++i) {
        if (mt[i] != -1) ret.push_back({mt[i], i});
    }

    return ret;
}