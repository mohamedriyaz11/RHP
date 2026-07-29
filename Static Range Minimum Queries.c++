#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000005;

int find(const vector<int>& seg, int node, int nl, int nr, int ql, int qr) {
    if (nr < ql || nl > qr)
        return INF;

    if (ql <= nl && nr <= qr)
        return seg[node];

    int mid = (nl + nr) / 2;

    int left = find(seg, 2 * node, nl, mid, ql, qr);
    int right = find(seg, 2 * node + 1, mid + 1, nr, ql, qr);

    return min(left, right);
}

int main() {
    int n, q;
    cin >> n >> q;

    int newn = 1;
    while (newn < n)
        newn <<= 1;

    vector<int> seg(2 * newn, INF);

    for (int i = 0; i < n; i++)
        cin >> seg[newn + i];

    for (int i = newn - 1; i >= 1; i--)
        seg[i] = min(seg[2 * i], seg[2 * i + 1]);

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << find(seg, 1, 1, newn, l, r) << '\n';
    }

    return 0;
}