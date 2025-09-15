# ♛ N-Queens Problem: The Ultimate Simple Guide

## 🚀 What is the N-Queens Problem? 

**The N-Queens Problem** asks:  
> How can you place N chess queens on an N×N board so that no two queens threaten each other?  
(That means: no two queens in the same row, column, or diagonal!)

---

## 🧠 Why is it Famous? 

- 📚 Classic in computer science for learning **Recursion** & **Backtracking**.
- 🏆 Used in coding interviews and competitive programming.
- 💡 Foundation for harder constraint satisfaction problems.

---

## 🗺️ Visual Explanation

### 🔍 Queen Attack Patterns

Before diving into solutions, let's understand how queens attack:

```mermaid
graph TD
    A["Queen at (3,3)"] --> B["Row Attacks"]
    A --> C["Column Attacks"]
    A --> D["Diagonal Attacks"]
    
    B --> B1["(3,0) (3,1) (3,2) (3,4) (3,5) (3,6) (3,7)"]
    C --> C1["(0,3) (1,3) (2,3) (4,3) (5,3) (6,3) (7,3)"]
    D --> D1["Main Diagonal: (0,0) (1,1) (2,2) (4,4) (5,5) (6,6) (7,7)"]
    D --> D2["Anti Diagonal: (0,6) (1,5) (2,4) (4,2) (5,1) (6,0)"]
    
    classDef default fill:#FFFFFF,stroke:#000000,color:#000000
    classDef queen fill:#FFD700,stroke:#B8860B,stroke-width:2px,color:#000000,font-weight:bold
    classDef attack fill:#FFE4E1,stroke:#8B0000,stroke-width:1px,color:#000000
    
    class A queen
    class B,C,D fill:#E6E6FA,stroke:#9370DB,stroke-width:1px,color:#000000
    class B1,C1,D1,D2 attack
    
    style A text-align:center
    style B text-align:center
    style C text-align:center
    style D text-align:center
    style B1 text-align:left
    style C1 text-align:left
    style D1 text-align:left
    style D2 text-align:left
```

### 🟩 2x2 Chessboard: Impossible!

```mermaid
graph TD
    A[2x2 Board Analysis]
    A --> B[Place Queen at Position 1]
    B --> C[All other positions attacked]
    C --> D[NO SOLUTION]
    
    A --> E[Place Queen at Position 2]
    E --> F[All other positions attacked]
    F --> G[NO SOLUTION]
    
    style A fill:#E6E6FA,stroke:#9370DB,color:#000000
    style B fill:#E6E6FA,stroke:#9370DB,color:#000000
    style E fill:#E6E6FA,stroke:#9370DB,color:#000000
    style C fill:#FFB6C1,stroke:#8B0000,color:#000000
    style F fill:#FFB6C1,stroke:#8B0000,color:#000000
    style D fill:#FF6B6B,stroke:#8B0000,color:#000000
    style G fill:#FF6B6B,stroke:#8B0000,color:#000000
```

> 🔴 **There are no ways to place 2 queens—try drawing it!**

### 🟩 8x8 Chessboard: Possible!

```
Enter your chessboard dimension: 8
SOLUTION NUMBER - 1
```

## 📷 Example Screenshot

![8-Queens Solution](./ss/8queens.png) <!-- You can save the screenshot as per your repo -->

#### ASCII Board Example

```
Q  .  .  .  .  .  .  .
.  .  .  .  Q  .  .  .
.  .  .  .  .  .  .  Q
.  .  .  .  .  Q  .  .
.  .  Q  .  .  .  .  .
.  .  .  .  .  .  Q  .
.  Q  .  .  .  .  .  .
.  .  .  Q  .  .  .  .
```
- `Q` = Queen 🟪
- `.` = Empty square

---

## 🔁 How Does the Algorithm Work? (Backtracking)

### 🧠 Core Backtracking Concept

