// including user-defined header file:
#include "login.h"

/*
return type = int
parameter passed = none
This function will enable to login as an admin
*/

int signUp()
{
    struct user *user_pointer;
	FILE *file_pointer;
	user_pointer = (struct user *)malloc(sizeof(struct user)); // initializing memory to structure pointer u1:
	system("clear");

	printf("\n");

	printf("\n				  SIGN UP	           		\n\n");

	printf("-------------------------------------------------------------------------------\n\n\n");
	if ((file_pointer = fopen("user.txt", "a+")) == NULL) // opening the text file in appending mode:
	{
		if ((file_pointer = fopen("user.txt", "w+")) == NULL) // opening  the ext file in write mode:
		{
			printf("Could not open file\n");
			exit(EXIT_FAILURE);
		} // end_of_if
	}// end_of_if

	printf("\t\t\tEnter your Username: ");

	scanf("%9s", user_pointer->username); // entering the username

	if (!check_details(user_pointer->username)) // checking if the username already exists:
	{
		printf("\n\t\t\tUsername already exists\n");
		strcpy(user_pointer->username, "null");	// if the username already exists copying nothing into username :
		printf("\n\t\t\tEnter Username again: "); // asking again for username:
		scanf("%9s", user_pointer->username);// re-enter username:
	}// end_of_if

	printf("\n\t\t\tEnter your Password: "); // entering password

	scanf("%9s", user_pointer->password);

	getchar();

	printf("\n\n\n\t\t\tYou have successfully registered.\n"); //Account successfully created

	printf("\n\n\n\tPress enter key to continue.....\n");

	getchar();

	fwrite(user_pointer, sizeof(struct user), 1, file_pointer); // writing the user details in the file:

	fclose(file_pointer); // closing the file:

	free(user_pointer); // freeing the  memory of u:

	// login(); // calling the login function:

	return FALSE;
} // end_signup_function

int login()
{

	char log_user[SIZE], log_pass[SIZE]; // initialize character variable:
	int flag; //FLag variable to store the returning value and check for TRUE and FALSE

	system("clear");

	printf("\n");

	printf("\n				     ADMIN LOGIN	           		\n\n");

	printf("-------------------------------------------------------------------------------\n\n\n");

	printf("\n\t\t\tEnter your Username: ");

	scanf("%s", log_user);

	printf("\n\t\t\tEnter your Password: ");

	scanf("%s", log_pass);

	// call the srch() that if user already signup than find username and password:
	flag = search_details(log_user,log_pass);
	// If can't find the username and password for user than shows invalid credentials:
	if (flag)
	{
		printf("\n\t\t\tWrong Credentials....\n");
	} // end_of_if
	else
	{
		printf("\n\t\t\tlogged in\n\n");
		sleep(SECONDS);
		return intoAcc(); // redirected to main account:

	} // end_of_else

	return FALSE;
} // end_of_login_function:

int check_details(char user_name[SIZE])
{	
	int flag=FALSE;
	struct user *user_pointer = (struct user *)malloc(sizeof(struct user)); // create a structure for user:

	FILE *file_pointer = fopen("user.txt", "rb"); // open file in read mode:

	fseek(file_pointer, 0, SEEK_SET);

	while (fread(user_pointer, sizeof(struct user), 1, file_pointer))
	{
		if (strcmp(user_pointer->username, user_name) == 0)
		{
			flag=TRUE;
		} // end_of_if
	}// end_of_while
	return flag;
} // end_of_check_function

// Find user through the provided username and password:
int search_details(char username[], char password[])
{

	FILE *file_pointer = fopen("user.txt", "rb");

	fseek(file_pointer, 0, SEEK_SET); /*
                                          ** moving the *in file pointer to start of the file
	                                  ***0 number of bytes to offset from position
				          ****SEEk_SET denotes starting of the file
			                  */
			                  
	// Allocates a new struct user and assigns it to the variable tmp.
	struct user *temp = (struct user *)malloc(sizeof(struct user));

	// read in a file and store the contents of that file into struct user:
	while (fread(temp, sizeof(struct user), 1, file_pointer))
	{
		/* checking if the username and password matches or not */
		if (!strcmp(username, temp->username) && !strcmp(password, temp->password))
		{
			{
				return FALSE;//return 1 if the username and password doesn't match
				break;
			}// end_of_if
		}// end_of_if
	}// end_of_while
	fclose(file_pointer); // close the file:

	return TRUE;

} // end_of_srch_function:

int userlogin()
{

	int choice; // declear variable for optimize switch case:

	while (TRUE)
	{
		system("clear");

		printf("\n\t\t\tWELCOME TO GROUP 2 PROJECT\n");

		printf("\n\t\t\t1. Sign Up \n\n\t\t\t2. Login \n\n\t\t\t3. Exit");

		printf("\n\nEnter your choice: ");

		scanf("%d", &choice); // enter user's choice:

		printf("\n");

		/* for taking the userinput from the user */

		switch (choice)
		{
		case 1: // Register new user
			signUp();
			break;
			
		case 2:
			return login(); //returning to TRUE(1) or FALSE(0) to the userlogin
			break;

		case 3:
			exit(EXIT_SUCCESS);
			break;

		default:
			printf("Invalid Choice..!");
			break;
		} // end_switch_case
	}	  // end_of_while

} // end_userlogin_function
