## Data types 

* Primitive 
    1. integer (for signed integer 0 positive 1 negative)
    2. float
    3. chracter
    4. boolean

* Derived
    1. function
    2. Array
    3. Pointer
    4. Refrence 

* User-Defined
    1. Class
    2. Structure
    3. Union
    4. Enum

range of integers  :
* signed integers =  -2^31 to 2^31-1
 * for unsigned integers  = 0 to 2^32-1

Float : 
   *  size =  4 bytes 
   * upto 7 decimal digits

Char:
   * size = 1 
   * stores in asci values


#### Type Modifiers 
 we can moify data type of variables. 
* eg. 
    * short 2 bytes
    * long 8 bytes
    * unsigned 4 bytes (but range is incresaed)
    * signed 4 bytes   (can store negative integers)


### How to include files in C++
#include<iostream> --- # Preprocessor Directive - used to include files

<iostream> - header file, compilaition of many predefined functions

main() - used to show starting of a program always int type function

## if else statement
for conditional statements. code will execute accordingly.

if(condition){
    execute if condition true
}
else{
    execute if condition is false
}

we can nest if else statements. 

# loops
for repetation of code. by using loop we can execute specific part of code over and over again. 
syntx :
    loop statement(condition){
        code will execute till condition is true
    }

* types of loops:
    1. for loop.
    2. while loop
    3. do .. while loop etc. 

## break and continue statement in loops
* break - breaks loop when triggred and program goes out from loop
* continue - skips all the programs in this iteration and directly goes to next iteration. 

## switching statement 
substitute for long if else statement. when input matches with any of case that code is executed. default case is executed if no case is satisfied. 
we have to use break statement in each case. 

## Functions
function is a piece of code that performs a specific task.
syntax of funcion 
return_type function_name(parameters){
    function_body
}

## Time Complexity
time complexity oF an algorithm quantifies the amount of the time taken by a program to run as a function of length of the input. 


## space complexity
space complexity of an algorithm quantiies the amount of the time taken by a program to run as a function of length of the input . It is directly proprotional to the largest memory your program  acquores at any instance during run time. 

study cases of time complexity from book


## Array 
list of variables of similar type. 

## selection sort
find the minimun element from unsorted array and swap it with element at begining.

## Bubble Sort 
Repetedly sort two elements if they are in wrong order. 

## insertion Sort
Insert an element from unsorted array to its correct positon in sorted array. 

## Subarray 
continuous part of array. number of subarrys in array with length n : nC2 + n = n*(n+1)/2

## subsequences 
this can be derived from array by selecting zero 
or more elements without changing the order of the 
remaining elements. 

number of subsequences : 2^n . 

Every subarray is subsequence but every subsequence is not subarray. 


## Two Dimensoinal Array
Declaration = datatype_declaratioin arr[n][m];

## Character Array
input : cin >> arr_name
output : cout << arr_name
to access perticular element: arr_name[index]

## Pointers
these are variable that store the address of other variables.

## pointer arithmatic
increment , decrement , addition , subtraction. 
after incrementing/decrementing pointer it goes to next/prev menory location.


## Stack and Heap
### Stack Memory allocation 
the memory is allocated on the function call stack. the memory gets deallocated as soon as the function call get over. deallocation is handled by compiler.

### Heap memory allocation
Allocation takes place on the pile of memory space available o programmers to allocated and deallocated. the programmer has to handle the deallocation.

* Delete Operatior
> to de-allocate memory P, we pass its address to delete() function
```cpp
// to de-allocate a memory,
// pointed by pointer 'p'.
delete(p)
```
* New Operator
new operator is used to allocate a block of memory of the given data type. 
```cpp
// Syntax
// mypointer = new <data_type>[size];
int *p = new int[10];
```
* Dangling Pointer 
in the memory location pointed by the pointer gets freed/deallocated, then the pointer is known as the Dangling Pointer. 

## Strings 
* no need to know size beforehand
* Performing operations like concatenation and append is easier.
* Terminate with special character '\0'.

```cpp
// use header file 'string' for using string funtions.
string str;
cin >> str;
str1(5,'n'); // nnnnn
str ="ValueWithoutSpace"; 
```

## BackTracking
Backtracking is algorithmic technique  for solving recursive problems by trying to build every possible solution incremently and removing those solution that fail to satisfy constraints of the problems at any point in time.


## Vectors and Pair
Vectors are dynamic arrays.
no need to allocate memory before hand in code.

```text
syntax to declare vector 
vector<datatype> name;
eg  vector<int> v;

to add element to vector
v.push_back(ele);

```
## Pair
```cpp
// pair <data_type1,data_type2> name;
// eg. pair 
pair <int,char> p;
p.first = 3;
p.second = 'f';
```

## Count Sort 
<br>

> 1. Find the count of every distinct element in array.
> 2. Calculate the position of each element in sorted array.
<br>

```text
Time Complexity : O(n)
only limited to small number of positive integers. 
space Complexity: O(max(Arr));
```

# OOP Concepts

### Classes 
```cpp
// Class declaration
class myClass{
    //Class Data
    string name;
}
```
Classes have objects which have the same data type as defined in the class

### Constructors in C++
default constructor is invoked as sonn as clas objects are created.It can be parameteried as well.

we have to specify default constructor if we make parameterized constructor.

they can access both public and private members of class.
```cpp
student(){}// default constructor
student(string s,int a,bool g){} // parameterized constructor.

```

### Copy constructor
used to copy the class objects. we have to write copy contructor.
```cpp
student(student &a){
    cout << "Copy Constructor"<< endl;
    name = a.name;
    age = a.age;
}
```

### Destructors 
invoked when object goes out of scope or destroyed by call to delete.
```cpp
~student(){}
```

### Getters Setters
they  are public functions to get/set private data members of class.

### Operator overloding
we can overload operators to work in class objects.

### Function Overloding
functions having the same name but different definatoins. the invoked function would depend on arguments you pass to functions. 

```cpp
float area(int r){ return 3.141*r*r; }

int area(int l,int r){ return l*r;}
```

<hr>

## Linked List

1. Size can be modified
2. Non contiguous memory
3. Isertion and deletion at any point is easier. 

<hr>

## Stack
stores a list of items can be added to or removed from list only at one end.

Last in First Out Principle

stack Operations
1. push(x) -> pushes element in stack
2. pop()   -> deletes element from stack
3. top()   -> gives value of first element 
4. empty() -> bool function checks if stack is empty or not.

> time complexity of these operations is O(1).

```text
1. at start top = -1;
2. At the time of pushing firstly increase top and then push value in stack.
3. At time of pushing reduce top.  
4. if top = -1, then stack is empty.
```
### Applications of Stack
#### prefix,infix and postfix
As computer doesn't know about BODMAS rule so we use prefix notation.
also called  as polished notation.

Postfix expresion - reverse polish notation


<hr>

## Queue 
last in first out.
implemented using array data structure.

```text
operations
1. enqueue - similar to push operation
2. dequeue - removes first element from queue.
3. peek()  - gives value at front.  
4. empty() - checks if queue is empty or not. 


use 2 pointers. front and rear.
initiate them with values -1. 

```
<hr>

## binary tree
every node in binary tree can have atmost 2 children.

A binary tree is a finite set of nodes that is either empty or consists of a 
root and two disjoint binary trees called the left subtree and the right 
subtree.
* Properties
1. Max nodes at lvl L  = 2^L
2. Max nodes in tree of height H = 2^H - 1.
3. Min number of levels for node N = log2(N+1).
4. A binary tree with L leaves has at least log2(N+1) +1   levels. 
5. parent node of ith node is i/2
6. left chile of node is 2i if 2i<= n(total number of nodes)
    a) if 2i > n then no left child for ith node.
7. Right child of node i is node 2i+1 if 2i+1 is <=n
    a) but if 2i+1 > n, node i has no right child. 

### Tree traversals

convension :- left must be visited before right node. 
so three possible ways
1. Inorder traversal.
2. Postorder traversal.
3. preorder traversal.


* other 2 types are
1. Breadth first
2. Depth first

<br>

### Breadth First Traversal
* All nodes at a given positins are visited first then nodes on the next lvl are visited.
* Usually in a left to right fasion
* this is implemented with a queue.

<br>

### Depth Traversal
* All nodes at a given brach are visited before any other are visited.
* there are 3 common depth first traversals.
    * Inorder
    * Preorder
    * Postorder

<br>

1. PreOrder traversal
    > Root ->
    > Left subtree ->
    > right subtree

2. PostOrder Traversal
 > left subtree ->
 > Right Subtree ->
 > Root

3. Inorder Traversal
> left subtree ->
> Root ->
> Right subtree

<br>

## Building of subtrees
1. with PreOrder and Inorder
```text
Algorithm
1. Pick an element from preorder and create a node.
2. Increment preorder idx.
3. Search for picked element's pos in inorder
4. call to build left subtree from inorders 0 to pos-1
5. call to build right subtree from inorders pos+1 to n
6. return code
```

2. with PostOrder and Inorder
```text
Algorithm
1. start from end of postorder and pick an element to creat a node
2. decrement postorder idx
3. search for picked elements pos in inorder
4. call to build right subtree from pos+1 to n
5. call to build left subtree from inorder 0 to pos-1
6. return the node
```

3. we can not make tree from only preOrder and postOrder as there can be more than 1 formations of skewed tree with similar pre and post order traversals. 

4. Level Order Traversal.
use of queue for traversal.

```text
```

<br>

### Binary Search Trees

1. Left subtree of a node contains only node with keys lesser than node's key
2. right subtree of a node contains only nodes with keys greater than node's key.
3. left and right subtree must also be BST. No duplicate nodes.

searching in BST :- o(logn) n - nodes in tree.
height of tree - log(n+1).

## Catlan numbers

<br>

![alt text](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-6e37684751c57a980ebaca5148b4736a_l3.svg)

### Applications of Catalan numbers
1. Possible BST.
2. Parathensis/ basket combinations
3. Possible forest
4. possible ways to find path in matrix
5. Dividing circles in N chords.
6. Dyck words of given length etc.

<br>

## Sets

* Ordered Set
1. Contains unique values.
2. implemented using balanced BST.  
3. Elements are in sorted ordered.
4. random access is not possible.
5. present in <set> header file.

```cpp
// insertion and print values of set.
set<int> s;
s.insert(1);
s.insert(2);
s.insert(3);
s.insert(4);
s.insert(5);
// print elements in set
for(auto i : s){
    cout << i << " ";
}
for(auto i = s.begin() ; i != s.end; i++){
    cout << *i << " ";
}

// print elements in reverse order
for(auto i = s.rbegin(); i!= s.rend();i++){
    cout << *i << " ";
}
// size of set
cout << s.size();

```
* Custom operator
```cpp
// printing elements in asending or descendig order
set<int , greater<int>> s;
s.insert(1);
s.insert(2);
s.insert(3);

// print element in the set.
for(auto i:s){
    cout << i << " ";
}
cout << endl; 
//print element in descending order.
```

* Upper and lower bound
```cpp
set <int> s;
s.insert(1);
s.insert(2);
s.insert(3);

cout << *s.lower_bound(2) << endl;
cout << *s.lower_bound(3) << endl;
cout << *s.upper_bound(3) << endl;
cout << (*s.upper_bound(5) == s.end() )<< endl;
```

* erase elemet in set.
```cpp
s.insert(1);
s.insert(3);
s.insert(2);
s.insert(5);

s.erase(2);
s.erase(s.begin());
```

### Multiset

1. can contain duplicates
2. implemented using balanced BST
3. Elements are in sorted order
4. random access is not possible i.e. to get ith element in log(n) time period
5. Present in #include<set> header file.

