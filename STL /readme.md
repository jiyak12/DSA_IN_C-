# STANDARD TEMPLATE LIBRARY(STL)
- To write codes in C++ , we need to use container or algo lots of times. It's difficult to pre-define container or write long xodes every time .
- STL is basically a compilation of algo containers or iterators and functors in a minimised version.
- It is a generalized library so we can use it with almost every data type without repeating the implementation code.

## C Skeleton
- #include<bits/stdc++.h> :  It's a shortcut that includes almost all standard C++ library headers
- #include<math.h> : This line includes the standard C math library header file. 
- using namespace std :  It allows you to use elements of the standard library without explicitly using std:: before them.
## Components of STL
The components of STL are the features provided by Standard Template Library (STL) in C++ that can be classified into 4 types:
- Containers : Containers are the data structures used to store objects and data according to the requirement. 
- Algorithms : Offer a wide range of functions to perform common operations on data (mainly containers). These functions implement the most efficient version of the algorithm for tasks such as sorting, searching, modifying and manipulating data in containers, etc
- Iterators : pointer like objects that are used to point to the memory addresses of STL containers & connect the STL algorithms with the containers. 
- Functors : It overloads the function-call operator () and allows us to use an object like a function.
## Vector
- A dynamic array that stores collection of elements same type in contiguous memory.
- It has the ability to resize itself automatically when an element is inserted or deleted.
 ### Creating a vector
 - vector is defined as `vector<T> v;` where T is the type of elements and v is the name assigned to the vector.
 - initialisation: provide the values to be stored in the vector inside {} curly braces.
![image](https://github.com/user-attachments/assets/0715d03a-344b-4d31-a11e-af7c123959c3)
### Insert Elements
#### vector(insert)
- An element can be inserted into a vector using vector insert(). It is a built-in function used to insert new elements at the given position in a vector.
- `v.insert (pos, val);` where val: Value to be inserted , pos: Iterator to the position where val is to be inserted
- `v.insert(pos, n, val)` where val - Value to be inserted, pos: Iterator to the position where val is to be inserted, n: Number of times val is to be inserted.
- `v.insert(pos, {val1, val2, ...});` where pos- Iterator to the position where range is to be inserted.
{val1, val2, ...} - Initializer list containing values to insert.
- `v.insert(pos, first, last)` where pos- Iterator to the position where range is to be inserted, first- Iterator to the first element in the range from which the elements are to be inserted, last- Iterator to the element one place after the last element in the range.
 #### vector push_back() 
 - A built-in method used to add a new element at the end of the vector.
 - Automatically resizes the vector if there is not enough space to accommodate the new element.
 - vector push_back() is a member method of the std::vector class defined inside the <vector> header file.`v.push_back(val);` where val: Element to be added to the vector at the end
 - used to a) add elements vector of strings at the end b)initialize an empty vector one by one.
#### Difference
![image](https://github.com/user-attachments/assets/32919d7d-f347-4cae-89a5-ae42fa1ea12c)
### Iterators
- An iterator is an object like a pointer that points to an element inside the container.
- `auto iteratorName;` where auto keyword automatically detected container type itself. and iteratorName is name assigned to the iterator.
![image](https://github.com/user-attachments/assets/46ef8424-c84c-4a14-be7f-782a42da7403) ![image](https://github.com/user-attachments/assets/c0fdd204-f954-465b-a6b4-c8a59c862c2c)
