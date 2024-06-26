/*
Description:
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is 
formed from the original string by deleting some (can be none) of the characters 
without disturbing the relative positions of the remaining characters. 

(i.e., "ace" is a subsequence of "abcde" while "aec" is not).
=====
Constraints:
(1) 0 <= s.length <= 100
(2) 0 <= t.length <= 10^4
(3) s and t consist only of lowercase English letters.
=====
Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
*/
#include<iostream> 
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;
        for(char tc : t){
            if(s[index] == tc){
                index++;
            }
        }
        return index==s.size();
    }
};
int main() { 
    Solution solution;

    std::cout << solution.isSubsequence("abc", "ahbgdc");
    return 0; 
}