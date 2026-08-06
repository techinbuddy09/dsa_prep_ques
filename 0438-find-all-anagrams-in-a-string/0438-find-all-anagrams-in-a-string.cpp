class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;

        //edge case 
        if(p.size() > s.size())
        {
            return ans;
        }

        unordered_map<char,int>need;
        unordered_map<char,int>window;
        
        //lets make the first frequency map

        for(char ch:p)
        {
            need[ch]++;
        }

        //create the first fixed sliding window
        for(int i =0;i<p.size();i++)
        {
            window[s[i]]++;
        }
        
        //now the first window can be a valid anagram

        if(window == need)
        {
            ans.push_back(0);// 0th index na
        }

        //now next we keep on exploring all the valid anagrams
        for(int i = p.size();i<s.size();i++)
        {
            // enter the character like expand the window from right
            window[s[i]]++;

            //next remove te left most character which is window size times behind

            window[s[i-p.size()]]--;

            //next since we have removed the leftmost lets erase it completely if its frequency is 0
            if(window[s[i-p.size()]] == 0)
            {
                window.erase(s[i-p.size()]);
            }

            //next if the two strings same lets add its first indices 
            if(window ==  need )
            {
                ans.push_back(i-p.size()+1);//end_idx-wind_size+1
            }
        }// we are doing +1 for ending index of the current window too

        return ans;
        
    }
};
// find all the anagrams means find all the permutations only yahi mtlb hota ha 
//ans.push_back(i-p.size()+1);
//Why +1?

//Because   i  is the ending index of the current window.

//e need the starting index.

//For a window of size k:

//start = end - k + 1