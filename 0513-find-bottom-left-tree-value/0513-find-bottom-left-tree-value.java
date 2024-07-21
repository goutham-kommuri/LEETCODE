class Solution {
  public int findBottomLeftValue(TreeNode root) {
    var queue = new ArrayDeque<TreeNode>();
    queue.offer(root);
    var node = root;

    while (!queue.isEmpty()) {
      node = queue.poll();

      if (node.right != null) queue.offer(node.right);
      if (node.left != null) queue.offer(node.left);
    }
    return node.val;
  }
}