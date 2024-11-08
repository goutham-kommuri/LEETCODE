class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int prev = Math.min(
                    i > 0 ? grid[i-1][j] : Integer.MAX_VALUE,
                    j > 0 ? grid[i][j-1] : Integer.MAX_VALUE
                );
                grid[i][j] = (prev != Integer.MAX_VALUE ? prev : 0) + grid[i][j];
            }
        }
        return grid[m-1][n-1];
    }
}