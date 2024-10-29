# Quick Sort Partition Algorithm (QUICK)

This algorithm is a partitioning step often used in the Quick Sort algorithm, where it organizes elements around a pivot element in a specified range of an array.

## Function Definition

**`QUICK(A, N, BEG, END, LOC)`**

- **Parameters**:
  - `A`: An array with `N` elements.
  - `BEG`: Starting index of the sublist to be partitioned.
  - `END`: Ending index of the sublist to be partitioned.
  - `LOC`: Tracks the position of the pivot element throughout the partitioning process.

---

## Algorithm Steps

1. **Initialization**:
   - Set `LEFT = BEG`, `RIGHT = END`, and `LOC = BEG`.

2. **Scan from Right to Left**:
   - (a) Repeat while `A[LOC] <= A[RIGHT]` and `LOC != RIGHT`:
     - Move `RIGHT` one step leftward: `RIGHT = RIGHT - 1`.
   - (b) If `LOC == RIGHT`, then **return**.
   - (c) If `A[LOC] > A[RIGHT]`, then:
     - Swap `A[LOC]` and `A[RIGHT]`.
     - Set `LOC = RIGHT` and go to Step 3.

3. **Scan from Left to Right**:
   - (a) Repeat while `A[LEFT] <= A[LOC]` and `LEFT != LOC`:
     - Move `LEFT` one step rightward: `LEFT = LEFT + 1`.
   - (b) If `LOC == LEFT`, then **return**.
   - (c) If `A[LEFT] > A[LOC]`, then:
     - Swap `A[LOC]` and `A[LEFT]`.
     - Set `LOC = LEFT` and go back to Step 2.

---

### Algorithm Steps

1. **Initialize Stack**:
   - Set `TOP = -1`.

2. **Initial Setup**:
   - If `N > 1`, then increment `TOP` by 1 and set:
     - `LOWER[TOP] = 0`
     - `UPPER[TOP] = N - 1`

3. **Iterate While Stack is Not Empty**:
   - Repeat steps 4 to 7 while `TOP != -1`.

4. **Pop Sublist from Stack**:
   - Set `BEG = LOWER[TOP]`, `END = UPPER[TOP]`, and decrement `TOP` by 1.

5. **Partition the List**:
   - Call `QUICK(A, N, BEG, END, LOC)` to partition the current sublist.

6. **Push Left Sublist to Stack (if any)**:
   - If there are elements to the left of `LOC` (`BEG < LOC - 1`), then:
     - Increment `TOP` by 1.
     - Set `LOWER[TOP] = BEG` and `UPPER[TOP] = LOC - 1`.

7. **Push Right Sublist to Stack (if any)**:
   - If there are elements to the right of `LOC` (`LOC + 1 < END`), then:
     - Increment `TOP` by 1.
     - Set `LOWER[TOP] = LOC + 1` and `UPPER[TOP] = END`.

---

