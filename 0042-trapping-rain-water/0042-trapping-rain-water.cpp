class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int ans=0,leftmax=0,rightmax=0;
        while(i<=j){
            leftmax=max(leftmax,height[i]);
            rightmax=max(rightmax,height[j]);
            if(leftmax<rightmax){
                ans+=(leftmax-height[i]);
                i++;
            }
            else {
                ans+=(rightmax-height[j]);
                j--;
            }
        }
        return ans;
    }
};