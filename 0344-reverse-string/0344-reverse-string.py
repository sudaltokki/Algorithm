class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        str_len = len(s)
        bias_left = 0
        bias_right = str_len - 1
        
        for i in range(str_len//2):
            s[bias_left], s[bias_right] = s[bias_right], s[bias_left]
            bias_left += 1
            bias_right -= 1