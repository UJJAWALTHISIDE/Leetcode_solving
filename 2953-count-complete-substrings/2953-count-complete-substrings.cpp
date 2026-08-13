class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int n = word.size();
        int ans = 0;
        for(int start=0;start<n;) {
            // Find a valid segment where adjacent chars differ <= 2
            int end=start+1;
            while(end<n && abs(word[end]-word[end-1])<=2) {
                end++;
            }
            // Now [start, end-1] is a valid segment
            for(int len=k;len<=26*k;len+=k){
                if(len>end-start)
                    break;
                vector<int> freq(26, 0);
                int left = start;
                for(int right = start; right < end; right++) {
                    freq[word[right] - 'a']++;
                    // Window size>len
                    if(right - left + 1 > len) {
                        freq[word[left] - 'a']--;
                        left++;
                    }
                    // Window size == len
                    if(right - left + 1 == len) {
                        bool complete = true;
                        for(int i = 0; i < 26; i++) {
                            if(freq[i] != 0 && freq[i] != k) {
                                complete = false;
                                break;
                            }
                        }
                        if(complete) {
                            ans++;
                        }
                    }
                }
            }
            start = end;
        }
        return ans;
    }
};