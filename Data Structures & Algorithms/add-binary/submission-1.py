
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if(len(b)>len(a)):
            return self.addBinary(b,a)
        n0 = len(a)-len(b)
        b = "0"*n0+b
        carry = 0
        ans = ""
        for i in range (len(a)-1,-1,-1):
            ai = int( a[i])
            bi = int( b[i])
            sum = str( carry^ai^bi)
            carry = ai&bi | carry&(ai^bi)
            ans = sum + ans
        if(carry):
            ans = "1"+ans
        return ans
        