class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        // This will store our final answer
        vector<int> ans;

        // freq[word] = how many times this word is required
        unordered_map<string, int> freq;

        // Store frequency of every word
        for (string word : words)
            freq[word]++;

        // Length of each word
        int wordSize = words[0].size();

        // Total number of words
        int n = words.size();

        // Total size of the required window
        int windowSize = wordSize * n;


        // We try every possible starting position
        // from 0 to wordSize - 1
        for (int startPos = 0; startPos < wordSize; startPos++) {

            // curr stores words currently inside our window
            unordered_map<string, int> curr;

            // Left side of the sliding window
            int left = startPos;

            // Number of words currently inside the window
            int count = 0;


            // Move right by exactly one word at a time
            for (int right = startPos;
                 right + wordSize <= s.size();
                 right += wordSize) {

                // Take one word from the string
                string word = s.substr(right, wordSize);


                // If this word is not present in words
                // then this window cannot be useful
                if (!freq.count(word)) {

                    // Remove everything from current window
                    curr.clear();

                    // No words are currently in the window
                    count = 0;

                    // Start a new window after this bad word
                    left = right + wordSize;

                    // Go to the next word
                    continue;
                }


                // Add this word to our current window
                curr[word]++;

                // We have one more word in the window
                count++;


                // If this word occurs more times than required
                // remove words from the left side
                for (; curr[word] > freq[word]; count--) {

                    // Take the leftmost word
                    string leftWord = s.substr(left, wordSize);

                    // Remove it from current window
                    curr[leftWord]--;

                    // Move left forward by one word
                    left += wordSize;
                }


                // If we have exactly n words
                // then we found a valid answer
                if (count == n) {

                    // Add starting index of this window
                    ans.push_back(left);


                    // Remove the leftmost word
                    // so that we can continue sliding
                    string leftWord = s.substr(left, wordSize);

                    curr[leftWord]--;

                    // Move left forward by one word
                    left += wordSize;

                    // Window now contains n-1 words
                    count--;
                }
            }
        }

        // Return all starting positions
        return ans;
    }
};