class Solution:
    def isPalindrome(self, s: str) -> bool:
        # 자료형 데크로 선언
        strs: Deque = collections.deque()
            
        for c in s:
            if c.isalnum():
                strs.append(c.lower())
                
        while len(strs) > 1:
            if strs.popleft() != strs.pop(): return False
        return True