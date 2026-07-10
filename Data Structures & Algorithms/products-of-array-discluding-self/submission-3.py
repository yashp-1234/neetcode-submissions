class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans = []
        mul = nums[0]
        isZero = 0
        for i in nums[1:]:
            if i != 0:
                mul *= i
            else:
                isZero += 1
        
        for i in range(len(nums)):
            if isZero == 1:
                if nums[i] != 0:
                    ans.append(0)
                else:
                    ans.append(mul)
            elif isZero >= 1:
                return [0] * len(nums)
            else:
                ans.append(mul // nums[i])

        return ans