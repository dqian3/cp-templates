#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Basic Segment tree that supports updates and range queries

#define IDENT 0

struct st {

    int size;
    int n;

    vector<ll> vals; 

	ll op(ll a, ll b) {
		return a + b;
	}

    void build(const vector<int> &arr, int x, int lx, int rx) {
        if (lx == rx) {
            if (lx < n)	
                vals[x] = arr[lx];
			else 
				vals[x] = IDENT;
            return;
        }
    
        int mx = (lx + rx) / 2;
        build(arr, 2 * x, lx, mx);
        build(arr, 2 * x + 1, mx + 1, rx);
        vals[x] = op(vals[2*x], vals[2*x + 1]);
    }

    void modify(int x, int i, int v, int lx, int rx)
    {
		if (lx == rx) {
			vals[x] = v;
		} else {
			int mid = (lx + rx) / 2;
			if (i <= mid) {
				modify(2*x, i, v, lx, mid);
			} else {
				modify(2*x + 1, i, v, mid + 1, rx);
			}
			vals[x] = op(vals[2*x], vals[2*x + 1]);
		}
    }

    void modify(int i, int val)
    {
        modify(1, i, val, 0, size - 1);
    }

    int get(int x, int lx, int rx, int l, int r)
    {
		if (r < lx || l > rx) {
			return IDENT;
		}
	
		if (l <= lx && rx <= r) {
			return vals[x];
		}
		int mid = (lx + rx) / 2;
		return op(get(2 * x, lx, mid, l, r),
				get(2 * x + 1, mid + 1, rx, l, r));
    }

    int get(int l, int r) {
        return get(1, 0, size - 1, l, r);
    }

    void init(const vector<int> &arr) {
        n = arr.size();
        size = 1;
        while (size < n) size *= 2;

        vals.resize(2 * size);

        build(arr, 1, 0, size - 1);
    }

    void print() {
        int i = 0;
        int j = 0;

        printf("---segtree size %d---:\n", size);
        while (j + 1 < size * 2) {    
            int next = j + (1 << i);
            for (; j < next; j++) {
                printf("%lld ", vals[j + 1]);
            }
            printf("\n");
            i++;
        }
    }
};
