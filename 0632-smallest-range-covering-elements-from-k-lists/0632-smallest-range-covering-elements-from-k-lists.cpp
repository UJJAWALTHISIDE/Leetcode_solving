class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Number of lists
        int k = nums.size();
        // Store (number, which list it belongs to)
        vector<pair<int, int>> arr;
        // Put all numbers into one array
        for (int i = 0; i < k; i++) {
            // Go through every number in this list
            for (int num : nums[i]) {
                // Store the number and its list number
                arr.push_back({num, i});
            }
        }
        // Sort all numbers by their value
        sort(arr.begin(), arr.end());
        // freq[i] = how many numbers from list i
        // are currently inside our window
        vector<int> freq(k, 0);
        // How many different lists are currently present
        int count = 0;
        // Left side of sliding window
        int left = 0;
        // Best answer we have found
        int bestLeft = arr[0].first;
        int bestRight = arr.back().first;
        // Move right side of window
        for (int right = 0; right < arr.size(); right++) {
            // Find which list this number belongs to
            int list = arr[right].second;
            // Add this number to our window
            freq[list]++;
            // If this is the first number from this list
            if (freq[list] == 1) {
                // We now have one more different list
                count++;
            }
            // If our window contains all k lists
            while (count == k) {
                // Current range
                int currentLeft = arr[left].first;
                int currentRight = arr[right].first;
                // Check if current range is smaller
                // than our previous best range
                if (currentRight - currentLeft <
                    bestRight - bestLeft) {
                    // Save this range
                    bestLeft = currentLeft;
                    bestRight = currentRight;
                }
                // Remove the leftmost number
                int leftList = arr[left].second;
                freq[leftList]--;
                // If no number from this list
                // is left inside the window
                if (freq[leftList] == 0) {
                    // Window no longer contains all lists
                    count--;
                }
                // Move left forward
                left++;
            }
        }
        // Return the smallest range
        return {bestLeft, bestRight};
    }
};