#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 1. Your DSU Find function with Path Compression
    int find_parent(int a, vector<int>& parent) {
        if (parent[a] == a) return a;
        return parent[a] = find_parent(parent[a], parent);
    }

    // 2. Your DSU Unite function
    void unite(int a, int b, vector<int>& parent) {
        int pa = find_parent(a, parent);
        int pb = find_parent(b, parent);
        if (pa != pb) {
            parent[pb] = pa;
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        
        // Handle your early exit edge cases cleanly
        if (n == 1) return true;
        for (int i : nums) if (i == 1) return false; 

        int largest = *max_element(nums.begin(), nums.end());
        
        // 3. Initialize DSU parent array for ALL numbers up to 'largest'
        vector<int> parent(largest + 1);
        for (int i = 0; i <= largest; i++) {
            parent[i] = i;
        }

        // 4. Factorize each number on the fly and union it with its prime factors
        for (int num : nums) {
            int temp = num;
            
            // Check factors from 2 up to sqrt(temp)
            for (int i = 2; i * i <= temp; i++) {
                if (temp % i == 0) {
                    // 'i' is fundamentally guaranteed to be a prime factor here
                    unite(num, i, parent); 
                    
                    // Divide out all instances of this factor
                    while (temp % i == 0) {
                        temp /= i;
                    }
                }
            }
            // If there's a remainder greater than 1, it's also a prime factor
            if (temp > 1) {
                unite(num, temp, parent);
            }
        }

        // 5. Final Pass: Check if every number shares the exact same ultimate parent
        int baseline_root = find_parent(nums[0], parent);
        for (int i = 1; i < n; ++i) {
            if (find_parent(nums[i], parent) != baseline_root) {
                return false; // Found an isolated group!
            }
        }

        return true;
    }
};