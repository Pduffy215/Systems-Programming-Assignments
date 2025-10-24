# include "arraylib.h"
# include <stdio.h>


/*
This is the implementation of the functions in arraylib.h. 
Please read the comments in arraylib.h before you start working on this file.
*/

unsigned int find_all_matches(int arr[], int size, int target, int results[]){
    for (int i = 0;i < size;i++){  //creating the results array based on the size of input array
	       results[i] = -1;   //Making all values -1
	}	       
    int count = 0;                 //Initializing the count of matches found
    for (int i = 0;i < size;i++) { //creating for loop to search through array 
    	if (arr[i] == target) {    //If it finds a match then put that result in results array 
		results[count] = i; //Put it at the index of the number of matches found previously
		count++;             //Then add 1 to count
	}
    }	
    return count;
}

unsigned int sum_positives(int arr[], int size){
    int sum = 0;                  //Initializing sum variable to hold the sum of positive integers in array
    for (int i = 0;i < size;i++){ //Creating for loop to look through input array
	    if (arr[i] > 0) {     //If the value in array is positive, add it to sum
		    sum += arr[i];
	    } 
    }                             //return sum
    return sum;
}

bool contains_prime(unsigned int arr[], int size){
    for (int i = 0; i < size; i++) {       //loop through all elements in array
	    if (arr[i] <= 1) continue;    //1 and 0 are not prime so skip them
	    if (arr[i] == 2) return true;  //2 is prime so return true if found
 
            bool prime = true;              //Initialize prime to true
	    for (int j = 2; j <= arr[i] / 2; j++) { //loop through numbers from 2 to half the value
		    if (arr[i] % j == 0) {          //if any number divides evenly then it is not prime
			    prime = false;           //exit the loop if not prime
			    break;
		    }
	    }
	    if (prime) return true;    //if no factor has been found the it is prime
    }
    return false;      //if no prime numbers were found then return false
}


    

bool is_reverse_sorted(int arr[], int size){
    for (int i = 1; i < size; i++) {  //loop through array starting at second element
	    if (arr[i] > arr[i - 1]) { //if the values is greater than the one before it return false
		    return false;    
	    }
    }                                 //if nothing returns false then return true
    return true;
}

int find_max(int arr[], int size){
    if (size == 0) {
	    return 0;    //is size of array is 0 return 0
    }
    int value = arr[0];              //Initialize value to first element of array
    for (int i = 1; i < size; i++) {  //loop through all the other elements starting at the second one
	    if (arr[i] > value){     //if the current number is greater than the value variable 
		    value = arr[i];  //set value equal to the current number
	    }
    }
    return value;
}

int strlenm(char arr[], int max_length){
    for (int i = 0;i <= max_length;i++) { //loop through input array incrementing i for each loop
	    if (arr[i] == '\0') {      //if null terminator is found return i variable
		    return i;
	    }
    }                              //if null isnt found return -1
    return -1;
}

unsigned int strcnt(char arr[]){
    int count = 0;                            
    bool word = false;                          // Initialize count to 0 and word to false
    for (int i = 0;arr[i] != '\0';i++) {        // loop through array until Null is found                  
	    if (arr[i] == ' ' || arr[i] == '\t' || arr[i] == '\n' || arr[i] == '-') { 
		    word = false;     // If token is found set word to false because we aren't in a word
	    } else {
		    if (word == false) { // If not a token then if word is false add 1 to count
			    count++;     // And set word to true because we are in a new word
			    word = true;
		    }
	    }


    }                    
    return count;
}

int strfind(char arr[], char target){ 
    for (int i = 0; ;i++) {            //Loop through entire array, Incrementing i each loop
	    if (arr[i] == target) {   //If current value is target then return i
		    return i;
	    } if (arr[i] == '\0') {   //When Null is found check if the target is Null
		    if (target == '\0') { //If target is Null return i
			    return i;
		    }
		    return -1;   //If target is not Null then return -1 because the target has not been found
	    }
    }
}

