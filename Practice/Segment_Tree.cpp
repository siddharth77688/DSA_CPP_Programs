#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class SegmentTree {
public:
    vector<ll> seg;
    int n;

    // CHANGE 1: Merge operation
    ll merge(ll a, ll b) {
        return a + b;  // SUM
    }

    // CHANGE 2: Identity value
    ll identity = 0;

    void build(int idx, int low, int high, vector<int>& a) {
        if(low == high) {
            seg[idx] = a[low];
            return;
        }

        int mid = (low + high) / 2;

        build(2*idx+1, low, mid, a);
        build(2*idx+2, mid+1, high, a);

        seg[idx] = merge(seg[2*idx+1], seg[2*idx+2]);
    }

    void update(int idx, int low, int high, int pos, int val) {
        if(low == high) {
            seg[idx] = val;
            return;
        }

        int mid = (low + high) / 2;

        if(pos <= mid){
            update(2*idx+1, low, mid, pos, val);
        }else{
            update(2*idx+2, mid+1, high, pos, val);
        }

        seg[idx] = merge(seg[2*idx+1], seg[2*idx+2]);
    }

    ll query(int idx, int low, int high, int l, int r) {
        if(r < low || high < l) {
            return identity;
        }

        if(l <= low && high <= r) {
            return seg[idx];
        }

        int mid = (low + high) / 2;

        return merge(
            query(2*idx+1, low, mid, l, r),
            query(2*idx+2, mid+1, high, l, r)
        );
    }

    SegmentTree(vector<int>& a) {
        n = a.size();
        seg.resize(4*n);
        if(n >=1 ){
            build(0, 0, n-1, a);
        }
    }
};