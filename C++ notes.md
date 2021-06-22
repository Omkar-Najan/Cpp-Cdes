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
space complexity of an algorithm quantiies the amount of the time taken by a progea to run as a function of length of the input . It is directly proprotional to the largest memory your program  acquores at any instance during run time. 

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