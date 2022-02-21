#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


bool dfs(vector<vector<int>> &g, vector<int> &coloring, int cur, int color)
{
    if (coloring[cur] != 0) {
        return coloring[cur] == color;
    }

    coloring[cur] = color;

    bool ret = true;
    for (int next : g[cur]) {
        ret &= dfs(g, coloring, next, color * -1);
    }
    return ret;
}


bool coloring(vector<vector<int>> &g, vector<int> &coloring)
{
    // Coloring should be initialized to all 0s
    for (int i = 0; i < g.size(); i++) {
        if (coloring[i] != 0) continue;

        if (!dfs(g, coloring, i, 1)) {
            printf("NO\n");
            return false;
        }
    }

    return true;
}
