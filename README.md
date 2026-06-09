# Polish Olympiad in Informatics (OI) Archive

This repository contains my personal archive of over 200 C++ solutions written during my rigorous preparation for the Polish Olympiad in Informatics (OI), where I became a two-time National Semi-Finalist.

## Graphs & Trees

**Graph Traversal:**
* **BFS (Breadth-First Search)** – Used for finding shortest paths in unweighted graphs (e.g., files 556876.cpp, 442082.cpp, 507971.cpp, 332160.cpp, 334415.cpp).
* **DFS (Depth-First Search)** – Used for cycle detection, connectivity, and tree traversals (e.g., files 605981.cpp, 3167968.cpp, 3190124.cpp, 3190238.cpp, 450133.cpp, 455565.cpp, 505885.cpp, 505929.cpp, 505933.cpp, 506225.cpp, 507939.cpp, 509263.cpp, 511585.cpp, 331728.cpp, 331747.cpp, 331958.cpp, 523445.cpp, 483467.cpp, 483584.cpp, 484575.cpp, 484814.cpp, 502654.cpp, 502655.cpp).

**Shortest Paths:**
* **Dijkstra's Algorithm** – Finding shortest paths in weighted graphs using a priority queue (e.g., files 556876.cpp, 441309.cpp, 443198.cpp, 455971.cpp, 456445.cpp, 497723.cpp, 497185.cpp, 523119.cpp, 505927.cpp, 436630.cpp, 532941.cpp, 535473.cpp, 535656.cpp, 347029.cpp, 333642.cpp, 333978.cpp, 497296.cpp).

**Spanning Trees:**
* **Kruskal's / Prim's Algorithms** – Finding the Minimum Spanning Tree (MST) (e.g., files 505932.cpp, 505934.cpp, 492593.cpp).

**Advanced Graph Operations:**
* **SCC (Strongly Connected Components)** – Tarjan's or Kosaraju-Sharir algorithm using post-order traversal (e.g., files 606017.cpp, 523605.cpp, 523646.cpp, 509166.cpp).
* **Topological Sorting** – Ordering vertices in a Directed Acyclic Graph (DAG) (e.g., files 606017.cpp, 452273.cpp, 452605.cpp, 523114.cpp, 523646.cpp, 502488.cpp, 509166.cpp, 502369.cpp, 502388.cpp, 502401.cpp, 502483.cpp).
* **LCA (Lowest Common Ancestor)** – Finding the lowest common ancestor using binary lifting (e.g., files 505885.cpp, 505929.cpp, 505933.cpp, 506225.cpp, 507939.cpp, 509263.cpp, 505891.cpp, 505927.cpp).
* **Centroid Decomposition** – Finding the centroid of a tree (file 3167968.cpp).

## Data Structures

* **Segment Trees / Fenwick Trees (BIT)** – Point-to-range and range-to-range trees (often implemented on an array of size `2 * BASE` with lazy propagation) used for sums, minimums, maximums, and element counting (e.g., files 555606.cpp, 559131.cpp, 3167968.cpp, 3190732.cpp, 3200304.cpp, 583202.cpp, 449626.cpp, 449627.cpp, 453184.cpp, 455072.cpp, 455865.cpp, 523112.cpp, 523116.cpp, 493885.cpp, 508323.cpp, 509263.cpp, 509787.cpp, 511585.cpp, 519924.cpp, 523871.cpp, 345056.cpp, 345081.cpp, 436874.cpp, 436876.cpp, 456446.cpp, 365110.cpp, 365113.cpp, 507570.cpp, 507831.cpp, 509154.cpp, 523440.cpp, 496480.cpp, 503475.cpp).
* **Disjoint Set Union (DSU)** – Managing connected components with path compression optimization (e.g., files 605981.cpp, 445637.cpp, 505934.cpp, 507950.cpp, 507383.cpp, 507386.cpp, 507525.cpp, 485108.cpp, 503069.cpp).
* **Trie (Prefix Tree)** – Efficient structure for searching and storing words/patterns (file 3190124.cpp).
* **Prefix Sums** – Static 1D and 2D arrays accumulating values for range sum queries in $O(1)$ time (e.g., files 584925.cpp, 506225.cpp, 320304.cpp, 345656.cpp, 346045.cpp, 320301.cpp, 334190.cpp, 366178.cpp, 367418.cpp, 367423.cpp, 367441.cpp, 378838.cpp).

