class Solution {
public:
    int countStaircase(vector<int>& v) {
        int n = v.size(), p = 0, ans = 0;
        while ((p + 1) * (p + 2) / 2 <= n) p++;
        vector<int> srt(v), id(n), cnt(n, 0), pos(n, 0), seen;
        sort(srt.begin(), srt.end());
        for (int i = 0; i < n; i++) id[i] = lower_bound(srt.begin(), srt.end(), v[i]) - srt.begin();
        for (int i = 0; i < n; i++) {
            int dist = 0, ok = 0;
            seen.clear();
            for (int j = i; j < n; j++) {
                int x = id[j];
                if (cnt[x]) {
                    int k = pos[x];
                    if (cnt[x] == k) ok--;
                    if (++cnt[x] > k) break;
                    if (cnt[x] == k) ok++;
                } else {
                    if (dist == p) break;
                    seen.push_back(x);
                    pos[x] = ++dist;
                    cnt[x] ++;
                    if (dist == 1) ok++;
                }
                if (ok == dist) ans++;
            }
            for (int x : seen) cnt[x] = 0;
        }
        return ans;
    }
};