// ================================
// JAVA CORRECTED PRODUCTION SOLUTION
// ================================
import java.util.*;

public class ProductionKnapsack {
    private final int[] profits;
    private final int[] weights;
    private final int capacity;
    
    public static class Solution {
        public final long maxProfit;
        public final List<Integer> selectedItems;
        public final int totalWeight;
        public final double solveTimeMs;
        public final int statesExplored;
        
        public Solution(long maxProfit, List<Integer> selectedItems, int totalWeight, 
                       double solveTimeMs, int statesExplored) {
            this.maxProfit = maxProfit;
            this.selectedItems = new ArrayList<>(selectedItems);
            this.totalWeight = totalWeight;
            this.solveTimeMs = solveTimeMs;
            this.statesExplored = statesExplored;
        }
        
        @Override
        public String toString() {
            return String.format("Solution{maxProfit=%d, totalWeight=%d, items=%s, time=%.3fms, states=%d}",
                maxProfit, totalWeight, selectedItems, solveTimeMs, statesExplored);
        }
    }
    
    private static class State {
        final long profit;
        final List<Integer> items;
        
        State(long profit, List<Integer> items) {
            this.profit = profit;
            this.items = new ArrayList<>(items);
        }
    }
    
    public ProductionKnapsack(int[] profits, int[] weights, int capacity) {
        if (profits.length != weights.length || profits.length == 0) {
            throw new IllegalArgumentException("Invalid input arrays");
        }
        if (capacity < 0) throw new IllegalArgumentException("Negative capacity");
        
        this.profits = profits.clone();
        this.weights = weights.clone();
        this.capacity = capacity;
    }
    
    public Solution solve() {
        long startTime = System.nanoTime();
        
        // TreeMap maintains ordering by weight automatically
        TreeMap<Integer, State> currentStates = new TreeMap<>();
        currentStates.put(0, new State(0, new ArrayList<>()));
        
        for (int itemIdx = 0; itemIdx < profits.length; itemIdx++) {
            TreeMap<Integer, State> nextStates = new TreeMap<>();
            
            for (Map.Entry<Integer, State> entry : currentStates.entrySet()) {
                int currWeight = entry.getKey();
                State currState = entry.getValue();
                
                // Keep existing state
                State existing = nextStates.get(currWeight);
                if (existing == null || existing.profit < currState.profit) {
                    nextStates.put(currWeight, new State(currState.profit, currState.items));
                }
                
                // Try adding current item
                int newWeight = currWeight + weights[itemIdx];
                if (newWeight <= capacity) {
                    long newProfit = currState.profit + profits[itemIdx];
                    List<Integer> newItems = new ArrayList<>(currState.items);
                    newItems.add(itemIdx);
                    
                    State existingNew = nextStates.get(newWeight);
                    if (existingNew == null || existingNew.profit < newProfit) {
                        nextStates.put(newWeight, new State(newProfit, newItems));
                    }
                }
            }
            
            // Proper dominance pruning
            TreeMap<Integer, State> prunedStates = new TreeMap<>();
            long maxProfitSoFar = -1;
            
            for (Map.Entry<Integer, State> entry : nextStates.entrySet()) {
                if (entry.getValue().profit > maxProfitSoFar) {
                    prunedStates.put(entry.getKey(), entry.getValue());
                    maxProfitSoFar = entry.getValue().profit;
                }
            }
            
            currentStates = prunedStates;
        }
        
        // Find optimal solution
        State optimalState = currentStates.values().stream()
            .max(Comparator.comparingLong(s -> s.profit))
            .orElse(new State(0, new ArrayList<>()));
        
        int optimalWeight = currentStates.entrySet().stream()
            .filter(e -> e.getValue().profit == optimalState.profit)
            .mapToInt(Map.Entry::getKey)
            .findFirst().orElse(0);
        
        long endTime = System.nanoTime();
        double solveTimeMs = (endTime - startTime) / 1_000_000.0;
        
        return new Solution(
            optimalState.profit,
            new ArrayList<>(optimalState.items),
            optimalWeight,
            solveTimeMs,
            currentStates.size()
        );
    }

    // JAVA MAIN FUNCTION
    public static void main(String[] args) {
        // Test with your hard problem
        int[] profits = {95, 88, 81, 70, 65, 63, 56, 45, 41, 35, 25, 15};
        int[] weights = {23, 21, 20, 17, 16, 15, 14, 11, 10,  8,  6,  4};
        int capacity = 50;
        
        ProductionKnapsack knapsack = new ProductionKnapsack(profits, weights, capacity);
        Solution result = knapsack.solve();
        
        System.out.println("Java Implementation Results:");
        System.out.println("Max Profit: " + result.maxProfit);
        System.out.println("Total Weight: " + result.totalWeight);
        System.out.println("States Explored: " + result.statesExplored);
        System.out.println("Solve Time: " + String.format("%.3f ms", result.solveTimeMs));
        System.out.print("Selected Items: ");
        for (int item : result.selectedItems) {
            System.out.print(item + " ");
        }
        System.out.println();
        System.out.println("\nFull Solution: " + result);
        
        // Additional verification
        long totalProfit = 0, totalWeight = 0;
        for (int item : result.selectedItems) {
            totalProfit += profits[item];
            totalWeight += weights[item];
        }
        System.out.println("Verification - Calculated profit: " + totalProfit + ", weight: " + totalWeight);
    }
}

