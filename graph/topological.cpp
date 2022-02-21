#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


bool dfs2(vector<vector<int>> &g, vector<int> &ans, vector<bool> &sorted, vector<bool> &visited, int cur)
{
    if (sorted[cur]) {
        return true;
    }
    else if (visited[cur]) {
        return false;
    }

    visited[cur] = true;

    for (int next : g[cur]) {
        if (!dfs2(g, ans, sorted, visited, next)) {
            return false;
        }
    }

    sorted[cur] = true;
    ans.push_back(cur);
    return true;

}

bool top_sort(vector<vector<int>> &g, vector<int> &ans) {
    // ans should be empty
    vector<bool> sorted(g.size());
    vector<int> ans;

    for (int i = 0; i < g.size(); i++) {
        if (sorted[i]) continue;

        vector<bool> visited(g.size());
        if (!dfs2(g, ans, sorted, visited, i)) {
            return false;
        }
    }

    reverse(ans.begin(), ans.end());
    return true;
}