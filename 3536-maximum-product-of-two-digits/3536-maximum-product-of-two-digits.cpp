class Solution {
public:
    int maxProduct(int n) {
        int largest_digit = 0;
        int sec_largest_digit = 0;
        while(n>0)
        {
            //phele we calc digit
            int digit = n%10;
            n=n/10;

            // now  check
            if(digit > largest_digit)
            {
                //largest_digit = digit;
                sec_largest_digit = largest_digit;
                largest_digit = digit;
            }
            else if(digit > sec_largest_digit)
            {
                sec_largest_digit = digit;
            }

        }
        // now returning the product of the first_largest digit and second largest digit
        return largest_digit*sec_largest_digit;
        
    }
};
// alright we gonna solve this question using two varibales 
// digit1-> holding current largest number
// digit2-> it basically holding the previous largest number
