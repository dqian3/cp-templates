#include <bits/stdc++.h>

#define NOOP INT_MAX

using namespace std;

typedef long long ll;

// Segment tree that supports assignment over ranges with lazy propagation

struct st {

    int size;
    int n;

    vector<ll> ops; 

    int op(int a, int b) {
        if (b == NOOP) return a;
        return b;
    }

    void propagate(int x, int l, int r)
    {
        if (l == r) {
            return;
        }

        ops[2*x] = op(ops[2*x], ops[x]);
        ops[2*x + 1] = op(ops[2*x + 1], ops[x]);
        ops[x] = NOOP;
    }

    void build(const vector<int> &arr, int x, int l, int r) {
        if (l == r) {
            if (l < n)
                ops[x] = arr[l];
            return;
        }
    
        int m = (l + r) / 2;
        build(arr, 2 * x, l, m);
        build(arr, 2 * x + 1, m + 1, r);
        ops[x] = NOOP;
    }

    void modify(int x, int val, int tl, int tr, int l, int r)
    {
        propagate(x, l, r);
        if (tr < l || tl > r) return;

        if (tl <= l && r <= tr) {

            // printf("(%d %d) =%d\n", l, r, val);
            ops[x] = op(ops[x], val);
            return;
        }

        int m = (l + r) / 2;
        modify(2 * x, val, tl, tr, l, m);
        modify(2 * x + 1, val, tl, tr, m + 1, r);

    }

    void modify(int val, int tl, int tr)
    {
        modify(1, val, tl, tr, 0, size - 1);
    }

    int get(int x, int i, int l, int r)
    {
        propagate(x, l, r);
        if (l == r) return ops[x];

        int m = (l + r) / 2;
        int res;
        if (i <= m) {
            res = get(2 * x, i, l, m);
        } else {
            res = get(2 * x + 1, i, m + 1, r);
        }

        return res;
    }

    int get(int i) {
        return get(1, i, 0, size - 1);
    }

    void init(const vector<int> &arr) {
        n = arr.size();
        size = 1;
        while (size < n) size *= 2;

        ops.resize(2 * size);

        build(arr, 1, 0, size - 1);
    }

    void print() {
        int i = 0;
        int j = 0;

        printf("---segtree size %d---:\n", size);
        while (j + 1 < size * 2) {    
            int next = j + (1 << i);
            for (; j < next; j++) {
                printf("%d ", ops[j + 1]);
            }
            printf("\n");
            i++;
        }
    }
};



