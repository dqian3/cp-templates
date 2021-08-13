#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


vector<int> primes(ll n)
{
    vector<int> primes;
    bool sieve[n + 1] = {};
    
    for (ll i = 2; i <= n; i++) {
        if (!sieve[i]) {
            for (ll j = i * i; j <= n; j += i) {
                sieve[j] = true;
            }

            primes.push_back(i);
        }
    }

    return primes;
}

pair<ll, ll> fibmodpair(ll n, ll mod)
{
    if (n == 0) {
        return {0, 1};
    }
    
    pair<ll, ll> res = fibmodpair(n / 2, mod);

    ll fnm1 = res.second - res.first;
    fnm1 = (fnm1 % mod + mod) % mod; // might be negative
    ll fn = res.first;
    ll fn1 = res.second;
    
    ll f2n = ((fnm1 * fn) % mod  + (fn * fn1) % mod) % mod;
    ll f2n1 = ((fn * fn) % mod  + (fn1 * fn1) % mod) % mod;

    if (n % 2 == 0) {
        return {f2n, f2n1};
    } else {
        return {f2n1, (f2n + f2n1) % mod};
    }
}

ll fibmod(ll n, ll c)
{
    return fibmodpair(n, c).first;
}


ll powmod(ll a, ll b, ll c)
{
    ll cur = 1;
    ll binexp = a;

    while (b > 0) {
        if (b & 1) {
            cur = (cur * binexp) % c;
        } 

        b = b >> 1;
        binexp = (binexp * binexp) % c;
    }
    return cur % c;
}

ll gcd(ll a, ll b)
{
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b; // Order to help prevetn overflow
}

ll gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}