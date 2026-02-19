/*
===============================================================================
TWO SUM PROBLEM
===============================================================================

Question:
Given an array of integers nums and an integer target, return indices of the
two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may
not use the same element twice.

You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:
- 2 <= nums.length <= 10^4
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9
- Only one valid answer exists.

===============================================================================
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Approach 1: Brute Force - O(n^2) time, O(1) space
// This checks every pair of numbers to find the two that sum to target
vector<int> twoSumBruteForce(vector<int> &nums, int target)
{
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      // Check if the sum of current pair equals target
      if (nums[i] + nums[j] == target)
      {
        return {i, j};
      }
    }
  }
  return {}; // No solution found
}

// Approach 2: Hash Map (Optimal) - O(n) time, O(n) space
// Uses a hash map to store seen numbers and their indices
// For each number, check if (target - current) exists in the map
vector<int> twoSumHashMap(vector<int> &nums, int target)
{
  unordered_map<int, int> map; // Stores value -> index

  for (int i = 0; i < nums.size(); i++)
  {
    int complement = target - nums[i];

    // Check if complement exists in the map
    if (map.find(complement) != map.end())
    {
      // Found the pair! Return indices
      return {map[complement], i};
    }

    // Store current number and its index
    map[nums[i]] = i;
  }

  return {}; // No solution found
}

int main()
{
  // Test Case 1
  vector<int> nums1 = {2, 7, 11, 15};
  int target1 = 9;
  cout << "Test Case 1:" << endl;
  cout << "Input: nums = [2, 7, 11, 15], target = 9" << endl;

  vector<int> result1 = twoSumHashMap(nums1, target1);
  cout << "Output: [" << result1[0] << ", " << result1[1] << "]" << endl;
  cout << "Explanation: nums[0] + nums[1] = 2 + 7 = 9" << endl
       << endl;

  // Test Case 2
  vector<int> nums2 = {3, 2, 4};
  int target2 = 6;
  cout << "Test Case 2:" << endl;
  cout << "Input: nums = [3, 2, 4], target = 6" << endl;

  vector<int> result2 = twoSumHashMap(nums2, target2);
  cout << "Output: [" << result2[0] << ", " << result2[1] << "]" << endl;
  cout << "Explanation: nums[1] + nums[2] = 2 + 4 = 6" << endl
       << endl;

  // Test Case 3 (Duplicate values)
  vector<int> nums3 = {3, 3};
  int target3 = 6;
  cout << "Test Case 3:" << endl;
  cout << "Input: nums = [3, 3], target = 6" << endl;

  vector<int> result3 = twoSumHashMap(nums3, target3);
  cout << "Output: [" << result3[0] << ", " << result3[1] << "]" << endl;
  cout << "Explanation: nums[0] + nums[1] = 3 + 3 = 6" << endl
       << endl;

  // Test Case 4 (User input)
  cout << "=== User Input Test ===" << endl;
  vector<int> userNums;
  int n, target;

  cout << "Enter the number of elements: ";
  cin >> n;

  cout << "Enter " << n << " numbers: ";
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    userNums.push_back(x);
  }

  cout << "Enter target sum: ";
  cin >> target;

  vector<int> result = twoSumHashMap(userNums, target);

  if (!result.empty())
  {
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    cout << "Values: " << userNums[result[0]] << " + " << userNums[result[1]]
         << " = " << target << endl;
  }
  else
  {
    cout << "No solution found!" << endl;
  }

  return 0;
}

/*
===============================================================================
SOLUTION EXPLANATION
===============================================================================

Approach 1: Brute Force
- Loop through each element
- For each element, loop through all remaining elements
- Check if their sum equals target
- Time Complexity: O(n²) - nested loops
- Space Complexity: O(1) - no extra space used

Approach 2: Hash Map (Optimal Solution)
- Use an unordered_map to store each number and its index
- For each number, calculate complement (target - current number)
- Check if complement exists in the map
- If yes, we found our pair!
- If no, add current number to map and continue
- Time Complexity: O(n) - single pass through array
- Space Complexity: O(n) - for the hash map

Why Hash Map is better:
- Reduces time complexity from O(n²) to O(n)
- Uses extra space but significantly improves performance
- This is the standard optimal solution for Two Sum problem

Key Insight:
Instead of checking all pairs (which is slow), we use the complement:
If we need a + b = target, then b = target - a
So when we see 'a', we just need to check if 'target - a' was seen before!
===============================================================================
*/

/*
===============================================================================
OUTPUT (Compile & Run: g++ two_sum.cpp -o two_sum && ./two_sum)
===============================================================================

Test Case 1:
Input: nums = [2, 7, 11, 15], target = 9
Output: [0, 1]
Explanation: nums[0] + nums[1] = 2 + 7 = 9

Test Case 2:
Input: nums = [3, 2, 4], target = 6
Output: [1, 2]
Explanation: nums[1] + nums[2] = 2 + 4 = 6

Test Case 3:
Input: nums = [3, 3], target = 6
Output: [0, 1]
Explanation: nums[0] + nums[1] = 3 + 3 = 6

===============================================================================
*/
