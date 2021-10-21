class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int m_idx = m - 1;
        int n_idx = n - 1;

        if (n == 0)
            return;

        for (int i = m + n - 1; i >= 0; i--) {
            if (m_idx < 0) {
                nums1[i] = nums2[n_idx];
                n_idx--;
            } else {
                if (nums1[m_idx] > nums2[n_idx]) {
                    nums1[i] = nums1[m_idx];
                    m_idx--;
                } else {
                    nums1[i] = nums2[n_idx];
                    n_idx--;
                }
            }
            
            if (n_idx < 0)
                return;
        }
    }
};