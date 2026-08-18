class Solution {
public:
    int strongPasswordChecker(string password) {
        // 1. Find the length of the password.
        int n = password.size();
        // 2. Check whether lowercase, uppercase and digit are present.
        bool lower = false, upper = false, digit = false;
        for (char c : password) {
            if (islower(c)) lower = true;
            if (isupper(c)) upper = true;
            if (isdigit(c)) digit = true;
        }
        // Count the missing character types.
        int missing = 3 - (lower + upper + digit);
        // 3. Find groups of consecutive identical characters.
        vector<int> groups;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && password[j] == password[i]) {
                j++;
            }
            int len = j - i;
            if (len >= 3) {
                groups.push_back(len);
            }
            i = j;
        }
        // 4. Calculate the total replacements required.
        int replace = 0;
        for (int len : groups) {
            replace += len / 3;
        }
        // 5. If length is less than 6,
        // we need insertions to reach length 6.
        if (n < 6) {
            return max(missing, 6 - n);
        }
        // 6. If length is between 6 and 20,
        // no deletion is required.
        if (n <= 20) {
            return max(missing, replace);
        }
        // 7. If length is greater than 20,
        // these deletions are mandatory.
        int del = n - 20;
        // 8. Use deletions greedily on groups where
        // they can save the maximum number of replacements.
        // First priority:
        // len % 3 == 0
        // One deletion saves one replacement.
        for (int &len : groups) {
            if (del == 0) break;
            if (len % 3 == 0) {
                int use = min(del, 1);
                len -= use;
                del -= use;
                replace -= use;
                replace=max(0,replace);
            }
        }
        // Second priority:
        // len % 3 == 1
        // Two deletions save one replacement.
        for (int &len : groups) {
            if (del == 0) break;
            if (len % 3 == 1) {
                int use = min(del, 2);
                len -= use;
                del -= use;
                replace -= use / 2;
            }
        }
        // Third priority:
        // Use the remaining deletions.
        // Every three deletions can save one replacement.
        for (int &len : groups) {
            if (del == 0) break;
            int use = min(del,(len/3)*3);
            len -= use;
            del -= use;
            replace -= use / 3;
        }
        // 9. Mandatory deletions +
        // remaining replacements or missing character types.
        return (n - 20) + max(missing, replace);
    }
};