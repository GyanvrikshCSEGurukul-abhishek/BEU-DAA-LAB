# BEU DAA Lab

Complete **Design and Analysis of Algorithms (DAA) Lab** programs in C for B.Tech Computer Science and Engineering students.

This repository contains the 12 experiments listed in the supplied DAA Lab syllabus (Course Code: **105403P**). Each program includes explanatory comments and input validation where appropriate.

## Experiments

| No. | Experiment | Source file |
|---:|---|---|
| 1 | Quick Sort with execution-time measurement | [`programs/01_quick_sort.c`](programs/01_quick_sort.c) |
| 2 | Merge Sort with execution-time measurement | [`programs/02_merge_sort.c`](programs/02_merge_sort.c) |
| 3 | Transitive closure using Warshall's algorithm | [`programs/03_warshall.c`](programs/03_warshall.c) |
| 4 | 0/1 Knapsack using Dynamic Programming | [`programs/04_knapsack_01.c`](programs/04_knapsack_01.c) |
| 5 | Dijkstra's shortest-path algorithm | [`programs/05_dijkstra.c`](programs/05_dijkstra.c) |
| 6 | Minimum Spanning Tree using Kruskal's algorithm | [`programs/06_kruskal.c`](programs/06_kruskal.c) |
| 7 | Breadth-First Search (BFS) for reachable vertices | [`programs/07_bfs.c`](programs/07_bfs.c) |
| 8 | Graph connectivity using Depth-First Search (DFS) | [`programs/08_dfs_connected.c`](programs/08_dfs_connected.c) |
| 9 | Subset Sum using backtracking | [`programs/09_subset_sum.c`](programs/09_subset_sum.c) |
| 10 | Travelling Salesperson Problem: exact solution vs. nearest-neighbour heuristic | [`programs/10_tsp_exact_vs_nearest_neighbor.c`](programs/10_tsp_exact_vs_nearest_neighbor.c) |
| 11 | Minimum Spanning Tree using Prim's algorithm | [`programs/11_prim.c`](programs/11_prim.c) |
| 12 | N-Queens using backtracking | [`programs/12_n_queens.c`](programs/12_n_queens.c) |

## Requirements

- GCC or another C11-compatible compiler
- A terminal, Command Prompt, or PowerShell
- Basic knowledge of C and algorithms

## Compile and run

Open a terminal in the repository's root directory.

### Windows (MinGW-w64 GCC)

Compile an individual program, for example Quick Sort:

```powershell
gcc -std=c11 -Wall -Wextra -pedantic programs/01_quick_sort.c -o quick_sort.exe
.\quick_sort.exe
```

For another experiment, replace the source filename and executable name:

```powershell
gcc -std=c11 -Wall -Wextra -pedantic programs/04_knapsack_01.c -o knapsack.exe
.\knapsack.exe
```

### Linux or macOS

```bash
gcc -std=c11 -Wall -Wextra -pedantic programs/01_quick_sort.c -o quick_sort
./quick_sort
```

Compile and run each source file separately. The programs are independent; they are not intended to be linked together into one executable.

## Input notes

- Quick Sort and Merge Sort generate random integers; enter the number of elements when prompted.
- Warshall, BFS, and DFS use adjacency matrices.
- Dijkstra uses a weighted adjacency matrix; a value of `0` means no edge (except the diagonal). Edge weights must be non-negative.
- Prim uses a weighted adjacency matrix for an undirected graph; `0` means no edge.
- Kruskal takes an edge list in the form `u v weight`.
- Subset Sum expects positive integers and a positive target.
- TSP expects a complete, symmetric distance matrix with zero diagonal. The exact brute-force method is restricted to at most 10 cities because its running time grows factorially.
- N-Queens prints every solution for the selected board size; larger values can take a long time.

## Complexity overview

| Algorithm | Typical time complexity | Notes |
|---|---:|---|
| Quick Sort | Average `O(n log n)`, worst `O(n²)` | Pivot choice affects performance |
| Merge Sort | `O(n log n)` | Uses `O(n)` auxiliary memory |
| Warshall | `O(V³)` | Computes reachability |
| 0/1 Knapsack DP | `O(nW)` | `W` is capacity |
| Dijkstra (matrix) | `O(V²)` | Requires non-negative weights |
| Kruskal | `O(E log E)` | Sorts edges |
| BFS (matrix) | `O(V²)` | Queue-based traversal |
| DFS (matrix) | `O(V²)` | Checks undirected graph connectivity |
| Subset Sum | `O(2ⁿ)` worst case | Backtracking |
| TSP exact brute force | `O(n!)` | Practical only for small inputs |
| Prim (matrix) | `O(V²)` | For connected undirected weighted graphs |
| N-Queens | Exponential / factorial-style worst-case growth | Backtracking |

## Timing experiments

For Experiments 1 and 2, run the program with several values of `n` (for example `100`, `1000`, `5000`, and `10000`) and record the reported CPU time. Measured results depend on the computer, compiler options, and system load. Do not treat one run as a universal benchmark.

## Limitations and assumptions

These are educational implementations intended for lab practice. Follow each program's prompts for input format. In particular, Dijkstra does not support negative edge weights, and the TSP exact method is deliberately limited to small inputs.

## Contributing

Suggestions and corrections are welcome. Please open an issue describing the problem or submit a pull request with a clear explanation of the change.

## Academic note

Use this repository as a learning aid. Read and understand the algorithms, test the programs, and follow your institution's rules for lab submissions and attribution.

## License

No license is currently specified. Unless you add a license, others generally do not receive permission to reuse, distribute, or modify this repository beyond rights granted by applicable law. Add a license only after deciding which terms you want to use.
