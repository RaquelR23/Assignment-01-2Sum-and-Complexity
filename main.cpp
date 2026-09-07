#include <iostream>          // Lets us use cout to print things.
#include <vector>            // Lets us use vectors.
#include <unordered_map>     // Lets us use an unordered_map (hash table).
#include <utility>           // Lets us use pair.
using namespace std;         // So we don't have to write std:: every time.


// This function uses the brute-force approach.
// It checks every possible pair of numbers until it finds
// two numbers that add up to the target.
pair<int, int> twoSumBruteForce(const vector<int>& nums, int target)
{
    // The outer loop picks the first number.
    for (int i = 0; i < nums.size(); ++i)
    {
        // The inner loop picks the second number.
        // We start at i + 1 so we don't use the same element twice.
        for (int j = i + 1; j < nums.size(); ++j)
        {
            // Check if the two numbers add up to the target.
            if (nums[i] + nums[j] == target)
            {
                // If they do, return the two indices.
                return {i, j};
            }
        }
    }

    // Return {-1, -1} if no valid pair is found.
    return {-1, -1};
}


// This function uses a hash table to find two numbers
// that add up to the target.
pair<int, int> twoSumHash(const vector<int>& nums, int target)
{
    // Stores each number and the index where we found it.
    // The number is the key and the index is the value.
    unordered_map<int, int> index;

    // Go through each number in the vector.
    for (int i = 0; i < nums.size(); ++i)
    {
        // Figure out what number we need to reach the target.
        // For example, if target = 9 and the current number is 2,
        // we need 7 because 2 + 7 = 9.
        int needed = target - nums[i];

        // Check if we have already seen the number we need.
        if (index.count(needed))
        {
            // If we found it, return its index and the current index.
            return {index[needed], i};
        }

        // Save the current number and its index
        // so we can check it later.
        index[nums[i]] = i;
    }

    // Return {-1, -1} if no valid pair is found.
    return {-1, -1};
}


// This function checks if the indices returned by one of our
// twoSum functions actually give us the target value.
bool isValidResult(const vector<int>& nums, pair<int, int> result, int target)
{
    // Check that both indices are valid.
    if (result.first < 0 || result.second < 0)
    {
        return false;
    }

    // Check that the two indices are different
    // and that their values add up to the target.
    return result.first != result.second &&
           nums[result.first] + nums[result.second] == target;
}


// This function prints the result in a way that makes it
// easy to see the indices, values, and whether the answer is valid.
void printResult(const vector<int>& nums, pair<int, int> result, int target)
{
    // Check if the result is valid.
    bool valid = isValidResult(nums, result, target);

    // If the result is valid, print the indices and values.
    if (valid)
    {
        cout << "Indices: [" << result.first
             << ", " << result.second << "]\n";

        cout << "Values: " << nums[result.first]
             << " + " << nums[result.second]
             << " = " << target << "\n";

        cout << "Valid: Yes\n";
    }
    else
    {
        // Print this if the function did not find a valid pair.
        cout << "No valid pair found.\n";
        cout << "Valid: No\n";
    }
}


// This function runs both approaches on one test case.
void runTest(const vector<int>& nums, int target, int testNumber)
{
    // Print the test number.
    cout << "\n========== Test " << testNumber << " ==========\n";

    // Print the target we are looking for.
    cout << "Target: " << target << "\n";

    // Run the brute-force solution.
    cout << "\nBrute Force:\n";
    pair<int, int> bruteResult = twoSumBruteForce(nums, target);

    // Print the brute-force result.
    printResult(nums, bruteResult, target);

    // Run the hash-based solution.
    cout << "\nHash:\n";
    pair<int, int> hashResult = twoSumHash(nums, target);

    // Print the hash result.
    printResult(nums, hashResult, target);
}


int main()
{
    // --------------------------------------------------
    // Test 1: Required test case from the assignment
    // --------------------------------------------------

    vector<int> nums1 = {
        15, 4, 18, 8, 19, 22, 24, 59,
        59, 20, 18, 12, 36, 42, 9
    };

    int target1 = 24;

    // Run the required test.
    runTest(nums1, target1, 1);


    // --------------------------------------------------
    // Test 2: Simple example
    // --------------------------------------------------

    vector<int> nums2 = {2, 7, 11, 15};

    int target2 = 9;

    // Run the second test.
    runTest(nums2, target2, 2);


    // --------------------------------------------------
    // Test 3: Test with negative numbers
    // --------------------------------------------------

    vector<int> nums3 = {-3, 4, 7, 2};

    int target3 = 1;

    // -3 + 4 = 1
    runTest(nums3, target3, 3);


    // --------------------------------------------------
    // Test 4: Test with duplicate values
    // --------------------------------------------------

    vector<int> nums4 = {3, 3};

    int target4 = 6;
    // The two 3s are different elements even though
    // they have the same value.
    runTest(nums4, target4, 4);


    // --------------------------------------------------
    // Test 5: Pair appears farther into the vector
    // --------------------------------------------------

    vector<int> nums5 = {10, 5, 20, 1, 30, 8};

    int target5 = 28;

    // 20 + 8 = 28
    runTest(nums5, target5, 5);


    // End the program.
    return 0;
}
