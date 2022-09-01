#include "arp.h" //including header file


//assigning the pre-defined password to admin for login
char pass[20] = pre_pass;



//Function to login as admin
int adminLogin()
{
    	int count_user = 0;

    	int count_pass = 5;

    	char username[10];		//variable to store username of admin


   label:

    	system("clear");

    	printf("\n\t\t\t->> Hello Admin\n\t\t\t Enter your username: ");
    	scanf("%[^\n]s", username);

	//The function is used to compare two strings:
	//If username entered incorrect:
 	if(strcmp(username, "admin") != 0)
    	{
        	count_user++;
		
		//if username is entered incorrect for 10 times
        	if(count_user == 10)
       	 	{
            		getchar();
            
            		printf("\n\n");
            		printf("Too many wrong username . Please try again...");
            		getchar();
            		
            		exit(0);
        	}

        	printf("Wrong username!, please try again\n\n");

       	 	getchar();

        	goto label;
    	}
    	
    	//if username entered is correct
    	else
    	{
       		char adPass[20]; //variable to store password of admin
    	
    	label2:
        	printf("\n\t\t\t>> Type password: ");
        	scanf("%s", adPass);

        	//if password entered is incorrect.
        	if(strcmp(adPass, pass) != 0)
        	{
            		count_pass--;
			
			//if password is entered incorrect for 5 times
            		if(count_pass == 0)
		    	{
		        	getchar();
		        	printf("\n\n");
		        
		        	printf("Too many wrong password ....");
		        	getchar();
		        
		        	exit(0);
		    	}

            		printf("\n\t\t\t->>> Wrong password .login attempt remaining %d", count_pass);

           	 	printf("\n\n");
            		getchar();

            		// count--;

            		goto label2;
        	}

        	else
        	{
        		//passing the value to the delay function
            		for(int i = 0; i <= 6; i++)
            		{
                		fordelay(100000000);
            		}

            		return intoAcc(); 		//redirect to the main account:
        	}
    	}
}
