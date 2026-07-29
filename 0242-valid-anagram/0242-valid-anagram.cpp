class Solution {
    //An anagram is a string formed by rearranging the characters of another string, where both strings contain exactly the same characters with the same frequency.
public:
    bool isAnagram(string s, string t) {
        
        //so we gonna use hashmap for this

        // edge case
        if(s.size()!= t.size())
                return false;

        unordered_map<char,int>mp;

        //lets traverse in string s and incresase the frequency
        for(char ch:s)
        {
            mp[ch-'a']++;
        }        

        // now lets traverse in string t and reduce the frequency if same charctre found
        for(char ch:t)
        {
            mp[ch-'a']--;

            //edge case here if-v3 freq means koi eak charcater zyada ha iss string mein => not an anagram
            if(mp[ch-'a'] < 0)
                    return false;
        }
        // else agar sab sahi raha sari frequencies 0 hoo gayi mtlb all characters match => return true

        return true;
    }
};
