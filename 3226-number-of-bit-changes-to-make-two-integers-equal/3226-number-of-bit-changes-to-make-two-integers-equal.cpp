class Solution {
public:
    int minChanges(int n, int k) {
        k ^= n;
        int cnt = __builtin_popcount(k);
        k &= n;
        return cnt == __builtin_popcount(k) ? cnt : -1;
    }
};