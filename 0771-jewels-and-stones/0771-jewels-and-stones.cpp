class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        //basically we have to tell how many charcters which are in jewels they are also in stones too
        //we can do the above ques in 0(1)

        unordered_set<int>hell(jewels.begin(),jewels.end());// creation of an unordered set
        int count = 0;
        for(char s:stones)
        {
            if(hell.count(s))
            {
                count++;
            }
        }
        return count; 
    }
};