```mermaid
graph TD
    Start([Start]) --> PlaceQueen[Place Queen in row]
    PlaceQueen --> CheckSafe{Is position safe?}
    CheckSafe -->|Yes| NextRow[Move to next row]
    CheckSafe -->|No| NextCol[Try next column]
    
    NextRow -->|Row < N| PlaceQueen
    NextRow -->|Row = N| Solution[Found Solution!]
    
    NextCol -->|Column < N| PlaceQueen
    NextCol -->|No more columns| Backtrack[Backtrack to previous row]
    Backtrack --> PlaceQueen
    
    style Start fill:#4CAF50,stroke:#2E7D32,color:white
    style PlaceQueen fill:#2196F3,stroke:#0D47A1,color:white
    style CheckSafe fill:#FFC107,stroke:#FF6F00,color:black
    style NextRow fill:#4CAF50,stroke:#2E7D32,color:white
    style NextCol fill:#FF9800,stroke:#E65100,color:white
    style Backtrack fill:#F44336,stroke:#B71C1C,color:white
    style Solution fill:#9C27B0,stroke:#4A148C,color:white
```

### Step-by-step (in Simple Words):

1. Start from the first row.
2. Try to place a queen in each column, one by one.
3. For each placement, check:
    - Is it safe? (No queen in same column/diagonal)
4. If safe, move to next row and repeat.
5. If you can't place a queen, **backtrack** (go up a row, move queen).
6. Repeat until you finish the board or run out of options.

### 🌳 Complete State-Space Tree for 4-Queens

```mermaid
graph TD
    Root["Start: Empty 4x4 Board"] --> R0C0["Row 0, Col 0"]
    Root --> R0C1["Row 0, Col 1"]
    Root --> R0C2["Row 0, Col 2"]
    Root --> R0C3["Row 0, Col 3"]
    
    R0C0 --> R1C0_X["❌ Row 1, Col 0"]
    R0C0 --> R1C1_X["❌ Row 1, Col 1"]
    R0C0 --> R1C2["✓ Row 1, Col 2"]
    R0C0 --> R1C3_X["❌ Row 1, Col 3"]
    
    R1C2 --> R2C0_X["❌ Row 2, Col 0"]
    R1C2 --> R2C1_X["❌ Row 2, Col 1"]
    R1C2 --> R2C2_X["❌ Row 2, Col 2"]
    R1C2 --> R2C3_X["❌ Row 2, Col 3"]
    
    R0C1 --> R1C0_1["❌ Row 1, Col 0"]
    R0C1 --> R1C1_1["❌ Row 1, Col 1"]
    R0C1 --> R1C2_1["❌ Row 1, Col 2"]
    R0C1 --> R1C3_1["✓ Row 1, Col 3"]
    
    R1C3_1 --> R2C0_1["✓ Row 2, Col 0"]
    R2C0_1 --> R3C0_1["❌ Row 3, Col 0"]
    R2C0_1 --> R3C1_1["❌ Row 3, Col 1"]
    R2C0_1 --> R3C2_1["✓ Row 3, Col 2"]
    R2C0_1 --> R3C3_1["❌ Row 3, Col 3"]
    
    R3C2_1["🎉 SOLUTION 1: (0,1)(1,3)(2,0)(3,2)"]
    
    classDef solution fill:#90EE90,color:#000000
    classDef invalid fill:#FF6B6B,color:#000000
    classDef valid fill:#87CEEB,color:#000000
    
    class R3C2_1 solution
    class R1C0_X,R1C1_X,R1C3_X,R2C0_X,R2C1_X,R2C2_X,R2C3_X,R1C0_1,R1C1_1,R1C2_1,R3C0_1,R3C1_1,R3C3_1 invalid
    class R0C0,R0C1,R0C2,R0C3,R1C2,R1C3_1,R2C0_1 valid
```

---

## 🔗 Detailed Algorithm Flowchart

