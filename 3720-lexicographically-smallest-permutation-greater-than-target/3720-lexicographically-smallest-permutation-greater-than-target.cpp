class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        map<char,int>mp;
        for (auto ch : s)mp[ch]++;

        string ans = "";
        int foundBiggerTillThisIndex = -1;
        for (int i = 0 ; i < (int)target.size() ; i++){
            char ch = target[i];
            if((i + 1 < (int)target.size()) && mp[ch] > 0){
                mp[ch]--;
                ans.push_back(ch);

                for (int j = target[i] - 'a' + 1; j < 26 ; j++ ){
                    if (mp[j + 'a'] > 0)foundBiggerTillThisIndex = i ;
                }
            }else{
                //try finding a bigger one ;
                bool found = false;
                for (int j = target[i] - 'a' + 1; j < 26 ; j++ ){
                    if(mp[j + 'a'] > 0){
                        found = true;
                        mp[j + 'a']--;
                        ans.push_back(j + 'a');

                        for (auto [x , y] : mp){
                            for (int k = 1 ; k <= y ; k++)ans.push_back(x);
                        }
                        return ans;
                    }
                }

                if (!found){
                    // go for a smaller one;
                    if(foundBiggerTillThisIndex == -1)return "";

                    while(ans.size() > foundBiggerTillThisIndex){
                        mp[ans.back()]++;
                        ans.pop_back();
                    }
                    for (int j = target[foundBiggerTillThisIndex] - 'a' + 1; j < 26 ; j++ ){
                        if(mp[j + 'a'] > 0){
                            mp[j + 'a']--;
                            ans.push_back(j + 'a');
                            for (auto [x , y] : mp){
                                for (int k = 1 ; k <= y ; k++ ){
                                    ans.push_back(x);
                                }
                            }

                            return ans;
                        }
                    }
                }
            }
        }

        return ans;
    }
};