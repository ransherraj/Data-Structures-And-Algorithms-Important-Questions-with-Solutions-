class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int res = words.size();
        vector<bool> alphabets(26);
        
        for( auto letter : allowed ) alphabets[ letter - 'a'] = true;
        
        for(auto word : words){
            for(auto letter : word){
                if( !alphabets[letter - 'a']){
                    res--;
                    break;
                }
            }
        }
        return res;
    }
};
