class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // firstly we gonna create hash map
        unordered_map<string,vector<string>>mp;
        // we need to iterate over here
        for(string wrd:strs)
        {
            string copy = wrd;// storing the copy
            //next sort the copy to get the key 
            sort(copy.begin(),copy.end());
            //now simply use [] operator 
            // has a good property like if the key exists it will simply append the word
            // if the key doesnt exists then it will create an empty vector and append the word there
            mp[copy].push_back(wrd);
        }

        // next we gonna reiterate in map and add the vector to string
        vector<vector<string>>ans;
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;


        
    }
};
