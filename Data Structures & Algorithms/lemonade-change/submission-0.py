class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        a = 0 #5
        b = 0 #10
        c = 0 #20
        if(bills[0]!=5): 
            return False
        for bill in bills:
            if(bill == 5):
                a+=1
            elif(bill==10):
                b+=1
            else:
                c+=1
            change = bill-5
            while(change>=20 and c>=1):
                change -= 20
                c-=1
            while(change>=10 and b>=1):
                change -= 10
                b-=1
            while(change>=5 and a>=1):
                change -= 5
                a -=1
            if(change):
                return False
        return True                
