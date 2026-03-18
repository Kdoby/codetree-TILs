import java.util.Scanner;
public class Main {
    public static int[][] grid = new int[20][20];
    public static int n;

    public static int ans = 0;

    public static boolean inRange(int row, int col) {
        return 0 <= row && row < n && 0 <= col && col < n;
    }

    // k = 가로 길이, l = 세로 길이
    public static int solve(int row, int col, int k, int l) {
        // 1 -> 2 -> 3 -> 4 를 각 변의 길이만큼씩 순회
        int[] dx = new int[]{-1, -1, 1, 1};
        int[] dy = new int[]{1, -1, -1, 1};
        int[] moveNum = new int[]{k, l, k, l};

        int sum = 0;
        int xx = row;
        int yy = col;

        for(int i = 0; i < 4; ++i) {
            // moveNum = k or l
            for(int j = 0; j < moveNum[i]; ++j) {
                xx += dx[i]; yy += dy[i];

                // 범위 벗어나는 사각형은 탈락
                if(!inRange(xx, yy)) return 0;

                sum += grid[xx][yy];
            }
        }

        return sum;
    }
    

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = sc.nextInt();
        // Please write your code here.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                for(int k = 1; k < n; k++) {
                    for(int l = 1; l < n; l++) {
                        // 각 점의 위치가 (row, col) 사각형의 맨 밑이라고 가정
                        // 이 점에서부터 1 -> 2 -> 3 -> 4 순서로 순회
                        ans = Math.max(ans, solve(i, j, k, l));
                    }
                }
            }
        }

        System.out.print(ans);
    }
}