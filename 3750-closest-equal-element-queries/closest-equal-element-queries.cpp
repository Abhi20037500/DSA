class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> indexMap;

        for (int i = 0; i < n; i++) {
            indexMap[nums[i]].push_back(i);
        }

        vector<int> answer;

        for (int q : queries) {
            vector<int>& indices = indexMap[nums[q]];

            if (indices.size() == 1) {
                answer.push_back(-1);
                continue;
            }

            // Binary search for position of q in the sorted indices list
            int pos = lower_bound(indices.begin(), indices.end(), q) - indices.begin();
            int minDist = INT_MAX;

            // Check neighbor to the right (wrap around if needed)
            int rightIdx = indices[(pos + 1) % indices.size()];
            int d1 = abs(q - rightIdx);
            minDist = min(minDist, min(d1, n - d1));

            // Check neighbor to the left (wrap around if needed)
            int leftIdx = indices[(pos - 1 + indices.size()) % indices.size()];
            int d2 = abs(q - leftIdx);
            minDist = min(minDist, min(d2, n - d2));

            answer.push_back(minDist);
        }

        return answer;
    }
};