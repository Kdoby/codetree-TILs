import java.util.Scanner;
public class Main {

    private static int[] xpos = {-1, 1, 0, 0};
    private static int[] ypos = {0, 0, -1, 1};
    private static int ans = 0;

    public static int GetSum(int[][] grid, int row, int col, int n) {
        int sum = 0;
        for(int i = 0; i < 4; ++i) {
            int x = row + xpos[i];
            int y = col + ypos[i];
            if(x < 0 || x >= n || y < 0 || y >= n) return 0;
            sum += grid[x][y];
        }

        return sum;
    }

    public static int GetLeftDiagonalSum(int[][] grid, int row, int col, int n) {
        if(row + 1 >= n || col - 1 < 0) return 0;
        return grid[row + 1][col] + grid[row][col - 1];
    }

    public static int GetRightDiagonalSum(int[][] grid, int row, int col, int n) {
        if(row + 1 >= n || col + 1 >= n ) return 0;
        return grid[row + 1][col] + grid[row][col + 1];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] grid = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = sc.nextInt();
        // Please write your code here.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                int sum = GetSum(grid, i, j, n);
                if(sum == 0) continue;
                int lsum = sum;
                int rsum = sum;
                for(int k = 1; k < n; ++k) {
                    if(i + k < n && j - k >= 0)
                        lsum += GetLeftDiagonalSum(grid, i + k, j - k, n);
                    if(i + k < n && j + k < n) 
                        rsum += GetRightDiagonalSum(grid, i + k, j + k, n);
                }
                ans = Math.max(Math.max(ans, lsum), rsum);
            }
        }

        System.out.print(ans);
    }
}