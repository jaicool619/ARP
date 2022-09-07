#include "login.h" //including header file

/*
return type = int
parameters = two char pointers
This function to update current password with the new password username 
*/
int updatePassword(char *curr_pass, char *new_pass)
{
    FILE *file_pointer = fopen("user.txt", "rb");
    int flag = FALSE;
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
        if (strcmp(temp->password, curr_pass) == 0)
        {
            strcpy(temp->password, new_pass);
            flag = TRUE;
        } // end_of_if
    }     // end_of_while

    fclose(file_pointer); // close the file:

    return flag; //returning TRUE or FALSE
}

/*
return type = int
parameters = two char pointers
This function to display menu driven options to the users for the MAC address ,change password etc.
*/
int intoAcc(char *curr_pass)
{
    int choice;      // variable to get choice from the user:
    system("clear"); // system() used for clear screen:

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
        return TRUE;

    // To change the admin password:
    case 2:

        char new_pass[SIZE]; // variable to store new password:

        // Used for change admin password:
        printf("Enter the new password\n");
        scanf("%s", new_pass);

        // function copies the string pointed by new_pass:
        if (updatePassword(curr_pass, new_pass))
        {
            getchar();
            printf("Password successfully updated\n");
            printf("Press enter key to continue..\n");
            getchar();
        }
        else
        {
            getchar();
            printf("Password not updated\n");
            printf("Press enter key to continue..\n");
            getchar();
        }

        intoAcc(new_pass); // redirect to the admin panel:
        break;
        // To exit from the program:
    case 3:
        return FALSE;
    } // end_switch_case:
    return FALSE;
} // end_intoAcc_function:
