class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;   
        vector<int> tmp;

        // Quickly handle cases where one array is empty
        if (nums1.size() == 0) { nums1 = nums2; }
        else if (nums2.size() == 0) {} 
        else {
            while (i < m && j < n){
                if (nums1[i] < nums2[j] && i < m) { tmp.push_back(nums1[i++]); } 
                else if (j < n || i >= m)         { tmp.push_back(nums2[j++]); } 
            }

            // Fill merged array with elements from remaining vector
            while ( i < m ) { tmp.push_back(nums1[i++]); }
            while (j < n )  { tmp.push_back(nums2[j++]); }

            nums1 = tmp;
        }

    }
};