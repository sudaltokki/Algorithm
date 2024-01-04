class Solution:
    def isPalindrome(self, s: str) -> bool:
        s1 = s.lower()
        s1 = ''.join(c for c in s1 if c.isalnum())
        num = len(s1) // 2
        for a in range(num):
            if s1[a] != s1[-1-a]: return False
        return True
