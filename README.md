# push_swap
A sorting program
(Completed 7 Oct 2024)


push_swap is a project developed as part of the 42 coding school curriculum, designed to implement a sorting algorithm using only two stacks. The goal of the program is to sort a list of integers with the least number of operations, demonstrating an understanding of algorithm efficiency and data structures. The program accepts unsorted numbers as input and outputs the sequence of operations needed to sort them, employing algorithms to optimize performance. This project reinforces skills in problem-solving, coding efficiency, and algorithm design.



The operations the program has access to sort numbers are the following:

PA: Pushes the top element from stack B onto stack A.

PB: Pushes the top element from stack A onto stack B.

SA: Swaps the two elements at the top of stack A.

SB: Swaps the two elements at the top of stack B.

SS: Executes the SA and SB operations simultaneously.

RA: Rotates stack A by moving the top element to the bottom, shifting all other elements one position up.

RB: Rotates stack B by moving the top element to the bottom, shifting all other elements one position up.

RR: Executes the RA and RB operations simultaneously.

RRA: Rotates stack A in reverse by moving the bottom element to the top, shifting all other elements one position down.

RRB: Rotates stack B in reverse by moving the bottom element to the top, shifting all other elements one position down.

RRR: Executes the RRA and RRB operations simultaneously.



In this project, I took on the challenge of implementing a sorting algorithm that is not commonly utilized by students and isn't optimized for the specific constraints of the project. While quicksort is one of the most widely used sorting algorithms, I had to put my focus on adapting it to meet the unique rules of the project.

My implementation not only achieved outstanding scores but also surpassed all benchmark tests, in some scenarios requiring fewer moves than algorithms specifically designed for this project. Throughout the process, I did my best to maintain a codebase that is readable, concise, and efficient.

-------------------------------------------------------------------------------------------------------------------------------------

How it works:

As mentioned above my algorithm is an adaptation of quicksort specifically for this project, therefore it differs a bit from the one that is traditionally used, but it still uses the same principles.

My algorithm is designed to efficiently determine the median of a stack or chunk by internally organizing it, which significantly improves efficiency compared to using a pivot. In the push_swap project, efficiency is largely measured by the number of operations performed to sort the list of numbers given, instead of how fast it can do it, utilizing the median to effectively split chunks enhances this process. Additionally, my sort6 function calculates the median of a chunk of size six (or less) to facilitate splitting the chunk between the two stacks while simultaneously organizing both halves using operations such as ss, rr, and rrr whenever feasible.

The primary objective of my algorithm is to reduce the original stack to a size of six or fewer elements for efficient sorting. This is accomplished through recursive splitting of the original stack using the median until only three numbers remain in stack A, at which point they can be easily sorted. This median-based approach creates chunks in stack B that are relatively organized, ensuring that all elements in the first chunk are smaller than those in the second.

Once the chunks are established in stack B, I sequentially push them onto stack A for sorting. If the chunk size is six or fewer, it is sorted directly; otherwise, the chunk is further divided into three parts using the median, distributing them across stacks A and B. If any resulting chunk remains larger than six, the algorithm continues to split it into smaller chunks until they are manageable. After sorting the chunks, the algorithm reorganizes the elements that were split and redistributed, attempting to optimize their arrangement further by splitting again if they exceed the size of six.
