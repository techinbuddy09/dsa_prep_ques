class Solution {
public:
    bool checkInclusion(string s1, string s2) {

    if(s1.length() > s2.length())
            return false;// like unequal length means not valid => return false
    // we gonna create the two hash maps
    unordered_map<char,int>need;
    unordered_map<char,int>curr_window;

    //firstly we will create oyr first required frequency map
    for(char ch:s1)
    {
        need[ch]++;
    }

  // next hashmap for the current window
  // we need to create first fixed sliding window of s1 string
    for(int i = 0;i<s1.size();i++)
    {
        curr_window[s2[i]]++;
    }        

    // before sliding the window we compare like the first window can also be valid na
    if(need == curr_window){
            return true;}

    // else now we slide and try for the other windows
    // i is currently left at last idx of s1
    for(int i = s1.size();i<s2.size();i++)
    {
        // firstly we enter the new element in the window
         curr_window[s2[i]]++;

         // next we remove the cahrcter windows size times behind
          curr_window[s2[i-s1.size()]]--;

          // next also we always compare the frequencies na so hash map mein kisi ki freq 0 usse bhi erase kardo

          if(curr_window[s2[i-s1.size()]] == 0)
                curr_window.erase(s2[i-s1.size()]);

        // next compare after removing and deleteing element    
            if(need == curr_window)
                return true;    
    }
    // if iterted entire and didnt found any 
    return false;        

    }
};

