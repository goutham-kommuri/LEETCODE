class Solution {
public:
    int searchInsert(vector<int>& arr, int t) {

        int n = arr.size();

        int low = 0;
        int high = n-1;

        while(low < high) {
            int mid = low + (high-low)/2;
            if(arr[mid] == t) return mid;
            else if(arr[mid] > t) high = mid;
            else low = mid+1;
        }
        
        if(arr[low] < t) return low+1;
        else return low;
    }
};