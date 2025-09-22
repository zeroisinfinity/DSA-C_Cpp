public class KnapMS {
    static final int[] profit = {0, 6, 5, 3, 8};
    static final int[] weight = {0, 1, 2, 1, 2};
    static final int constraint = 5;
    static final int pwsize = 5;
    static int[][] mem = new int[pwsize][constraint + 1];

    static int knap(int obj, int wght) {//b1
        
        if (obj == 0 || wght == 0) {//b2
            mem[obj][wght] = 0;
            return 0;
        }//b2
        if (mem[obj][wght] != -1) return mem[obj][wght];
        if (weight[obj] <= wght) {//b3
            int neg = knap(obj - 1, wght);
            int pov = knap(obj - 1, wght - weight[obj]) + profit[obj];
            mem[obj][wght] = neg > pov ? neg : pov;
        }//b3
        else {//b6
            mem[obj][wght] = knap(obj - 1, wght);
        }//b6
        return mem[obj][wght];
    }//b1

    public static void main(String[] args) {//b4
        
        for (int i = 0; i < pwsize; i++)
            for (int j = 0; j < constraint + 1; j++)
                mem[i][j] = -1;

        System.out.printf("max profit is - %d", knap(pwsize - 1, constraint));
    }//b4
}
