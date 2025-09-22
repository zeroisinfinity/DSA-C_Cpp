#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <chrono>
#include <cassert>

class OptimizedKnapsack {
private:
    std::vector<int> profits, weights;
    int capacity;
    
public:
    struct Solution {
        long long max_profit;
        std::vector<int> selected_items;
        int total_weight;
        double solve_time_ms;
        size_t states_explored;
    };
    
    OptimizedKnapsack(const std::vector<int>& p, const std::vector<int>& w, int cap) 
        : profits(p), weights(w), capacity(cap) {
        assert(p.size() == w.size() && !p.empty() && cap >= 0);
    }
    
    Solution solve() {
        auto start = std::chrono::high_resolution_clock::now();
        
        // Use map<weight, pair<max_profit, item_set>> 
        std::map<int, std::pair<long long, std::vector<int>>> current_states;
        current_states[0] = {0, {}};  // Base state
        
        for (size_t item = 0; item < profits.size(); ++item) {
            std::map<int, std::pair<long long, std::vector<int>>> next_states;
            
            // Process each existing state
            for (const auto& [weight, state_info] : current_states) {
                const auto& [profit, items] = state_info;
                
                // Keep existing state
                auto it = next_states.find(weight);
                if (it == next_states.end() || it->second.first < profit) {
                    next_states[weight] = {profit, items};
                }
                
                // Try adding current item
                int new_weight = weight + weights[item];
                if (new_weight <= capacity) {
                    long long new_profit = profit + profits[item];
                    
                    auto new_items = items;
                    new_items.push_back(item);
                    
                    auto it_new = next_states.find(new_weight);
                    if (it_new == next_states.end() || it_new->second.first < new_profit) {
                        next_states[new_weight] = {new_profit, new_items};
                    }
                }
            }
            
            // Proper dominance pruning: remove states with higher weight but lower/equal profit
            current_states.clear();
            long long max_profit_so_far = -1;
            
            for (const auto& [weight, state_info] : next_states) {
                const auto& [profit, items] = state_info;
                if (profit > max_profit_so_far) {
                    current_states[weight] = {profit, items};
                    max_profit_so_far = profit;
                }
            }
        }
        
        // Find optimal solution
        auto optimal = std::max_element(current_states.begin(), current_states.end(),
            [](const auto& a, const auto& b) { return a.second.first < b.second.first; });
        
        auto end = std::chrono::high_resolution_clock::now();
        double time_ms = std::chrono::duration<double, std::milli>(end - start).count();
        
        return {
            optimal->second.first,
            optimal->second.second,
            optimal->first,
            time_ms,
            current_states.size()
        };
    }
};


// Test the C++ version
int main() {
    // Test with your hard problem
    std::vector<int> profits = {95, 88, 81, 70, 65, 63, 56, 45, 41, 35, 25, 15};
    std::vector<int> weights = {23, 21, 20, 17, 16, 15, 14, 11, 10,  8,  6,  4};
    
    OptimizedKnapsack knapsack(profits, weights, 50);
    auto result = knapsack.solve();
    
    std::cout << "Max Profit: " << result.max_profit << std::endl;
    std::cout << "Total Weight: " << result.total_weight << std::endl;
    std::cout << "States Explored: " << result.states_explored << std::endl;
    std::cout << "Solve Time: " << result.solve_time_ms << " ms" << std::endl;
    std::cout << "Selected Items: ";
    for (int item : result.selected_items) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
