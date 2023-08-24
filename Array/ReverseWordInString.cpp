/*
Description:
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. 
The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. 
Do not include any extra spaces.
=====
Constraints:
(1) 1 <= s.length <= 10^4
(2) s contains English letters (upper-case and lower-case), digits, and spaces ' '.
(3) There is at least one word in s.
(4) Solve it in-place with O(1) extra space.
=====
Example:
Input: s = " a good   example  "
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/
#include<iostream> 
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {

        for(int i=0; i<s.size()-1; i++){
            if(s.at(i)==' ' && s.at(i+1)==' '){
                s.erase(i, 1);
                i--;
            }
        }
        if(s.at(0)!=' '){
            s.insert(0, 1,' ');
        }
        if(s.at(s.size()-1)!=' '){
            s.insert(s.size(), 1,' ');
        }
        
        int front = 0;
        int end = s.size()-1;
        int len = 0;
        int count = (std::count(s.begin(), s.end(), ' ')-1)/2;

        while(count>0){
            while(s.at(front)==' ') front++;
            while(s.at(end)==' ') end--;

            while(s.at(end)!=' '){
                s.insert(front, 1, s.at(end));
                s.erase(end+1, 1);
                len++;
            }
            front+=len;
            len=0;

            while(s.at(front)!=' '){
                s.insert(end+1, 1, s.at(front));
                s.erase(front, 1);
                len++;
            }
            end-=len;
            len=0;
            
            count--;
        }
        return s.substr(1,s.size()-2);
    }
};
int main() { 
    Solution solution;
    std::string str = " Hello   world  c++";

    std::cout << solution.reverseWords(str);
    return 0; 
}