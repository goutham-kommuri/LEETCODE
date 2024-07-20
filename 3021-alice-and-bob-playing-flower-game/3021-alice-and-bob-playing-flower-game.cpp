class Solution {
public:
    long long flowerGame(int n, int m) {
        long long res = 0;
        // x + y is odd
        res = ((long long) n * (long long) m)/2;
        return res;
    }
};