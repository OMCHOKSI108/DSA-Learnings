import java.util.HashSet;

class Solution {
    public boolean searchMatrix(int[][] mat, int x) {
        HashSet<Integer> s1 = new HashSet<>();

        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[i].length; j++) {
                s1.add(mat[i][j]);
            }
        }

        return s1.contains(x);
    }import java.util.HashSet;

class Solution {
    public boolean searchMatrix(int[][] mat, int x) {
        HashSet<Integer> s1 = new HashSet<>();

        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[i].length; j++) {
                s1.add(mat[i][j]);
            }
        }

        return s1.contains(x);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        // Example matrix
        int[][] matrix = {
            {1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 30, 34, 60}
        };

        int target1 = 3;
        int target2 = 13;

        System.out.println("Searching for " + target1 + ": " + sol.searchMatrix(matrix, target1));
        System.out.println("Searching for " + target2 + ": " + sol.searchMatrix(matrix, target2));
    }
}
}
