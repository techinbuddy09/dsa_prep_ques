class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int>need;
        unordered_map<char,int>window;

        //sabse phele the first needed characters frequency map
        for(char ch:t)
        {
            need[ch]++;
        }

        int left = 0; //left boundary
        int required = need.size();// the required count of characters
        int formed = 0;//to keep the attendence of the charcters enter window
        int min_len = INT_MAX;//min length of the substring
        int start = 0;// to store the index of best ans 

        //firstly lets create the window
        for(int right  = 0;right<s.size();right++)
        {
            //lets expand window by entering the charcters from left
            window[s[right]]++;

            // next we need to mark attendence to na
            if(need.count(s[right]) && window[s[right]] == need[s[right]])
            {
                //phele required char ha na phir dono ki freq satisfy toh yes mark attendence
                formed++;
            }

            //next if we have a valid window
            while(formed == required)
            {

                // before removing we need to store the ans
                if(right - left+1 < min_len)
                {
                    min_len = right-left+1;
                    start =  left;
                }
                // phele absent mark then remove
                if(need.count(s[left]) && window[s[left]] == need[s[left]])
                {
                    //like already counted na
                    // phir satisfy na
                    formed--;
                }
                // next we gonna remove the character from here
                window[s[left]]--;
                left++;//move both the two pointers
            }
        }

        if( min_len == INT_MAX)
                return ""; // return empty string if no such string found na
        // else return 
        return s.substr(start,min_len);//samaj jao string yaha par baneghi        

        
    }
};
// here in this question the frequency of charcters it doesnt matter here it just matters that we need to have all the characters theek
// here we can include duplicates too 

// IMP intuittion:
//so basically its like if we have satisfied the requirement once and increased the counter and the smae charcter apperas again we dont need to increase the counter as like this requirement its already ful filled na mtlb abc ki attence eak baar toh leli ha ab agar aa phirse window mein enter we wont take it attendence again as its counted once na