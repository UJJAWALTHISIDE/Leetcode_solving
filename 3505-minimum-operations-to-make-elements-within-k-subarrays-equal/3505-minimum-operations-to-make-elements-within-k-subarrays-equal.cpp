class Solution {
public:
    int n, x, k;

    long long minOpsSubarray[100001];
    //minOpsSubarray[i] = min operations reauired to make all elements of subarray[i...i+x-1] as equal

    long long memo[16][100001];

    long long solve(int count, int i) {
        if(count == k)
            return 0;
        
        int subArraysNeeded = k-count;
        int elementsNeeded  = subArraysNeeded*x;
        int lastIndex       = i + elementsNeeded - 1;

        if(lastIndex >= n) {
            return 1e16; //10^16
        }

        if(memo[count][i] != -1) {
            return memo[count][i];
        }

        //Took ith index as start of a subarray
        long long result = minOpsSubarray[i] + solve(count+1, i+x);


        //Skip index i
        result = min(result, solve(count, i+1));

        return memo[count][i] = result;

    }

    long long minOperations(vector<int>& nums, int x, int k) {
        this->n = nums.size();
        this->x = x;
        this->k = k;

        memset(memo, -1, sizeof(memo));

        multiset<int> left, right;
        long long leftSum = 0, rightSum = 0;

        int i = 0;
        int j = 0;

        while(j < n) {
            if(left.size() <= right.size()) {
                left.insert(nums[j]);
                leftSum += nums[j];
            } else {
                right.insert(nums[j]);
                rightSum += nums[j];
            }

            //Balancing
            if(!left.empty() && !right.empty()) {
                int maxLeft  = *left.rbegin();
                int minRight = *right.begin();

                if(maxLeft > minRight) {
                    left.erase(left.find(maxLeft));
                    right.erase(right.find(minRight));

                    left.insert(minRight);
                    right.insert(maxLeft);

                    leftSum += minRight - maxLeft;
                    rightSum += maxLeft - minRight;
                }
            }

            //If we have found the subarray of size x
            if(j-i+1 == x) {
                long long median = *left.rbegin();
                long long leftSize = left.size();
                long long rightSize = right.size();

                minOpsSubarray[i] = (leftSize * median - leftSum) + (rightSum - rightSize*median);

                if(left.find(nums[i]) != left.end()) {
                    left.erase(left.find(nums[i]));
                    leftSum -= nums[i];
                } else {
                    right.erase(right.find(nums[i]));
                    rightSum -= nums[i];
                }
                i++;
            }

            j++;
        }

        return solve(0, 0); //recursion
    }
};
