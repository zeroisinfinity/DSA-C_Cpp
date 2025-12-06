public class KnapTS {
    static final int[] profit = {0, 6, 5, 3, 8};
    static final int[] weight = {0, 1, 2, 1, 2};
    static final int constraint = 5;
    static final int pwsize = 5;
    static int[][] mem = new int[pwsize][constraint + 1];

    static int max(int a, int b) {//b8
        return a > b ? a : b;
    }//b8

    static int knap(int obj, int wght) {//b1
        for (int i = 1; i < obj; ++i)
            for (int j = 1; j <= wght; ++j)
                if (weight[i] <= j) mem[i][j] = max(mem[i - 1][j], mem[i - 1][j - weight[i]] + profit[i]);
                else mem[i][j] = mem[i - 1][j];
        return mem[obj - 1][wght];
    }//b1

    public static void main(String[] args) {//b4
        
        for (int i = 0; i < pwsize; i++)
            for (int j = 0; j < constraint + 1; j++)
                mem[i][j] = 0;

        System.out.printf("max profit is - %d", knap(pwsize, constraint));
        System.out.println();

        for (int i = 0; i < pwsize; i++) {
            for (int j = 0; j < constraint + 1; j++) {
                System.out.printf(" %d ", mem[i][j]);
            }
            System.out.println();
        }
    }//b4
}