```mermaid
flowchart TD
    Start(["Start N-Queens"]) --> Init["Initialize: row = 0, board = empty"]
    Init --> CheckRow{"row >= N?"}
    CheckRow -- Yes --> Solution["🎉 Solution Found!<br/>Print board"]
    CheckRow -- No --> InitCol["col = 0"]
    
    InitCol --> CheckCol{"col < N?"}
    CheckCol -- No --> Backtrack["❌ Backtrack<br/>Return false"]
    CheckCol -- Yes --> SafeCheck["isSafe(row, col)?"]
    
    SafeCheck --> CheckConflicts{"Check conflicts"}
    CheckConflicts --> RowCheck["Same row?"]
    CheckConflicts --> ColCheck["Same column?"]
    CheckConflicts --> DiagCheck["Same diagonal?"]
    
    RowCheck --> Conflict1{"Conflict?"}
    ColCheck --> Conflict2{"Conflict?"}
    DiagCheck --> Conflict3{"Conflict?"}
    
    Conflict1 -- Yes --> NextCol["col++"]
    Conflict2 -- Yes --> NextCol
    Conflict3 -- Yes --> NextCol
    
    Conflict1 -- No --> AllSafe{"All checks passed?"}
    Conflict2 -- No --> AllSafe
    Conflict3 -- No --> AllSafe
    
    AllSafe -- Yes --> PlaceQueen["Place queen at (row, col)"]
    AllSafe -- No --> NextCol
    
    PlaceQueen --> Recurse["Solve(row + 1)"]
    Recurse --> RecurseResult{"Recursive call successful?"}
    
    RecurseResult -- Yes --> Solution
    RecurseResult -- No --> RemoveQueen["Remove queen from (row, col)"]
    
    RemoveQueen --> NextCol
    NextCol --> CheckCol
    
    classDef start fill:#87CEEB,color:#000000
    classDef success fill:#90EE90,color:#000000
    classDef fail fill:#FF6B6B,color:#000000
    classDef process fill:#DDA0DD,color:#000000
    
    class Start,Init start
    class Solution success
    class Backtrack fail
    class PlaceQueen,RemoveQueen,Recurse process
```

### 🔄 Recursive Call Sequence for 4-Queens

```mermaid
sequenceDiagram
    participant Main as Main Function
    participant S0 as solveNQueens(0)
    participant S1 as solveNQueens(1)
    participant S2 as solveNQueens(2)
    participant S3 as solveNQueens(3)
    participant S4 as solveNQueens(4)
    
    Main->>S0: Start solving from row 0
    activate S0
    
    Note over S0: Try queen at (0,1)
    S0->>S1: Place at (0,1), solve row 1
    activate S1
    
    Note over S1: Try queen at (1,3)
    S1->>S2: Place at (1,3), solve row 2
    activate S2
    
    Note over S2: Try queen at (2,0)
    S2->>S3: Place at (2,0), solve row 3
    activate S3
    
    Note over S3: Try queen at (3,2)
    S3->>S4: Place at (3,2), solve row 4
    activate S4
    
    Note over S4: row >= 4, solution found!
    S4-->>S3: return true
    deactivate S4
    
    S3-->>S2: return true
    deactivate S3
    
    S2-->>S1: return true
    deactivate S2
    
    S1-->>S0: return true
    deactivate S1
    
    S0-->>Main: Solution: [(0,1), (1,3), (2,0), (3,2)]
    deactivate S0
```

---

## 🎯 Step-by-Step Solution Timeline

```mermaid
graph LR
    A["Start: Empty 4x4 board"] --> B["Try (0,0): Place queen"]
    B --> C["Check (1,0): ❌ Same column"]
    C --> D["Check (1,1): ❌ Same diagonal"]
    D --> E["Check (1,2): ✓ Safe"]
    E --> F["Place queen at (1,2)"]
    F --> G["Check (2,0): ❌ Diagonal conflict"]
    G --> H["Check (2,1): ❌ Diagonal conflict"]
    H --> I["Check (2,2): ❌ Same column"]
    I --> J["Check (2,3): ❌ Diagonal conflict"]
    J --> K["❌ No valid position in row 2"]
    K --> L["🔄 Backtrack: Remove (1,2)"]
    L --> M["Try (1,3): ❌ Same row as (0,0)"]
    M --> N["🔄 Backtrack: Remove (0,0)"]
    N --> O["Try (0,1): Place queen"]
    O --> P["Try (1,3): ✓ Safe"]
    P --> Q["Try (2,0): ✓ Safe"]
    Q --> R["Try (3,2): ✓ Safe"]
    R --> S["🎉 Solution Found!<br/>[(0,1), (1,3), (2,0), (3,2)]"]
    
    classDef start fill:#87CEEB,color:#000000
    classDef safe fill:#90EE90,color:#000000
    classDef unsafe fill:#FF6B6B,color:#000000
    classDef backtrack fill:#FFA500,color:#000000
    classDef solution fill:#FFD700,color:#000000
    
    class A start
    class E,F,O,P,Q,R safe
    class C,D,G,H,I,J,M unsafe
    class K,L,N backtrack
    class S solution
```

