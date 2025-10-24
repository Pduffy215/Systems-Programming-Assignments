# include "mylib.h"
# include <stdio.h>


/*
This is the implementation of the functions in mylib.h. 
Please read the comments in mylib.h before you start working on this file.
*/
float int_to_float(int input) {
    float result = (float)input;  //change the integer into a float
    return result;                //return the float result
}

int factorial(int input){
    if (input < 0)     //return -1 if input is a negative number
	    return -1; 
    if (input == 0)    //return 1 if input is 0
	    return 1;
    int output = input;  //assign output variable to input for use inside for loop
    for (int i = input - 1;i > 0; i--) {  //assign i to be input - 1 so when it starts multiplying it dosen't do 4 * 4 
	    output = output * i;          //until i is 0 multiply output by i and store the answer. decrement i by 1 everytime 
    }                                    //when i is 0 return the output
    return output;
}

int sum(int input){
    int output = input; // assign output variable to input for use in for loops
    if (input > 0) {                             //if input is positive then set i to input - 1 to not do 4 + 4
	    for (int i = input - 1;i > 0;i--) {  //until i is 0 add i to output and store the answer. decrement i by 1 everytime
		    output = output + i;         
	   }
    } else if (input < 0) {                    //if inout is negative then set i to input + 1 so it goes to 0
	    for (int i = input + 1;i < 0;i++) { //unitl i is 0 add i to output and store the answer. inrement i by 1 everytime
		    output = output + i;
	   }
    }
    return output;	    //return output after all loops have completed
}

char grade_scale(float score){
    char output = 'A';   //initialize output variable 
    if (score > 100) {   //if the score is over 100 set output to X
	    output = 'X';

    }  else if (score >= 90) {      
	      output = 'A';

    } else if (score >= 80) {
	    output = 'B';

    } else if (score >= 70) {        // do if else chain for all values between 0-100 using appropriate ranges
	    output = 'C';
    
    } else if (score >= 60) {
	    output = 'D';
    
    } else if (score >= 0) {
	    output = 'F';
    } else {                        //if the score is anything else then assign output to 'X' 
           output = 'X';
    }                        // return output after everything
    return output;
}

bool is_even(int input){
    if (input % 2 == 0) {  // check if input mod 2 is 0 because if this is true then it is even
            return true;  // return true if its even
    } else {
	    return false;  // return false otherwise
    }
}

int num_factors(int input){
    int output = 1;          //set output to 1 to add a factor for the number itself 
    if (input <= 0)          //if input is 0 or negative the nreturn -1
	    return -1;                 
    for (int i = 1; i <= input/2; i++) {  //for every number less than half the input check the remainder
	    if (input % i == 0)           //if the remainder is 0 than it is a factor and add one to the output
		    output++;             //there are no factors after half the input except itself
    }
    return output;
}

int max_of_three(int a, int b, int c){
    int output = 0;  //Initialize output to 0
    if (a > b) {     //first compare a and b and make output equal to whever is greatest
	    output = a;
    } else {
	    output = b;  }
    if (c > output) {      //then compare that value to c and output whichever is greater
	    output = c; }
    return output;
}

int days_in_month(int month){
    int output = -1;   // Initialize output to -1 in case input is not a month
    switch (month) {   // Use switch to determine what to output from all the cases
	    case 1:
            case 3:
	    case 5:			    
	    case 7:   //if month is 1, 3, 5, 7, 8, 10, 12 it has 31 days so set output to 31
	    case 8:
	    case 10:
	    case 12:	    
		    output = 31;
		    break;
	    case 2:
	            output = 28; //if month is 2 set output to 28
		    break;
	    case 4:
	    case 6:
            case 9:   //if month is 4, 6, 8, 9 set output to 30
            case 11:
                    output = 30;
    		    break; //return output
    }
    return output;
}

float divide(int a, int b){
    if (b == 0)     //if b is 0 return -1 because division by 0 is undefined
	    return -1;
    return (float)a / (float)b;    //change a and b to float and divide them and return that value
}

char to_uppercase(char input){
    char output = '0';   //Initialize output to 0 in case input isnt a lwercase letter
    switch (input) {
	    case 'a':
		    output = 'A';
		    break;       
            case 'b':
		    output = 'B';
		    break;
	    case 'c':
		    output = 'C';
	 	    break;
	    case 'd':
		    output = 'D';
		    break;
	    case 'e':
		    output = 'E';
		    break;
	    case 'f':
		    output = 'F';
		    break;
	    case 'g':
		    output = 'G';
		    break;
	    case 'h':
		    output = 'H';
		    break;
	    case 'i':
		    output = 'I';   //go through all the lowercase letter and change them 
		    break;          // into there uppercase version with a switch
 	    case 'j':
		    output = 'J';
		    break;
	    case 'k':
		    output = 'K';
		    break;
	    case 'l':
		    output = 'L';
		    break;
	    case 'm':
		    output = 'M';
		    break;
	    case 'n':
		    output = 'N';
		    break;
	    case 'o':
		    output = 'O';
		    break;
	    case 'p':
		    output = 'P';
		    break;
	    case 'q':
		    output = 'Q';
		    break;
	    case 'r':
		    output = 'R';
		    break;
	    case 's':
		    output = 'S';
		    break;
	    case 't':
		    output = 'T';
		    break;
	    case 'u':
		    output = 'U';
		    break;
	    case 'v':
		    output = 'V';
		    break;
	    case 'w':
		    output = 'W';
		    break;
	    case 'x':
		    output = 'X';
		    break;
	    case 'y':
		    output = 'Y';
		    break;
	    case 'z':
		    output = 'Z';
		    break;
    }

    return output;
}
