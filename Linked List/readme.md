# Linked List
It is a linear data structure that can be visualized as a chain with different nodes connected, where each node represents a different element. The difference between arrays and linked lists is that, unlike arrays, the elements are not stored at a contiguous location.

Since for any element to be added in an array, we need the exact next memory location to be empty, and it is impossible to guarantee that it is possible. Hence adding elements to an array is not possible after the initial assignment of size.
![image](https://github.com/user-attachments/assets/dd2817e5-207b-44f6-af78-edd13567473f)

A linked list is a data structure containing two crucial pieces of information, the first being the data and the other being the pointer to the next element. The ‘head’ is the first node, and the ‘tail’ is the last node in a linked list.

![image](https://github.com/user-attachments/assets/5ffc8712-28f7-47db-88d0-924483a0fe32)

# Working
- The struct has two data types: data which contains the value of the node and a pointer next, which points to the next node in the list.
- There is a constructor which assigns the values to a new node.
- A new keyword is used to dynamically allocate memory to a node with data as arr[0].
- The combination of the given parameters and functions initializes a linked list.

#  Understanding Pointers
A pointer is a variable that stores the memory address of another variable. In simpler terms, it "points" to the location in memory where data is stored. This allows you to indirectly access and manipulate data by referring to its memory address.

Java does not explicitly use pointers or take the address of variables as you do in C++. Instead, we have reference variables. These reference variables do not directly contain memory addresses like pointers in languages such as C or C++. Instead, they hold references to objects in memory.
Understanding the difference between Node and Node*: A node refers to the structure that contains data and the pointer to the next node. In contrast, Node* (Node pointer) specifically denotes a pointer variable that stores the address of the Node it is pointing to.

![image](https://github.com/user-attachments/assets/28d5ff0a-0252-4149-b697-2a6fb890eddf)

# Memory Space:
Let’s talk about assuming the data stored is integer. Another main difference between an array and a linked list is the memory used. In the case of an array, we are storing integers that consume 4 Bytes for every int, whereas in a linked list, we are storing data and a pointer at every node, so the memory used up will depend on the configuration of the system.

![image](https://github.com/user-attachments/assets/c901495b-e0d1-4146-b564-2cfe42a17710)

Therefore, in the case of a 64 Bit system, it occupies or consumes more space than a 32 Bit system.

# Applications of Linked Lists:

- Creating Data Structures: Linked lists serve as the foundation for building other dynamic data structures, such as stacks and queues.
- Dynamic Memory Allocation: Dynamic memory allocation relies on linked lists to manage and allocate memory blocks efficiently.
- Web Browser is one important application of Linked List.

# Types of Linked Lists:

- Singly Linked Lists: In a singly linked list, each node points to the next node in the sequence. Traversal is straightforward but limited to moving in one direction, from the head to the tail.

![image](https://github.com/user-attachments/assets/a99ad18e-c285-40ed-861b-6e6b86df6361)


- Doubly Linked Lists: In this each node points to both the next node and the previous node, thus allowing it for bidirectional connectivity.

![image](https://github.com/user-attachments/assets/08385384-b8d1-4201-80a0-f8b578ad0858)


- Circular Linked Lists: In a circular linked list, the last node points back to the head node, forming a closed loop.

![image](https://github.com/user-attachments/assets/2579f6ab-77b3-49b1-bc22-d68d4b38c16c)

