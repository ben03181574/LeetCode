/*
Description:
Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.
=====
Constraints:
(1) 1 <= s.length <= 10^4
(2) s consists of only English letters and spaces ' '.
(3) There will be at least one word in s.
=====
Example:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
*/
#include<iostream> 
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int len = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(s.at(i)==' ' && len>0){
                return len;
            }else if(s.at(i)==' ' && len==0){
                continue;
            }else{
                len+=1;
            }
        }
        return len;
    }
};
int main() { 
    Solution solution;
    string str = " Hello C++ World  ";

    std::cout << solution.lengthOfLastWord(str);
    return 0; 
}