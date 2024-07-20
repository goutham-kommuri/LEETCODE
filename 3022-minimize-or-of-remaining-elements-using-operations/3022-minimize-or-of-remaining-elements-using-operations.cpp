template <class T> class SP{
private: int N, K; const T O = T(); vector<vector<T>> t;
    T op(T x, T y){return x & y;}
public:
    SP(vector<T> &a) : N(size(a)), K(__lg(N)){
        t.assign(K + 1, vector<T>(N, O)), t[0] = a;
        for(int i = 1; i <= K; i++) for(int j = 0; j + (1 << i) <= N; j++) t[i][j] = op(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);
    }
    int query(int l, int r){
        int k = __lg(r - l + 1);
        return l > r ? O : op(t[k][l - 1], t[k][r - (1 << k)]);
    }
    int xquery(int l, int r){
        T res = O; int k = r - l + 1;
        while(k > 0){
            int p = __lg(k);
            res = op(res, t[p][l - 1]);
            l += (1 << p), k ^= (1 << p);
        }
        return res;
    }
};
class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        SP<int> sp(nums);
        int n = nums.size();
        auto chk = [&](int ans){
            vector<int> dp(n, n);
            auto nxt = [&](int i){
                int lo = i, hi = n - 1, res = -1;
                while (lo <= hi){
                    int mid = (lo + hi) >> 1;
                    if (sp.query(i + 1, mid + 1) & ~ans) lo = mid + 1;
                    else res = mid, hi = mid - 1;
                }
                return res;
            };
            int j = nxt(0);
            if (j == -1) return false;
            dp[j] = j;
            for (int i = j + 1; i < n; i++){
                int k = nxt(i);
                dp[i] = min(dp[i], dp[i - 1] + 1);
                if (k == -1) continue;
                dp[k] = min(dp[k], dp[i - 1] + (k - i));
            }
            return dp[n - 1] <= k;
        };
        int ans = 0;
        for (int i = 0; i < 30; i++) ans |= 1 << i;
        for (int i = 29; i >= 0; i--){
            ans ^= 1 << i;
            if (chk(ans)) continue;
            ans ^= 1 << i;
        }
        return ans;
    }
};