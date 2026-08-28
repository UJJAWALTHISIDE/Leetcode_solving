class Solution{
    int compare(string&left,vector<int>&cnt,char mid,string&target){
        int n=target.size();
        int m=n/2;
        string half=left;
        for(int c=25;c>=0;--c){
            half.append(cnt[c],char('a'+c));
        }
        for(int i=0;i<m;++i){
            if(half[i]>target[i]){
                return 1;
            }
            if(half[i]<target[i]){
                return -1;
            }
        }
        if(n%2){
            if(mid>target[m]){
                return 1;
            }
            if(mid<target[m]){
                return -1;
            }
        }
        for(int i=m-1;i>=0;--i){
            int pos=n-1-i;
            if(half[i]>target[pos]){
                return 1;
            }
            if(half[i]<target[pos]){
                return -1;
            }
        }
        return 0;
    }
public:
    string lexPalindromicPermutation(string s,string target){
        int cnt[26]={};
        for(char c:s){
            ++cnt[c-'a'];
        }
        int odd=0;
        char mid=0;
        for(int c=0;c<26;++c){
            if(cnt[c]&1){
                ++odd;
                mid=char('a'+c);
            }
        }
        if(odd>1){
            return "";
        }
        vector<int>halfCnt(26);
        for(int c=0;c<26;++c){
            halfCnt[c]=cnt[c]/2;
        }
        int m=s.size()/2;
        string left;
        for(int i=0;i<m;++i){
            bool found=false;
            for(int c=0;c<26;++c){
                if(halfCnt[c]==0){
                    continue;
                }
                --halfCnt[c];
                left.push_back(char('a'+c));
                if(compare(left,halfCnt,mid,target)>0){
                    found=true;
                    break;
                }
                left.pop_back();
                ++halfCnt[c];
            }
            if(!found){
                return "";
            }
        }
        string ans=left;
        if(mid){
            ans.push_back(mid);
        }
        for(int i=m-1;i>=0;--i){
            ans.push_back(left[i]);
        }
        return ans>target?ans:"";
    }
};