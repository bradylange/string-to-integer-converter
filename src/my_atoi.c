#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Brady Lange
 * 3/12/18
 * File name: myatoi.c
 * This program is my own version of the C library function that converts a string to an integer 
 */
 
 // My atoi function that I have created 
 int myatoi(const char * str)
 {
	 int i = 0;
	 int count = 0;
	 int result = 0;
	 int length = strlen(str);
	 
	 if(length == 0)
		return 0;
	 
	 while(str[i] != '\0')
	 {
		 //This statement will check if there is any blank space characters I will need to attend to
		 if(str[0] == '\t' || str[0] == '\n' || str[0] == '\v' || str[0] == '\f' || str[0] == '\r' || str[0] == ' ' && i == 0)
		 {
			 for(i; i < length; i++)
			 {
				 if(str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
				 {
					 ++count;
					 if(count == length)
						return 0;
				 }
				 else 
				 {
					 i = 0;
					 break;
				 }
			 }	 
		 }
		 
		 //This calculates the numeric value of the string entered
		 result = result * 10 + str[i] - '0'; //Result times base 10 plus the string value - '0' (48)
		 i++;
	 }
	 
	 return result;
	
 } //End of myatoi function
 
 //Main function to test my atoi function
 int main(int argc, char * argv[])
 {
	 int i = 0;
	 
	 int length = strlen(argv[1]);
	 char string[length];
	 
	 while(argv[1][i] != '\0')
	 {
		string[i] = argv[1][i];
		i++;
	 }
	 
	 printf("The string '%s' was parsed to the integer %d\n", string, myatoi(string));
	 
	return 0;
	
 } //End of main function