### 📋 Board State Visualization

```mermaid
graph TD
    subgraph "Solution Board State"
        A["Row 0: . Q . .<br/>Row 1: . . . Q<br/>Row 2: Q . . .<br/>Row 3: . . Q ."]
    end
    
    subgraph "Conflict Analysis"
        B["Queen at (0,1)"] --> B1["Controls: Row 0, Col 1, Diagonals"]
        C["Queen at (1,3)"] --> C1["Controls: Row 1, Col 3, Diagonals"]
        D["Queen at (2,0)"] --> D1["Controls: Row 2, Col 0, Diagonals"]
        E["Queen at (3,2)"] --> E1["Controls: Row 3, Col 2, Diagonals"]
    end
    
    subgraph "Safety Verification"
        F["No two queens share:<br/>• Same row ✓<br/>• Same column ✓<br/>• Same diagonal ✓"]
    end
    
    classDef board fill:#F0F8FF,color:#000000
    classDef analysis fill:#E6E6FA,color:#000000
    classDef verification fill:#90EE90,color:#000000
    
    class A board
    class B1,C1,D1,E1 analysis
    class F verification
```

---

## 📝 Sample Code (C, Simple)

```c
bool valid_move(int k_row , int l_col , int* soln){//b5    
    for( int trav = 0 ; trav < k_row - 1 ; trav++){//b6
          bool same_diagonals = abs((trav + 1) - k_row) == abs(soln[trav] - l_col);
          bool same_col = (soln[trav] == l_col) ;
          if( same_diagonals || same_col ){//b6
              return false;
          }//b6
    }//b6
    return true;    
}//b5

void place_queen(int dxd, int k_row , int* soln){//b1 
    if(k_row > dxd){
        display(soln, dxd);
        printf("
");
        return;
    }

    
    for(int trav = 0 ; trav < dxd ; trav++){//b2
          if( valid_move(k_row , trav + 1 , soln ) ){//b3
                soln[k_row-1] = trav + 1;
                place_queen(dxd , k_row + 1 , soln);
          }//b3
    }//b2
}//b1

```

---

## 📊 Time & Space Complexity

| Algorithm    | Time Complexity | Space Complexity |
|--------------|----------------|-----------------|
| Backtracking | O(N!)          | O(N)            |

- **Time:** Worst case, you try every possible placement (factorial growth).
- **Space:** Just the board array (O(N)), plus recursion stack.

---

## 🤔 Why Backtracking?

Backtracking is like trying all options, but **giving up as soon as you know** something won't work.  
Imagine trying keys on a lock:  
- If a key doesn’t work, you put it back and try another.  
- If a key fits, you keep going!

---

### 🔍 Constraint Satisfaction Analysis

```mermaid
graph TD
    subgraph "Constraint Types"
        A["Row Constraint"] --> A1["Each row must have exactly 1 queen"]
        B["Column Constraint"] --> B1["Each column must have exactly 1 queen"]
        C["Diagonal Constraint"] --> C1["Each diagonal can have at most 1 queen"]
    end
    
    subgraph "Validation Process"
        D["Place Queen at (r,c)"] --> E{"Check Row r"}
        E -- "Already occupied" --> F["❌ Invalid"]
        E -- "Free" --> G{"Check Column c"}
        G -- "Already occupied" --> F
        G -- "Free" --> H{"Check Main Diagonal"}
        H -- "Already occupied" --> F
        H -- "Free" --> I{"Check Anti Diagonal"}
        I -- "Already occupied" --> F
        I -- "Free" --> J["✓ Valid Placement"]
    end
    
    classDef constraint fill:#E6E6FA,color:#000000
    classDef process fill:#F0F8FF,color:#000000
    classDef invalid fill:#FF6B6B,color:#000000
    classDef valid fill:#90EE90,color:#000000
    
    class A1,B1,C1 constraint
    class D,E,G,H,I process
    class F invalid
    class J valid
```

### ❌ No Solution: 2x2 Board

```mermaid
graph LR
    A["2x2 Board: Impossible"] --> B["Only 4 positions"]
    B --> C["Each queen attacks 3 positions"]
    C --> D["No safe placement for 2nd queen"]
    D --> E["Mathematical proof: N=2,3 have 0 solutions"]
    
    classDef impossible fill:#FF6B6B,color:#000000
    class A,E impossible
```

### ✅ Solution: 8x8 Board

```mermaid
graph TD
    A["8x8 Board: 92 Total Solutions"] --> B["First Solution Found"]
    B --> C["Queen positions:<br/>(0,5) (1,2) (2,6) (3,1)<br/>(4,7) (5,3) (6,0) (7,4)"]
    C --> D["Verification: All constraints satisfied"]
    
    classDef solution fill:#90EE90,color:#000000
    class A,B,C,D solution
```

```
SOLUTION NUMBER - 1
.  .  .  .  .  ♛  .  .
.  .  ♛  .  .  .  .  .
.  .  .  .  .  .  ♛  .
.  ♛  .  .  .  .  .  .
.  .  .  .  .  .  .  ♛
.  .  .  ♛  .  .  .  .
♛  .  .  .  .  .  .  .
.  .  .  .  ♛  .  .  .
```

---

## 📚 Extra Resources

- [Wikipedia: N-Queens](https://en.wikipedia.org/wiki/Eight_queens_puzzle)
- [Visualizations & Interactive](https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/)
- [LeetCode Problem](https://leetcode.com/problems/n-queens/)

---

## ⚡ Pro Tips

- Start with smaller boards (N=4 or N=5) to understand.
- Practice writing the backtracking logic from scratch.
- Use print statements to visualize the board at each step!

---

## 📊 Complexity Analysis Visualization

```mermaid
graph LR
    subgraph "Time Complexity Growth"
        A["N=1: 1 solution"] --> B["N=4: 2 solutions"]
        B --> C["N=8: 92 solutions"]
        C --> D["N=12: 14,200 solutions"]
        D --> E["Growth Rate: O(N!)"]
    end
    
    subgraph "Space Complexity"
        F["Board Array: O(N)"] --> G["Recursion Stack: O(N)"]
        G --> H["Total Space: O(N)"]
    end
    
    subgraph "Optimization Techniques"
        I["Early Pruning"] --> J["Constraint Propagation"]
        J --> K["Symmetry Breaking"]
        K --> L["Heuristic Ordering"]
    end
    
    classDef complexity fill:#FFE4B5,color:#000000
    classDef optimization fill:#E6E6FA,color:#000000
    
    class A,B,C,D,E,F,G,H complexity
    class I,J,K,L optimization
```

## 🏁 Summary Table

| Board Size | Number of Solutions |
|------------|---------------------|
| 1          | 1                   |
| 2          | 0                   |
| 3          | 0                   |
| 4          | 2                   |
| 5          | 10                  |
| 6          | 4                   |
| 7          | 40                  |
| 8          | 92                  |
| 9          | 352                 |
| 10         | 724                 |

---

## 🛡️ Professional Emojis Legend

- ♛ – Queen
- 🟩 – Board
- 🔁 – Loop/Recursion
- ⚡ – Tip
- 🎉 – Solution found
- ❌ – No solution
- 🧠 – Theory/Concept
- 📚 – Resource/Link

---

## ✍️ Author & Credits

- Coded and documented by [zeroisinfinity](https://github.com/zeroisinfinity)
- Guide created with 💡 and 🤖 by Copilot

---

*Happy Coding! If this helped, star the repo!* ⭐