## Algorithmic Techniques

* **Binary Search** – Classic element search in a sorted array (`std::lower_bound` / `std::upper_bound`).
* **Binary Search on Answer** – Reducing an optimization problem to a decision problem using a state-checking function (e.g., files 556660.cpp, 2490949.cpp, 437759.cpp, 437769.cpp, 440119.cpp, 441587.cpp, 505931.cpp, 583202.cpp, 494513.cpp, 509628.cpp, 511585.cpp, 519709.cpp, 322017.cpp, 323265.cpp, 323804.cpp, 326945.cpp, 353716.cpp, 353732.cpp, 436026.cpp, 501495.cpp, 521242.cpp, 521299.cpp, 521658.cpp, 521703.cpp, 472968.cpp).
* **Two Pointers / Sliding Window** – Linear time optimization technique using two pointers traversing an array or string (e.g., files 579140.cpp, 584602.cpp, 584925.cpp, 493293.cpp, 436713.cpp, 343610.cpp, 322033.cpp, 322034.cpp, 399626.cpp).
* **Mo's Algorithm** – Offline processing of range queries using square root decomposition (file 584602.cpp).

## Dynamic Programming (DP)

* **Knapsack Problem** – Optimal selection of items under a strict constraint (e.g., files 587295.cpp, 449622.cpp, 346983.cpp, 523115.cpp, 521030.cpp, 520984.cpp, 460920.cpp, 523444.cpp).
* **LCS (Longest Common Subsequence)** – Finding the longest subsequence common to sequences (e.g., files 449623.cpp, 331016.cpp).
* **LIS (Longest Increasing Subsequence)** – Finding the longest increasing subsequence, optimized to $O(N \log N)$ complexity (e.g., files 441587.cpp, 454500.cpp, 331142.cpp, 521242.cpp, 521299.cpp, 521658.cpp, 521703.cpp, 472968.cpp).
* **Range / Palindromic DP** – Dynamic counting of substrings or subproblems over discrete segments (e.g., files 523205.cpp, 523207.cpp).
* **Other DP Variants** – Bitmask DP (files 3181811.cpp, 509628.cpp) and Grid DP (files 576504.cpp, 328345.cpp, 328497.cpp, 378858.cpp, 522387.cpp, 523425.cpp, 523426.cpp, 523449.cpp).

## String & Mathematical Algorithms

* **KMP (Knuth-Morris-Pratt)** – Linear time pattern matching using a prefix-suffix table (file 523194.cpp).
* **String Hashing** – Converting strings to polynomial hashes modulo, utilizing double hashing for collision resistance (e.g., files 523107.cpp, 461506.cpp, 461514.cpp).
* **Euclidean Algorithm (GCD)** – Finding the Greatest Common Divisor (e.g., files 564026.cpp, 3189097.cpp, 325434.cpp, 326014.cpp, 350426.cpp, 352982.cpp, 364527.cpp, 460881.cpp).
* **Sieve of Eratosthenes** – Efficient prime number generation and integer factorization (e.g., files 325023.cpp, 325750.cpp, 367441.cpp, 436407.cpp).
* **Modular Exponentiation** – Calculating powers in logarithmic time with modulo arithmetic (file 522640.cpp).
* **Big Integer Arithmetic** – Operations on arbitrarily large numbers represented as strings (e.g., files 2496869.cpp, 518900.cpp, 503517.cpp, 503558.cpp, 503966.cpp).

## Greedy Algorithms & Backtracking

* **Backtracking** – Algorithms generating or exploring complex state spaces (e.g., Sudoku solver in 570229.cpp, board state exploration in 581345.cpp).
* **Greedy Algorithms** – Choosing locally optimal solutions for interval scheduling, coin change, and timeline manipulation (e.g., files 575125.cpp, 575157.cpp, 593401.cpp, 457267.cpp, 457293.cpp, 464223.cpp, 520402.cpp, 503114.cpp).

## Simulations & Computational Geometry

* **Ad-hoc / Geometric Simulations** – Implementations involving grid movement, rotations, distance bounds, and spatial calculations (e.g., file 556764.cpp for bit pattern drawing, 2527186.cpp for board movements, 440388.cpp, 493928.cpp for 3D spatial distance metrics, 504701.cpp).
