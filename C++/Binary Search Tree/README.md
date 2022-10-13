# We can implement Binary Tree using:

1. Dynamically Created Nodes
2. Arrays (For a complete binary tree, for node at index i, left-child index = 2 * i + 1, right-child index = 2 * i + 2)

# Memory Allocation in Stack and Heap:

### There can be 4 subsections in a memory, namely:

**1. Code(Text) :** to store compiled instructions in compiled language in the program\
**2. Static/Global :** to store allthe global variables\
**3. Stack :** space for function call execution, local variables defined within functions lay in stack\
**4. Heap :** free store, dynamic memory allocation that can grow or shrink as per our memory during run-time\

#### Refer to the Code `implement.cpp` 

- When program starts execution, `main()` function will be called, whenever a function is called, some amount of memory in `Stack` section is allocated for its execution and it is called as the `Stack Frame`. All the local variables and state of execution of the function call are stored here. At each function call, the memory is allocated one over another in the `Stack` section of the computer memory.
- The pointer `newNode` creates a new dynamic memory space in the `Heap` section of memory and execution of `Stack` section will be paused while doing this.
