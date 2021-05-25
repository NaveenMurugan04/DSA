
#include <iostream>
using namespace std;
// C program to demonstrate pointer to pointer 
int main() 
{ 
	int var = 789; 

	// pointer for var 
	int *ptr2; 

	// double pointer for ptr2 
	int **ptr1; 

	// storing address of var in ptr2 
	ptr2 = &var; 
	
	// Storing address of ptr2 in ptr1 
	ptr1 = &ptr2; 
	
	 **ptr1=1;
	// Displaying value of var using 
	// both single and double pointers 
	cout<<("Value of var = %d\n", var ); 
	cout<<("Value of var using single pointer = %d\n", *ptr2 ); 
	cout<<("Value of var using double pointer = %d\n", **ptr1); 
	
return 0; 
} 
