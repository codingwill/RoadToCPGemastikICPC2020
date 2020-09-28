#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/19
*/
using namespace std;
using ll = long long int;
 
ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;
 
void solve();
 
ll fastpow(ll x, ll y, ll n = BIG) 
{
    x %= n;
    ll ans = 1;
    while (y > 0) 
    {
        if (y & 1) ans = (ans * x) % n;
        x = (x * x) % n;
        y >>= 1;
    }
    return ans;
}
 
bool sortPairSecond(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}
 
bool sortPairFirst(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
 
bool sortPairFirstDec(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}
  
ll fact(ll n) 
{ 
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = (res * i) % MOD; 
    return res; 
} 
  
ll Combin(ll n, ll r) 
{ 
    return fact(n) / ((fact(r) * fact(n - r)) % MOD); 
} 
 
 
bool MySort(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void solve()
{
    int t;
    cin >> t;
    int total = t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a;
        for (int i = 0; i < n; ++i)
        {
            int x, y;
            cin >> x >> y;
            a.push_back(make_pair(x, y));
        }
        sort(a.begin(), a.end(), sortPairFirst);
        int count = 0;
        int last = 0;
        for (int i = 0; i < n; ++i)
        {   
            if (i == 0)
            {
                last = a[i].first;
                if ((a[i].second - last) % k == 0)
                {
                    count += (a[i].second - last) / k;
                }
                else
                {
                    count += (a[i].second - last) / k + 1;
                }
                last = a[i].second + (a[i].second - last) % k;
            }
            else
            {
                if (last < a[i].second)
                {
                    if (last >= a[i].first)
                    {
                        if ((a[i].second - last) % k == 0)
                        {
                            count += (a[i].second - last) / k;
                        }
                        else
                        {
                            count += (a[i].second - last) / k + 1;
                        }
                        
                    }
                    else
                    {
                        last = a[i].first;
                        if ((a[i].second - last) % k == 0)
                        {
                            count += (a[i].second - last) / k;
                        }
                        else
                        {
                            count += (a[i].second - last) / k + 1;
                        }
                    }
                    last = a[i].second + (a[i].second - last) % k;
                }
                
            }
            //cout << count << ' ';
        }
        //cout << '\n';
        cout << "Case #" << total - t << ": "; 
        cout << count;
        cout << '\n';
    }
}
 
/*
 
6 6
9 10 12 4 7 2
3 4 6 0 1 0
0 0 0 0

4 6 1 2 3 5 

K = 5
1 3
4 5
5 6
6 7
7 8
8 9
*/