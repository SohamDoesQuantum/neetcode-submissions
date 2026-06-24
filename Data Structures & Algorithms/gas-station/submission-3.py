class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if(sum(cost)>sum(gas)):
            return -1
        start_idx = 0
        tank = 0
        n = len(cost)
        for i in range (n):
            tank = tank+gas[i]-cost[i]
            if(tank<0):
                start_idx = i+1
                tank = 0
            
        return start_idx