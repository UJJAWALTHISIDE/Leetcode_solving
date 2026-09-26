class Solution {  
public:  
    string evaluate(string s, vector<vector<string>>& knowledge) {  
        vector<string> form;  
        string ans_main="";  
        for(int i=0;i<s.size();){  
            string ans="";  
            if(s[i]=='('){  
                i++; 
                while(s[i]!=')'){  
                    ans.push_back(s[i]);  
                    i++;  
                }  
            }  
            if(ans!=""){   
                form.push_back(ans);   
            }  
            i++;  
        }  
        unordered_map<string,string> mp;
        for(vector<string> v: knowledge){
            mp[v[0]]=v[1];
        }
        vector<string> forans;  
        for(string s: form){  
            if(mp.find(s)!=mp.end()){
                forans.push_back(mp[s]);
            }
            else{
                forans.push_back("?");
            }
        }  
        int j=0;  
        for(int i=0;i<s.size();i++){  
            if(s[i]=='('){  
                while(s[i]!=')'){  
                    i++;  
                }       
                
                ans_main+=forans[j];  
                j++;  
            }  
            else{  
                ans_main+=s[i];  
            }  
        }  
        return ans_main;  
    }  
};