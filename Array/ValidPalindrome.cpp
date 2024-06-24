/*
Description:
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and
removing all non-alphanumeric characters, it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
=====
Constraints:
(1) 1 <= s.length <= 2 * 10^5
(2) s consists only of printable ASCII characters.
=====
Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = "a9"
Output: false
Explanation: "a9" is not a palindrome.
*/
#include<iostream> 
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int right = s.size() - 1;
        int left = 0;
        
        while(right>left){
            if(!std::isalnum(s[right])){
                right--;
                continue;
            }
            if(!std::isalnum(s[left])){
                left++;
                continue;
            }
            if(tolower(s[right]) != tolower(s[left])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
int main() { 
    Solution solution;
    string str = "A man, a plan, a canal: Panama";

    std::cout << solution.isPalindrome(str);
    return 0; 
}