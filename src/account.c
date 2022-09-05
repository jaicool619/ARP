#include "arp.h" //including header file

int intoAcc()
{
	int choice;		 // variable to get choice from the user:
	system("clear"); // system() used for clear screen:

// Label for admin:
adm:

	// display admin panel:
	printf("\n\t\t\t********************************************\n");
	printf("\n\t\t\t|    ---     ~!! Admin Panel !!~     ---        |\n");
	printf("\n\n\t\t[1] Get MAC Address\n\t\t[2] Change Password\n\t\t[3] Exit\n\n\n\t\t Enter your choice:");

	scanf("%d", &choice); // Enter the user choice:

	// start_switch_cases:
	switch (choice)
	{
		// To get MAC Address from the IP Address:
	case 1:
		return 1;

	// To change the admin password:
	case 2:
		char pass[SIZE];
		char new_pass[SIZE]; // variable to store new password:

		// Used for change admin password:
		printf("Enter the new password\n");
		scanf("%s", new_pass);

		// function copies the string pointed by new_pass:
		strcpy(pass, new_pass);
		printf("Password successfully updated\n");

		goto adm; // redirect to the admin panel:

		// To exit from the program:
	case 3:
		return 0;
	} // end_switch_case:
	return 0;
} // end_intoAcc_function:
