class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        myset = set()
        for i in nums:
            if i in myset:
                return True
            else:
                myset.add(i)
        return False