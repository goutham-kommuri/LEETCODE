

class Solution(object):
    def isEvenOddTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return False
        
        queue = deque([root])
        level = 0
        
        while queue:
            size = len(queue)
            prev_val = None if level % 2 == 0 else float('inf')
            
            for _ in range(size):
                node = queue.popleft()
                
                if level % 2 == 0:  # Even level
                    if node.val % 2 == 0 or (prev_val is not None and node.val <= prev_val):
                        return False
                else:  # Odd level
                    if node.val % 2 != 0 or (prev_val is not None and node.val >= prev_val):
                        return False
                
                prev_val = node.val
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            level += 1
        
        return True