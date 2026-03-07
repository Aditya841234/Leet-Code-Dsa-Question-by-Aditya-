class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies using unordered_map
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Use a min-heap to keep top k frequent elements
        // The heap stores pairs (frequency, value) and orders by frequency
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto& entry : freq) {
            int number = entry.first;
            int count = entry.second;

            minHeap.push({count, number}); // push frequency first for correct ordering

            // If heap size exceeds k, remove the smallest frequency
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Step 3: Build the answer vector
        vector<int> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second); // take the number
            minHeap.pop();
        }

        // The result can be returned in any order
        return ans;
    }
};