public class KnapRS {
    static final int[] profit = {0, 3, 5, 6, 8};
    static final int[] weight = {0, 1, 2, 1, 2};
    static final int constraint = 5;
    static final int pwsize = 5;

    static int knap(int obj, int wght) {//b1
        
        if (obj == 0 || wght == 0) {//b2
            return 0;
        }//b2
        
        if (weight[obj] <= wght) {//b3
            int neg = knap(obj - 1, wght);
            int pov = knap(obj - 1, wght - weight[obj]) + profit[obj];
            return neg > pov ? neg : pov;
        }//b3
        return knap(obj - 1, wght);
    }//b1

    public static void main(String[] args) {//b4
        System.out.printf("max profit is - %d", knap(pwsize - 1, constraint));
    }//b4
}
