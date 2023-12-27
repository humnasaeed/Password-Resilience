#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// Function to check presence of lowercase letter 
int hasLowercase(char pass[]){

    int i; 


    // Iterate through each char of the password until the null character
    for (i = 0; pass[i] != '\0'; i++){

        char letter = pass[i]; 

        // Checking if the characters are lowercase using Ascii values in a conditional statement 
        if (letter >= 97 && letter <= 122){

            // Returning 1 upon first appearence 
            return 1; 
        }
    }


    // Returning 0 if score is 0 as there is no occurance
    return 0; 
    
}

// Function to check presence uppercase letter 
int hasUppercase(char pass[]){
    
    int i; // initializing i. 


    // Iterating through each char of password to check occurance of uppercase letter 
    for (i = 0; pass[i] != '\0'; i++){
        char letter = pass[i]; 
        if (letter >= 65 && letter <= 90){ // using ascii values to identify 
            return 1; // Returning 1 and terminating function upon first occurance 
        }
    }

    // If no occurence of uppercase letter, returns 0. 
    return 0; 

}

// Checking for numerical digit 
int hasDigit(char pass[]){
    int i; 

    // Using for loop to iterate through each char of password 
    for (i = 0; pass[i] != '\0'; i++){
        char letter = pass[i]; 

        // Checking each char with digit ascii values 
        if (letter >= 48 && letter <= 57){
            return 1; // Returning one upon each occurance 
          
        }
    }

    //If no occurance, returns 0. 
    return 0; 
    
}

// Checking for special characters !@#$%^&*()
int hasSpecialChar(char pass[]){
    
    int i;

    // Iterating through each character of password 
    for (i = 0; pass[i] != '\0'; i++){
        char letter = pass[i]; 

        // Using conditionals with ascii values to check for certian special characters  
        if (letter == 33){ 
            return 1;  // returning one upon first occurance of special character 
        } else if (letter == 64){
            return 1; 
        } else if (letter <= 35 && letter >= 38){
            return 1;
        } else if (letter == 94){
            return 1;
        } else if (letter >= 40 && letter <= 42){
            return 1;
        }
    }  

    // If no ocurrances of uppercase letter, return 0. 
    return 0; 
}

// Function to evaluate total strength of password 
int evaluateStrength(char pass[]){

    // Initializing score as 0. 
    int score = 0; 

    // Incrementing score if the returned values of the four functions is 1. 
    // A returned 1 from the functions means there is an occurance. 
    if ((hasLowercase(pass)) == 1){
        score++;
    }

    if ((hasUppercase(pass)) == 1){
        score++; 
    }

    if ((hasDigit(pass)) == 1){
        score++; 
    }

    if ((hasSpecialChar(pass)) == 1){
        score++; 
    }

    // Also incrementing score by 1 if the length of password is 12+ characters. 
    int len = strlen(pass); 
    if (len >= 12){
        score++; 
    }

    // Returning the final score 
    return score; 
}

// Main function 
int main(){ 

    printf("\n");

    // Declaring and initializing variable to keep track of last user input 
     int stored_results = 0;

    // While loop to continously display the main menu 
    while(1){

        // Displaying main menu interface 
        printf("Password Resilience Analyzer\n");
        printf("1. Test a new password\n");
        printf("2. View strength of the last tested password\n");
        printf("3. Exit\n"); 
        printf("Enter your choice: "); 

        // Declaring char array and int variable to store user inputs 
        int input; 
        char str_input[500]; 
       
        // Using scanf() to take input as string to effectivley deal with incorrect inputs
        // User input of string when expecting int causes unexpected behaviours; hence taking string.
        scanf("%s", str_input); 

        // Using strcmp() functions to ensure user has entered 1,2, or 3. 
        if (strcmp("1", str_input) != 0 && strcmp("2", str_input) != 0 && strcmp("3", str_input) != 0){
            printf("\n"); 

            // Program will go to the next iteration to deal with incorrect inputs. 
            continue; 
        }
        
        // Converting string input to int using atoi(). 
        input = atoi(str_input); 
         
        // Condition to check if the user input is 3
        if (input == 3){

            // Displays a message 
            printf("Exiting...\n"); 

            // Terminates program 
            exit(0); 
        }

        // Initializing char array to store user input
        char buf[500]; 

        // check if user input is 1 
        if (input == 1){

            // Prompting user to enter password 
            printf("Enter the Password: ");

            // Stored password in a char array. 
            scanf("%s",buf); 
            
            // Using strlen() to determine length of password 
            int len = strlen(buf);  

            // Checking if length is less than 9 
            if (len < 8){

                // Prints error message 
                printf("Error: Password should be at least 8 characters long\n");
                printf("\n"); 

                // Goes to next iteration where user can re-enter the password 
                continue;
            } 

            // Calling evaluateStrength() function
            // Storing password strength score in output variable 

            int output = evaluateStrength(buf); // user input as parameter 
            
            // Using if-else statements to determine score categorization 

            // if 0-2 points, displays Weak. 
            if (output >= 0 && output <= 2){
                printf("Password Strength: Weak\n"); 

                // Assigns 1 to variable to store results 
                stored_results = 1; 

            // if 3-4 points, displays Moderate
            } else if (output >= 3 && output <= 4){
                printf("Password Strength: Moderate\n"); 
    
                // Assigns 2 to variable to store results 
                stored_results = 2; 

            // checks if score is 5 then displays Strong 
            } else if (output == 5){
                printf("Password Strength: Strong\n"); 

                // Assigns 3 to store results  
                stored_results = 3; 
            }
        }

        // Checking if user input is 2 
        if (input == 2){

            // Checking if stored result is 1,2,3
            // Displays strength category 
            if (stored_results == 1){
                printf("Last tested password strength: Weak\n"); 

            } else if (stored_results == 2){
                printf("Last tested password strength: Moderate\n"); 

            } else if (stored_results == 3) {
                printf("Last tested password strength: Strong\n"); 
            }

        }

        // Printing new line for user friendly interface 
        printf("\n"); 

    }

    return 0; 
}
