class Solution(object):
    def minimumOperations(self, nums, target):
        arr = [t - n for t, n in zip(target, nums)]
        
        result = 0
        current_list = []
        pos = True
        
        for num in arr:
            if num == 0:
                result += self.solve(current_list)
                current_list = []
                pos = True
            else:
                exp = num > 0
                if exp != pos:
                    result += self.solve(current_list)
                    current_list = []
                current_list.append(abs(num))
                pos = exp
        
        result += self.solve(current_list)
        
        return result
    
    def solve(self, lst):
        min_val = 0
        result = 0
        
        for num in lst:
            if num > min_val:
                result += num - min_val
            min_val = num
        
        return result
        