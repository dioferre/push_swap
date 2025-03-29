# **push_swap** 🧮  
**A sorting program**  
*(Completed 7 Oct 2024)*  

---

### **About the Project** 📚

`push_swap` is a project developed as part of the 42 coding school curriculum. The challenge is to implement a sorting algorithm using only two stacks. The goal is to sort a list of integers with the least number of operations, demonstrating an understanding of algorithm efficiency and data structures. The program accepts unsorted numbers as input and outputs the sequence of operations needed to sort them, employing algorithms to optimize performance.

This project reinforces skills in problem-solving, coding efficiency, and algorithm design.

---

### **Available Operations** 🔧

The program has access to the following operations to sort numbers:

| **Operation** | **Effect** |
|:-------------:|:----------:|
| **pa**        | Pushes the top element from stack B onto stack A |
| **pb**        | Pushes the top element from stack A onto stack B |
| **sa**        | Swaps the two elements at the top of stack A |
| **sb**        | Swaps the two elements at the top of stack B |
| **ss**        | Executes the SA and SB operations simultaneously |
| **ra**        | Rotates stack A by moving the top element to the bottom, shifting all other elements one position up |
| **rb**        | Rotates stack B by moving the top element to the bottom, shifting all other elements one position up |
| **rr**        | Executes the RA and RB operations simultaneously |
| **rra**       | Rotates stack A in reverse by moving the bottom element to the top, shifting all other elements one position down |
| **rrb**       | Rotates stack B in reverse by moving the bottom element to the top, shifting all other elements one position down |
| **rrr**       | Executes the RRA and RRB operations simultaneously |

---

### **Algorithm Approach** 🚀

In this project, I tackled the challenge of implementing a sorting algorithm that is not commonly used by students and is not optimized for the project's specific constraints. While **quicksort** is widely known, I focused on adapting it to meet the unique rules of the project.

My implementation not only achieved outstanding scores but also surpassed all benchmark tests, sometimes requiring fewer moves than algorithms specifically designed for the project. Throughout the process, I made sure to maintain a codebase that is readable, concise, and efficient.

---

### **How It Works** ⚙️

As mentioned, my algorithm is an adaptation of **quicksort** specifically for this project. While it differs from the traditional version, it still retains the core principles of the quicksort algorithm.

The algorithm efficiently determines the median of a stack or chunk by internally organizing it, which significantly improves performance compared to using a pivot. In the `push_swap` project, efficiency is measured by the number of operations required to sort the list, not the speed of the sorting. Utilizing the median to split chunks effectively enhances the sorting process.

Additionally, my `sort6` function calculates the median of a chunk of size six (or less) to help split the chunk between the two stacks while simultaneously organizing both halves using operations such as **ss**, **rr**, and **rrr** whenever feasible.

---

### **Optimization Strategy** 🔍

The primary goal of the algorithm is to reduce the original stack to six or fewer elements for efficient sorting. This is done by recursively splitting the stack using the median until only three numbers remain in **stack A**, at which point they can be easily sorted. The median-based approach creates chunks in **stack B** that are relatively organized, ensuring all elements in the first chunk are smaller than those in the second.

Once the chunks are created in **stack B**, I sequentially push them onto **stack A** for sorting. If a chunk size is six or fewer, it is sorted directly. Otherwise, the chunk is further divided into three parts using the median, distributing them across **stacks A and B**. If any resulting chunk remains larger than six, the algorithm continues to split it until the chunks become manageable. After sorting the chunks, the algorithm reorganizes the elements that were split and redistributed, optimizing their arrangement further by splitting again if necessary.
