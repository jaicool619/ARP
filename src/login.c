// including user-defined header file
#include "login.h"


// assigning the pre-defined password to admin for login:
char pass[VAR] = PRE_PASS;
char user[VAR] = PRE_USER; 

/*
return type = int
parameter passed = none
This function will enable to login as an admin
*/

// Function to login as admin:
int adminLogin()
{
	// variable declaration
	int count_user = MIN_LIMIT; // initialising the variable with 0

	int count_pass = MAX_LIMIT; // initialising the variable with 5

	char username[SIZE]; // variable to store username of admin


	system("clear");

	printf("\n\t\t\t->> Hello Admin\n\t\t\t Enter your username: ");
	scanf("%[^\n]s", username); // take username from user:

	// The function is used to compare two strings:
	// If username entered incorrect:
	if (strcmp(username, user) != FALSE)
	{
		count_user++;

		// if username is entered incorrect for 10 times:
		if (count_user == 10)
		{
			getchar();

			printf("\n\n");
			printf("Too many wrong username . Please try again...");
			getchar();

			exit(EXIT_FAILURE);
		} // end_of_if

		printf("Wrong username!, please try again\n\n");

		getchar();

		adminLogin();
	} // end_of_if

	// if username entered is correct
	else
	{
		char user_Pass[VAR]; // variable to store user defined password

	do{
		printf("\n\t\t\t>> Type password: ");
		scanf("%s", user_Pass); // take password from user:

		/*if password entered is incorrect.
	  The strcmp() compares two strings character by character.
	  If the strings are equal, the function returns FALSE */
		if (strcmp(user_Pass, pass) != FALSE)
		{
			count_pass--;

			// if password is entered incorrect for 5 times
			if (count_pass == FALSE)
			{
				getchar();
				printf("\n\n");

				printf("Too many wrong password ....");
				getchar();

				exit(EXIT_SUCCESS);
			} // end_if:

			printf("\n\t\t\t->>> Wrong password .login attempt remaining %d", count_pass);

			printf("\n\n");
			getchar();
			
			
		}
		else
		    {   
		        sleep(SECONDS);
		        
		        break;
		    }
		    
		}while(TRUE);
		
		
							
	}	
	return intoAcc(); // redirect to the main account:
	
} // end_of_adminlogin_function:
