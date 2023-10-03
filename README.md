# Data-structures-Lab

This repository comprises of all the Data structures & Programming lab exercises at University of Hyderabad(2021-2022)..


WEEK-1:

1. Implement Stack using Arrays and using Linked lists [Push, Pop, Display].
2. Implement Queues using Arrays and using Linked Lists [Enqueue and Dequeue].
3. Write a program to implement Tower of Hanoi without recursion. Also Debug the code using gdb debugger. Share the screenshots of the gdb execution part in your assignment.
4.  Write a program that convert the infix Expression in to Postfix Expression and then evaluate  the postfix expression using stacks. [Note: There should be atleast one two digit operand in the expression] 
5. Given an array of integers and a number ‘n’, find the smallest subarray with sum greater than the given value. Display the smallest subarray by adding the size of the subarray to  each element in the subarray. 
Example - 1 
Arr[] = {1,4,45,6,0,19}, n = 51 
Smallest Subarray is {4,45,6} 
Output is {7,48,9} 
Example – 2 
Arr[] = {1,11,100,1,0,200,3,2,1,250}, n = 280 
Smallest subarray is {100,1,0,201} 
Output is {104,5,4,204}

WEEK-2:

Question - 1 
 Write a Program that ask user to enter the string (Note : string can contain only  ‘(’ , ’)’ , ’[’ , ’]’, ‘{’ , ‘}’ these mentioned 6 characters only ) 
 You have to determine that input string is valid or not. 
 A input string is valid if and only if : 
 1. Open bracket must be enclosed by the same bracket.  2. Open Brackets Must be closed in correct order 
 Example 1 
 Input : “()” 
 Output : true 
 Example 2 
 Input : “([)]” 
 Output : false 
 Example 3 
 Input : “{}[{}]()()”
 Output : true 
 Example 4 
 Input : “{)” 
 Output : false 
 
Question - 2 
 Create a singly link list which contains either 0 or 1 as element only 
1. Provide an Insert function for inserting nodes with value either 0 or 1  only.(insert it at beginning or end) 
2. Provide a function to calculate equivalent decimal value by taking singly link  list elements as binary number. 
Like This 
 Consider You created Single link list in this fashion 
Example - 1 
Link list : 0 -->1-->0-->1 
Decimal Equivalent function output : 5 
Example - 2 
Link list : 1 -->0-->0-->0 
Decimal Equivalent function output : 8 
Example - 3 
Link list : 1 -->1-->0-->0 
Decimal Equivalent function output: 12 
Example - 4 
Link list : 1 -->0 
Decimal Equivalent function output: 2
3. Avoid use of Switch cases 
4. Your program should be able to handle the exception in user input 
  
Question 3: 
Write a source code to create a singly circular linked list. A node should consist of 
• Character array to store three strings in “info” part 
• Address of next node as “link” part 
The following are the operations: 
a) Create five nodes dynamically in a linked list with string values as given bellow (c) in  the “info” part 
b) Third string value in the current node should match the first string value in the next  node 
c) Display five nodes as follows 
1. blue red green 
2. green black yellow 
3. yellow white orange 
4. orange grey violet 
5. violet brown blue 
d) Display only the second-string values of a linked list 
e) Replace first string values of the first and fifth node with the value “color” string and  display all five nodes and also display the output as “String not matching” 

WEEK-3

Question 1:
Write a source code how to implement efficiently multiple queues in a single array. 1. Multiple queues are 4 
2. The Queue, name Q1 should contain 5 elements 
3. Second Queue, name Q2 should contain 3 elements 
4. Third Queue, name Q3 should contain 2 elements 
5. Fourth Queue, name Q4 should contain 6 elements 
6. Delete operation should perform on the maximum number of elements in queue 7. Insert operation should perform on the minimum number of elements in the Queue 
8. Perform the sequence of operations: Delete, Delete, Delete, Insert, Insert, Delete, Display all  four queues. 
Question 2: Split a Circular Linked List into two halves 
Given a Circular Linked List of size N, split it into two halves circular lists. If there are odd number of  nodes in the given circular linked list then out of the resulting two halved lists, first list should  have one node more than the second list. The resultant lists should also be circular lists and not linear  lists. 

Example 1:
Input: 
Circular LinkedList: 1->5->7 
Output: 
1 5 
7
Example 2: 
Input: 
Circular LinkedList: 2->6->1->5 
Output: 
2 6 
1 5



Question 3: 
Write a source code on how to implement a priority queue 
Consider, 
1. Create Queue using arrays 
2. Input for the Queue is the name of the student, Gate score of the student(G1) 3. Perform the operations:  
Insert(name,G1), 
Insert(name,G2(G2>G1)), 
Insert(name,G3(G3<G2)), 
Insert(name,G4(G4=G2)), 
Delete, 
Insert(name,G5(G5<G2)), 
Delete,  
Display the name of the student along with Gate Score

WEEK-4:

1.Create a Binary tree & print it in tree format..
&calculate Height,Inorder,Preorder & post order traversals..

2.Input an infix expression & check the validity of infix expression ...Convert it into prefix,postfix notations.

WEEK-5

1. Accept the list of words (input) as a category  
a. Physical Activity 
b. Education 
c. Food  
d. Work 
e. Hobby 
f. Family 
g. Worship 

  2. The following list of words to be mapped in the respective basket as (group/cluster) of  above categories and each word is assigned with the number as frequency. You have       to accept the word number of times based on the frequency given through keyboard randomly. 
  a. Exercise -3 
  b. God 
  c. Book-7 
  d. Relative-3 
  e. Lunch-5 
  f. Gardening-2 
  g. Meeting 
  h. Prayer 
  i. Football-2 
  j. Studying-3 
  k. Class-6 
  l. Book reading-4 
  m. Story telling 
  n. Assignment 
  o. Daughter-2 
  p. Cake 
  q. Project-10
  
 3. From Steps 2 and 3 construct the following the tree 
  a. Level 0 is root {WORDS} 
  b. Level 1 is of categories (S.No.1) 
  c. Level 2 is of bunch of words (S.No.2) 
  d. Level 4 is the frequency of each word. The frequency range is from 2 to N. If  there is unique word, the frequency need not to be reflected. It should be  treated as leaf nodes .

4. Write a menu driven program for the following operations 
5. The following are the operations 
a. Create a tree structure by taking input from steps 1-3 
b. If the word repeats, the frequency values to be changed in the Level 4 c. Display leaf nodes excluding Level 4 
d. Find the depth of any node 
e. Find the degree of any node 
f. Display the words in frequency descending order


WEEK-6:

Implement Height balanced binary tree(AVL tree) in the following way(all nodes in the tree should be unique) 
provide an insert function to insert the node in the tree 
Provide a delete function to delete the node from the tree(by value) provide a function to display pre-order,in-order,post-order Level,level-order tree traversal 
Provide a function to calculate the sum of all nodes in the left subtree of the root node.

WEEK-7
 
Performance of Quick-Sort with four different pivots for partitioning 
Pivot-1: Choose the first element as pivot 
Pivot-2: Choose randomly the pivot element 
Pivot-3: Median of {First element, Middle element, Last element} Pivot-4: Median of {n/4th element, middle element, 3n/4th element} 
Performance of Merge-Sort 
Input Array types: 
1. Random numbers of integers in the range 0 to 10k ( k = 4,5,6,7) 2. Sorted array of (1) 
3. Almost Sorted of (1). ( This can be obtained by swapping 1% pairs of the  sorted array) 
Implement Quick_Sort(Array, Size_of_Array, Pivot_type)  
Implement Merge_Sort(Array, Size_of_Array) 
Report the time taken by all the four versions of Quick_Sort and Merge_sort on the input array as specified above.

WEEK-8

Q:1 Design a HashTable (atleast size >= 10) for Integers
        (Use Collision Resolution Technique : -Quadratic Probing)
       
        Provide following Function 
1 Insert a Key
2. Delete a Key
         3. Search a Key Using key Value
4. Calculate Load Factor

Q:2 Design a HashTable (atleast size >= 10) for Integers
        (Use Collision Resolution Technique : -Double Hashing)
       
        Provide following Function 
1 Insert a Key
2. Delete a Key
         3. Search a Key Using key Value
4. Calculate Load Factor

Q:3 Implement Heap-sort Algorithm Using Min-Heapify and Max-Heapify
       Procedures.

       Your Program Should Work Like This
        
       Choose option 
Using min-heapify
Using Max-heapify


After selecting either of the option 
          
     Implement following functions(for both options) : 
Build Heap by inserting some integers.
Insert a key into heap.
Delete function.
Sort function.

WEEK-9

Ques.1. Create a menu-driven program:-

(Take the No. of vertices from the user, enter the Node and make an adjacency matrix after that print the BFS and DFS traversal).

1.)Create a Graph.

2.)Do BFS traversal in the Graph

3.)Do DFS traversal in the Graph

WEEK-10

Ques.1.  Take String input from the User and find the longest palindromic in String(use concept of subString). 

Input 1:  S : "aaaabbaa"

Output:-  "aabbaa"

input 2 : S : "aaa aaa"

Output : "aaa aaa"


Questiion 2 : Implement Radix Sort Algorithm
Take Input array from the User Sort it Using Radix Sort Algorithm



 



 







