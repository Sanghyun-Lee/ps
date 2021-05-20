class KthLargest {
public:
    vector<int> kLargest;

    KthLargest(int k, vector<int>& nums) {
        kLargest = vector<int>();
        if(nums.size() > 0){
            // 전달 받은 배열을 정렬하고
            sort(nums.begin(), nums.end(), greater<int>());

            // 큰 수부터 vector에 넣는다
            for(vector<int>::iterator it = nums.begin(); 
                it < nums.begin() + k && it != nums.end(); it++) {
                kLargest.push_back(*it);
            }
        }

        // 빈 공간은 INT_MIN으로 채운다
        for(int i = kLargest.size(); i < k; i++) {
            kLargest.push_back(INT_MIN);
        }
    }
    
    int add(int val) {
        int k = kLargest.size();

        // val가 현재 위치의 값보다 크면 해당 위치에 삽입한다. (정렬된 상태 유지)
        for(int i = 0; i < k; i++) {
            if(val >= kLargest[i]) {
                kLargest.insert(kLargest.begin() + i, val);
                break;
            }
        }
        // 다시 배열의 크기를 조절하고 k-1위치를 return
        kLargest.resize(k);
        return kLargest[k - 1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */