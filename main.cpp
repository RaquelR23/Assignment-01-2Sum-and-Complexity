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
https://adclick.g.doubleclick.net/pcs/click?xai=AKAOjsvcISYHQhu8xwSdLofA0O9dIOEl_AMHD78jdl_GIeu1hwSkHoywL8EvjNXo_kVGmIgWUwBEBNRtQ-G7tzt2SGGRxLEmmMFNNrrjl0zezvto5QmYmFHD51iH-gzuxS11lwHyBagi-3w5ViyM-4EiiP8Lum1oT2fhxT4dfv37q5NvTB0-yrdvBceoS0mn1vgkLDMcn6Q7MaNs05L15gf7EiNZW6yURa2TJaeAgQSgKeSqMzY-a4hSvKwC6RNrl-oYXi74_MIzWW3g5ZbB7aELbg6yBLfgb56OdWHoUF9pxNwS55-YjSuqJGGBmVr8t8f-0MQ8lhF61gVc65EAur-h3J4H_V1UDo9GCH-YbnBnqJd5ujeO4bjE1xuYvQ3687C0MK9i4x6VUajBNOO6xGfCmk3N0hmahxI8mY15ojHcPWaT6av2uc_YIWoA825yTF8AhXQvJYZ8kzsb8JFALgB0AnbmWtnB1PLljvC6mvLo-7c_4VrXParcb6lehkXa4tnx6Pj_L9Z8bvdnGd-JD3yMInSMu16KG_KHzXJ6XE_kjLh5Y4tTwOfgHp_EkfHey1cSClXc5bK7p07bCF-xRrYf0Ms1sej-lqRQAjIUeZS0JFSV8bw4gZsei0hz-Pp6CsyDV0ZXv6XQwihuGmKHyfrEPcOvCHEhhK4tAc_jCAvVpIyrxVN_CqRbovFKM3FjrNqr-CMmDYTtFVzuaIccRqm5xlCnKzSxwV56luvtJlTDVzwiq7P3vvlf45fY_fnWlYkCYUHBd8h76Mrt0VGfmshwFeklNoXVP02l4600wQnLAFEc2DpI4rwWUJIUXC8SeJw8JjWCwlfNxbmeq31eRpPB3d6RZqgg7XqzhyB6fLiSinqBw0IiYsaqzrm2P-sl54Rsbh4mlioo3NBk0zCWsVZGj52v0HK5ndlU1xxjqvcbagrWKrdq0BYFZHgPJl9AMM8ZxGouUPmXjWQqWiI-AnKpVBSJeKfkLvVKSCyjF2Vud_TgMlOMYyZCis7UFCdRfAk5Y_cyrL3nhERwiYJuK60MepI0E2uQWxwZyVx61UwUB4sfalfEG9xryaPnkeadxGc9x6wOu6pr2n_BWZQ3kySutJ0_uD8RiGTxjj07m3syowcEjsFkhaVdpD_kR1FQ0ZYM0ac74ADoO2RcpKxNhKOPAU1DTktd0hI5TbanLuiqVwqjYWSrXM0RafnB2_hwvDEOfNw_9tE8kSrezbIZ8K1bXlwkk1z5tK7xIZyiUltjd9LxbeBG2wxSk1__ueO0Jh9HP43cM90o3kOV6FbtlckIkuTvNFyYV8YXeyLI03gELSLZ-HHPm3zgk-DZjuWoaf0zp100bLad7XMqEC_4E58fbkW-j0E8sjzrOZcCMvqM6ac6A2WkX8csJNN1GbdFuoM6oOjC6hfuNkuTTRI_uPbfc2ri7px3zjHSL8xqzoN8eZLxbO2YN9dxuC1IoS3KvOW5ThYbIUTbko3wOFuBKskUu7-zhorY1fHNYMBQ7pupVVpBJhz5o3YYMx-VWZ2LBDQqsCXd-vidjpzcfFhdaFg3efNGCUZWkcfGndzHMxTiIs1FF3T9FfUbqMgFS7GFWdm4Gpc-HWMx8j8i9iaEzsRVzLaWnfmf4PhBqeEKyA_vD52EDh7Qz5XJMtD_FS1alXUqyyEfiHWJ7DGLzVyPP2CyNWCAc-VEXbngowJiFejeE9DAeZxbAr8GdX-a-eTFckzAp55UbrxVX26TZV9pVRBurC9EJ_zpFDTblXRjtx8TfAhfICXxkoX42wzlrgXsQCSuLoggbcSAukoknqc_eBKx0YqgGyrylbnoABE7s0T5oQ1M7jKzJFWlvJuzqEsSHQgh3XVe1u_aAlAc36Adglxp9K8dH6TRgYtlEkmQMgfRDvo1Zmpey1NotcnShV_so5kl&sai=AMfl-YSoWnn28x9Zla7CEuyfVR6IrPi41SDJNqRgVv-AgtibgnEQaPvN4N3ziLRAZf40beCvIDxe7F0SAniDrLSEJ-vhCID0iOkthcwoGD8zioVS1moyBbmPamIzJ1maF56kLzWrpfQ0dxfLvqNAkG8gzD_-6xxR8v9759Ly9EceoRukPnnn4P7jRwQhaI1MiWED_zWgv0gixFMoY8kMcMtKeNyTBz8wGQ38z6sOgy_peHq7LVSW1B6JGnlNDHm_MVmNq2WbdgoIp7IpgGio-gnxRnhjCAhkbSmbK-FuRgvPiboPY3rd7sO7kQ49anvh5VrX5GDijLawZiz_hQDnruD8davWrOtK6YKrQlb7I2g9v1WXQIAqDm4vfTE7n7Tx8vYpjfLVBQdBmr3cCeg7PJQ5jHcL4hyqHmmoYT2d3TlBIiDBVtE_oBgLYwjOb9ZKTHnOOrlQKeT7X6GuU5SFC39saGIOfNjZI90YafIeysopH49X0kQkZvRiOicyWiuZAGeCB_4B9CadLga0fToffR7J850R_QzPO3W-yWNFLUfxjpXkVj2GqIYlOpVz0hltLQA00HvyRJ1T8gb83wOuxCPzOX74KrZ3-xgxfEUSZbBnvfPbxi44sKmF33zExNGFz28wQQUC9XfXbZn-EUa9898bU88iuF83q3iJqvMmrROktai1MySIuoEphpNza36BWqjrlYMzsc7ISx2qh1cERJLYtxurTnA9f6X4ph5AWiXf2Zj4LPAnuT_CVd22JEEc4pu0EGIZCqbid_o-rgrQnQ5-bp6ewvH_X95j5e-vHDFqh30qrS6DYbnTpF53W5-ce9zIlOIj8NuUtP5DqSY_vAFjsJcPIH3JtKd2UHX0nwdMWr6UxuADmrhM5a54XCMAYUu9hzIuZ6Fj9GnM_SQyHYOLh_YIajvzzBoWcd2X_ZzlPTu2gkZz_RLOrlrar-OSCp5JixQl_ikgX_oQifnP8bubIe06aQp3m5aWc1W41_Bn8te5JoRlBxQyhow&sig=Cg0ArKJSzPp1L3qt9wYb&cry=1&fbs_aeid=%5Bgw_fbsaeid%5D&urlfix=1&nx=180&ny=181&dim=300x250&adurl=https://www.lego.com/en-us/product/arcade-pinball-machine-11374%3Fcmp%3Ddfa_34509022%3B9663855%3B436982387%3B259403419%3BSHOP%26dclid%3D%25edclid!%26gad_source%3D7%26gad_campaignid%3D23388967401
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