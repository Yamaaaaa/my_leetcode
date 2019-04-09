/*in the solution, we store the array into a 
hash table, so that when we get the first number,
we can find the second number by index but not 
traversing. And the time comlexity turn to O(n)
from O(n^2). 
Collison that the algorithm cause 
is easy to solute if you choose an appropriate 
hash table*/

class Solution{
    public vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int,int> table;
        for(int i=0;i<nums.size();++i){
            table[nums[i]] = i;
        }

        for(int i=0;i<nums.size();++i){
            int second = target - nums[i];
            if(table.contains(second)&&table[second]!=i){
                return vector<int>({i,table[second]});
            }
        }
        return vector<int>();
    }
}
//Runtime: 12 ms, faster than 90.62% of C++ online submissions for Two Sum.
//Memory Usage: 10.4 MB, less than 33.59% of C++ online submissions for Two Sum.
//A more efficient solution is merge two loops and find second number in current
//table but not whole table. The idea is just like brute force 1.1