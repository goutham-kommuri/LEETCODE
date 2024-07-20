int speedup =[]{std::ios::sync_with_stdio(0);std::cin.tie(0);return 0;}();
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define VPSS vector<pair<string, string>>
#define VVS vector<vector<string>>
#define VS vector<string>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        VPSS v(n);
        for (int i = 0; i < n; i++) {
            v[i].s = strs[i];
            sort(all(strs[i]));
            v[i].f = strs[i];
        }
        sort(all(v));
        VVS ans;
        VS temp;
        for (int i = 0; i < n - 1; i++) {
            if (v[i].first != v[i + 1].first) {
                temp.push_back(v[i].s);
                ans.push_back(temp);
                temp.clear();
            } else {
                temp.push_back(v[i].second);
            }
        }
        temp.push_back(v[n - 1].second);
        ans.push_back(temp);
        return ans;
    }
};