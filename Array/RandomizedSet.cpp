/*
Description:
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. 
Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. 
Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements 
(it's guaranteed that at least one element exists when this method is called). 
Each element must have the same probability of being returned.
You must implement the functions of the class 
such that each function works in average O(1) time complexity.
=====
Constraints:
(1) -2^31 <= val <= 2^31 - 1
(2) At most 2 * 10^5 calls will be made to insert, remove, and getRandom.
(3) There will be at least one element in the data structure when getRandom is called.
=====
Example 1:

Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); 
// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); 
// Returns false as 2 does not exist in the set.
randomizedSet.insert(2); 
// Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); 
// getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); 
// Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); 
// 2 was already in the set, so return false.
randomizedSet.getRandom(); 
// Since 2 is the only number in the set, getRandom() will always return 2.
*/
#include<cstdlib> // for rand()
#include<iterator> // for next()
#include<iostream>
#include<unordered_set>
using namespace std;
class RandomizedSet {
    unordered_set<int> randomizedSet;
    // vector<int> randomizedVector;
public:
    RandomizedSet() {
        // no any initial action
    }
    
    bool insert(int val) {
        // pair<unordered_set<int>::iterator, bool> result = this->randomizedSet.insert(val);
        return this->randomizedSet.insert(val).second;
    }
    
    bool remove(int val) {
        return this->randomizedSet.erase(val);
    }
    
    int getRandom() {
        // random_device rd;
        // mt19937 gen(rd());
        // uniform_int_distribution<> dis(0, this->randomizedSet.size()-1);

        // this->randomizedVector.assign(this->randomizedSet.begin(), this->randomizedSet.end());
        // return this->randomizedVector[dis(gen)];
        // return this->randomizedVector[rand()%this->randomizedVector.size()];
        return *next(this->randomizedSet.begin(),rand()%this->randomizedSet.size());
    }
};
int main(){
    RandomizedSet* obj = new RandomizedSet();
    bool param_1 = obj->insert(5);
    bool param_2 = obj->remove(6);
    int param_3 = obj->getRandom();
    cout << param_1 << endl;
    cout << param_2 << endl;
    cout << param_3 << endl;
}
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */