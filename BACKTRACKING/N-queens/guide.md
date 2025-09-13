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

### 🟩 2x2 Chessboard: Impossible!

```
Enter your chessboard dimension: 2
NO SOLUTION POSSIBLE
```
> 🔴 **There are no ways to place 2 queens—try drawing it!**

### 🟩 8x8 Chessboard: Possible!

```
Enter your chessboard dimension: 8
SOLUTION NUMBER - 1
```
![8-Queens Solution](./screenshots/8queens_solution.png) <!-- You can save the screenshot as per your repo -->

#### ASCII Board Example

```
.  Q  .  .  .  .  .  .
.  .  .  Q  .  .  .  .
.  .  .  .  .  Q  .  .
Q  .  .  .  .  .  .  .
.  .  .  .  Q  .  .  .
.  .  Q  .  .  .  .  .
.  .  .  .  .  .  Q  .
.  .  .  .  .  .  .  Q
```
- `Q` = Queen 🟪
- `.` = Empty square

---

## 🔁 How Does the Algorithm Work? (Backtracking)

### Step-by-step (in Simple Words):

1. Start from the first row.
2. Try to place a queen in each column, one by one.
3. For each placement, check:
    - Is it safe? (No queen in same column/diagonal)
4. If safe, move to next row and repeat.
5. If you can't place a queen, **backtrack** (go up a row, move queen).
6. Repeat until you finish the board or run out of options.

---

## 🔗 Mermaid Flowchart

```mermaid
flowchart TD
    Start([Start]) --> Row1[Try to place queen in row 1]
    Row1 --> CheckSafe1{Is position safe?}
    CheckSafe1 -- Yes --> Place1[Place queen, go to next row]
    CheckSafe1 -- No --> NextCol1[Try next column]
    Place1 --> Row2[Try to place queen in next row]
    NextCol1 --> CheckSafe1
    Row2 --> CheckSafe2{Is position safe?}
    CheckSafe2 -- Yes --> Place2[Place queen, go to next row]
    CheckSafe2 -- No --> NextCol2[Try next column]
    Place2 --> EndRow[...continue for all rows...]
    EndRow --> AllPlaced{All queens placed?}
    AllPlaced -- Yes --> Solution[Found Solution! 🎉]
    AllPlaced -- No --> Backtrack[Backtrack]
    Backtrack --> Row2
```

---

## 🌳 Backtracking Tree (for 4-Queens)

```
Level 0: Try Q at (0,0) (0,1) (0,2) (0,3)
 |
 |--(0,0)
 |   |--(1,0) X
 |   |--(1,1) X
 |   |--(1,2) ✓
 |        ...
 |--(0,1)
 |   |...
 |--(0,2)
 |   |...
 |--(0,3)
     |...
(X = not safe, ✓ = safe and continue)
```

---

## 📝 Sample Code (C, Simple)

```c
bool is_safe(int* board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

bool solve_nqueens(int* board, int row, int n) {
    if (row == n) return true;
    for (int col = 0; col < n; col++) {
        if (is_safe(board, row, col, n)) {
            board[row] = col;
            if (solve_nqueens(board, row + 1, n)) return true;
        }
    }
    return false;
}
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

## 📷 Example Screenshots

### ❌ No Solution: 2x2 Board

```
NO SOLUTION POSSIBLE
```

### ✅ Solution: 8x8 Board

```
SOLUTION NUMBER - 1
Q1 .  .  .  .  .  .  .
.  Q2 .  .  .  .  .  .
.  .  Q3 .  .  .  .  .
.  .  .  Q4 .  .  .  .
.  .  .  .  Q5 .  .  .
.  .  .  .  .  Q6 .  .
.  .  .  .  .  .  Q7 .
.  .  .  .  .  .  .  Q8
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

## 🏁 Summary Table

| Board Size | Number of Solutions |
|------------|--------------------|
| 1          | 1                  |
| 2          | 0                  |
| 3          | 0                  |
| 4          | 2                  |
| 8          | 92                 |

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
