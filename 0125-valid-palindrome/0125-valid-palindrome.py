class Solution:
    def isPalindrome(self, s: str) -> bool:
        strs = []
        for c in s:
            if c.isalnum():
                strs.append(c.lower())
                
        # 팰린드롬 여부 판별
        while len(strs) > 1:
            if strs.pop() != strs.pop(0): return False
        return True