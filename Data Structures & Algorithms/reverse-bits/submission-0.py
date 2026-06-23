class Solution:
    def reverseBits(self, n: int) -> int:
        num = 0
        for i in range (32):
            if (1<<i) & n !=0:
                num += (1<<31-i)
        return num
        