# Data Structures in C

A collection of C programs implementing fundamental data structures and algorithms. This repository serves as a learning resource for understanding how core data structures work under the hood, including Linked Lists, Stacks, Queues, Trees, and Graphs.

## 📂 Repository Contents

The code is organized by data structure type. Below is a breakdown of the files:

### 🔗 Linked Lists
* **`lschain.c`** - Singly Linked List implementation.
* **`double.c`** - Doubly Linked List implementation.
* **`circle.c`** - Circular Linked List implementation.

### 📚 Stacks (Piles)
* **`pileSt.c`** / **`pile2st.c`** - **Static** Stack implementation (using arrays).
* **`pileDy.c`** / **`pile2dy.c`** - **Dynamic** Stack implementation (using linked lists).

### 🚶 Queues (Files)
* **`filest.c`** / **`filest(1).c`** - **Static** Queue implementation (using arrays).
* **`fileDy.c`** / **`filedy.c`** - **Dynamic** Queue implementation (using linked lists).

### 🌳 Trees
* **`arbre.c`** - General Tree structure implementation.
* **`arbreBi.c`** / **`arbrebi.c`** - Binary Tree implementation.

### 🕸️ Graphs & Algorithms
* **`graph.c`** / **`graph(1).c`** - Graph data structure representation.
* **`bfs.c`** - Breadth-First Search (BFS) algorithm traversal.

### 🧮 Misc
* **`fac_cal.c`** - Factorial calculation utility.
* **`ex.c`** - Miscellaneous exercises/examples.

## 🚀 How to Run

To run any of these programs, you need a C compiler (like `gcc`).

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/mdriouec/data_strcture_staffs.git](https://github.com/mdriouec/data_strcture_staffs.git)
    cd data_strcture_staffs
    ```

2.  **Compile a file:**
    Replace `filename.c` with the file you want to run (e.g., `lschain.c`).
    ```bash
    gcc filename.c -o output
    ```

3.  **Run the executable:**
    * **Linux/Mac:**
        ```bash
        ./output
        ```
    * **Windows:**
        ```bash
        output.exe
        ```

## 🛠️ Tech Stack
* **Language:** C

## 📜 License
This project is licensed under the **GPL-3.0** License.
