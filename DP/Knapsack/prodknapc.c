// ================================
// C CORRECTED PRODUCTION SOLUTION  
// ================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

typedef struct {
    int weight;
    long long profit;
    int* items;
    int item_count;
} State;

typedef struct {
    State* states;
    int count;
    int capacity_allocated;
} StateSet;

typedef struct {
    long long max_profit;
    int* selected_items;
    int item_count;
    int total_weight;
    double solve_time_ms;
    int states_explored;
} KnapsackResult;

StateSet* create_stateset() {
    StateSet* set = malloc(sizeof(StateSet));
    assert(set != NULL);
    set->capacity_allocated = 64;
    set->states = malloc(set->capacity_allocated * sizeof(State));
    assert(set->states != NULL);
    set->count = 0;
    return set;
}

void add_state(StateSet* set, int weight, long long profit, const int* items, int item_count) {
    if (set->count >= set->capacity_allocated) {
        set->capacity_allocated *= 2;
        set->states = realloc(set->states, set->capacity_allocated * sizeof(State));
        assert(set->states != NULL);
    }
    
    State* state = &set->states[set->count++];
    state->weight = weight;
    state->profit = profit;
    state->item_count = item_count;
    
    if (item_count > 0) {
        state->items = malloc(item_count * sizeof(int));
        assert(state->items != NULL);
        memcpy(state->items, items, item_count * sizeof(int));
    } else {
        state->items = NULL;
    }
}

int compare_states(const void* a, const void* b) {
    const State* sa = (const State*)a;
    const State* sb = (const State*)b;
    return sa->weight - sb->weight;
}

void prune_dominated(StateSet* set) {
    if (set->count <= 1) return;
    
    qsort(set->states, set->count, sizeof(State), compare_states);
    
    int write_idx = 0;
    long long max_profit = -1;
    
    for (int i = 0; i < set->count; i++) {
        if (set->states[i].profit > max_profit) {
            if (write_idx != i) {
                // Move state to write position
                if (write_idx > 0 && set->states[write_idx - 1].items) {
                    free(set->states[write_idx - 1].items);
                }
                set->states[write_idx] = set->states[i];
            }
            max_profit = set->states[i].profit;
            write_idx++;
        } else {
            // Free dominated state
            if (set->states[i].items) {
                free(set->states[i].items);
            }
        }
    }
    set->count = write_idx;
}

void free_stateset(StateSet* set) {
    if (set) {
        for (int i = 0; i < set->count; i++) {
            if (set->states[i].items) {
                free(set->states[i].items);
            }
        }
        free(set->states);
        free(set);
    }
}

KnapsackResult solve_knapsack_c(const int* profits, const int* weights, int n, int capacity) {
    clock_t start = clock();
    
    StateSet* current = create_stateset();
    add_state(current, 0, 0, NULL, 0);
    
    for (int item = 0; item < n; item++) {
        StateSet* next = create_stateset();
        
        for (int i = 0; i < current->count; i++) {
            State* state = &current->states[i];
            
            // Add existing state to next
            add_state(next, state->weight, state->profit, state->items, state->item_count);
            
            // Try adding current item
            int new_weight = state->weight + weights[item];
            if (new_weight <= capacity) {
                // Create new item array with current item added
                int new_item_count = state->item_count + 1;
                int* new_items = malloc(new_item_count * sizeof(int));
                assert(new_items != NULL);
                
                if (state->items && state->item_count > 0) {
                    memcpy(new_items, state->items, state->item_count * sizeof(int));
                }
                new_items[state->item_count] = item;
                
                add_state(next, new_weight, state->profit + profits[item], 
                         new_items, new_item_count);
                
                free(new_items);  // Safe to free - add_state makes its own copy
            }
        }
        
        prune_dominated(next);
        
        free_stateset(current);
        current = next;
    }
    
    // Find optimal
    State* optimal = &current->states[0];
    for (int i = 1; i < current->count; i++) {
        if (current->states[i].profit > optimal->profit) {
            optimal = &current->states[i];
        }
    }
    
    clock_t end = clock();
    double time_ms = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
    
    KnapsackResult result;
    result.max_profit = optimal->profit;
    result.total_weight = optimal->weight;
    result.solve_time_ms = time_ms;
    result.states_explored = current->count;
    result.item_count = optimal->item_count;
    
    if (optimal->item_count > 0) {
        result.selected_items = malloc(optimal->item_count * sizeof(int));
        assert(result.selected_items != NULL);
        memcpy(result.selected_items, optimal->items, optimal->item_count * sizeof(int));
    } else {
        result.selected_items = NULL;
    }
    
    free_stateset(current);
    return result;
}

void free_result(KnapsackResult* result) {
    if (result && result->selected_items) {
        free(result->selected_items);
        result->selected_items = NULL;
    }
}

// C MAIN FUNCTION
int main() {
    // Test with your hard problem
    int profits[] = {95, 88, 81, 70, 65, 63, 56, 45, 41, 35, 25, 15};
    int weights[] = {23, 21, 20, 17, 16, 15, 14, 11, 10,  8,  6,  4};
    int n = 12;
    int capacity = 50;
    
    KnapsackResult result = solve_knapsack_c(profits, weights, n, capacity);
    
    printf("C Implementation Results:\n");
    printf("Max Profit: %lld\n", result.max_profit);
    printf("Total Weight: %d\n", result.total_weight);
    printf("States Explored: %d\n", result.states_explored);
    printf("Solve Time: %.3f ms\n", result.solve_time_ms);
    printf("Selected Items: ");
    for (int i = 0; i < result.item_count; i++) {
        printf("%d ", result.selected_items[i]);
    }
    printf("\n\n");
    
    free_result(&result);
    return 0;
}