```cpp
// if we erase any element from multiset, every occurance of that element gets deleted.
// if we want to delete only 1 element then do the following

multiset<int> ms;
ms.insert(1);
ms.insert(2);
ms.insert(3);
ms.insert(3);
ms.insert(3);
ms.insert(3);

ms.erase(ms.find(3)); // ms.find will give you the pointer tofirst occurance of 3 and that three will get deleted.

```

```text

Time complexity of operations
1. insertion : O(log N)
2. Deletion : O(log N)
3. Lower/Upper_bound : O(log N)
4. print : O(NlogN);
```


* Unordered Set
1. contains unique element only
2. Implemented using hashing
3. elements are not in sorted ordered.
4. Random access is not possible.
5. Present in #include<unordered_set> header file

<br>

### Heaps
heap is binary tree based data structures. they are not necessarily Binary Search Tree.

1. minHeap - root is smallest element.
2. maxHeap - root is max element.

* How to convert an array into a maxheap ?
start adding an node to binary tree and check if current node is smaller than its root element. 
if not then swap those node. (heapify).

* how to pop element from heap.
pop root ans then replace it with max element from remaining elements.


### heap in STL
1. MAXHEAP : priority-queue<int, vector<int>>.
2. MINHEAP : priority-queue<int, vector<int> , greater<int>>

* push - Log(N).
* Pop - Log(N).
* top - O(1).
* size - O(1).

<br>

### Hashing

why hashing ?
sequential search requires o(n) comparisons. not useful for large database.
binary search requires O(nlogN) but array should be sorted. 

What is Hashing ?
Record for the key value is directly referred by calculating address from key value
* Address of element x is obtained by computing arithmetic function f(x).
* Function f(x) is called as hash function
* Table used for storing records is known as hash table
* Best Case Time Complexity of hashing=O(1)
* Worst Case Time Complexity =O(n)

## collision
* generation of same keys after hashing function.
Collision handeling
* seperate chaing  -> if collision, create a chain of values at same key using linked list. O(n).
    Load factor-> n/b.

* open Addressing -> if collision do probing.
    using second argument called probe number in the hash function. probe number depends upon key, hence given by P(k).

Linear Probing: P(K) = a*k+b

Quadratic Probing: P(K) =  a*k<sup>2</sup> + b*k + c

Double Hashing: P(k,x) = K*h<sub>2</sub>(X), h<sub>2</sub>(X) is secondery hashing function.

hashing is implemented using ordered and unordered map.
* Ordered Map
1. Insertion : O(log(n))
2. Accessing : O(log(n))
3. deletion : O(logN)

Implemented Using Red/Blck tree

Key Value

map<int,int>mp;

* Unordered Map
1. Insertion : O(1)
2. Accessing : O(1)
3. deletion : O(N)

Implenented using Hash Tables.(basically array of Buckets)
unordered_map<int,int> ump;

<br>

## Greedy Algorithm
it works in phases. 
1. at each phase take what is best without regard for future.
2. hope by choosing local optimum at each step you will end up choosing global optimum.

* used to solve problems that have n inputs and require us to obtain a subset that satisfies some constranits.
* any subset that satisfied the constraints is called as a feasible solution
* at each stage choose optimal solution.


### Problems on Greedy Algorithm
1. coin changing problem
    an optimal solution to coin changing problem is the minimum number of coins whose total value equals a specific amount. for ex. min coins for 83 cent (IND mint)
    Objective Function : Min number of coins returned.
    Greedy Solution : Always return largest coin you can 

* Approach
    1. set removal =  initial_value
    2. choose largest coin that is less than removal
    3. add coin to set of coins and set removal = removal - coin_value.
    4. repeat step 2 and 3 until reomoval = 0

* Feasible solution : any subset of sol that satisfies problem
* Optimal Solution : feasible sol that maximizes or minimizes objective function is called an optimal solution.
