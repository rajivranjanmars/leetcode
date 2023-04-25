class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // Merge both the sorted arrays into a single array.
        vector<int> merged(m + n);
        int i = 0, j = 0, k = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                merged[k] = nums1[i];
                i++;
            } else {
                merged[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < m) {
            merged[k] = nums1[i];
            i++;
            k++;
        }
        while (j < n) {
            merged[k] = nums2[j];
            j++;
            k++;
        }

        // Sort the merged array.
        sort(merged.begin(), merged.end());

        // Find the median.
        int len = m + n;
        if (len % 2 == 0) {
            int mid1 = len / 2 - 1;
            int mid2 = len / 2;
            return (merged[mid1] + merged[mid2]) / 2.0;
        } else {
            int mid = len / 2;
            return merged[mid];
        }
    }
};

