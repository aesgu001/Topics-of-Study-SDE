# 2200. Find All K-Distant Indices in an Array
# https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/

###################################################################################################
#
#   def findKDistantIndices(nums, key, k):
#   1.  Initialize empty array out
#   2.  Initialize the next index to store to 0
#   3.  For each num in nums
#   4.      If num == key:
#   5.          lower bound = max(next index, i - k)
#   6.          upper bound = min(nums.length, i + k + 1)
#   7.          next index = upper bound
#   8.          For each index in range(lower bound, upper bound)
#   9.              append index to out
#   10. Return out
#
#   Time complexity:    O(N) to check if each element in nums == key
#                       O(N) to check for k-th distant indices
#                       O(N) + O(N) = O(N)
#   Space complexity:   O(N) array of size N to store k-th distant indices
#
###################################################################################################

def findKDistantIndices(nums, key, k):
    out = []
    # Next k-th distant index to store
    next_KDI = 0

    for i in range(0, len(nums)):
        if nums[i] == key:
            # Get lower bound
            lower_bound = i - k
            if lower_bound < next_KDI:
                lower_bound = next_KDI
            
            # Get upper bound
            upper_bound = i + k + 1
            if upper_bound > len(nums):
                upper_bound = len(nums)
            
            # Get next KDI
            next_KDI = upper_bound
            
            # Store all k-th distant indices within range
            for j in range(lower_bound, upper_bound):
                out.append(j)
    
    return out

# Test cases
nums1 = [3, 4, 9, 1, 3, 9, 5]
key1 = 9
k1 = 1
print(findKDistantIndices(nums1, key1, k1))

nums2 = [2, 2, 2, 2, 2]
key2 = 2
k2 = 2
print(findKDistantIndices(nums2, key2, k2))
