// including user-defined header file
#include "arp.h"

// execution of program starts from main function

/*main method
 return type = integer
*/
int main()
{
    // calling the function and checking if the login is successful or not

    // if the login is unsuccessful
    if (userlogin() == FALSE)
    {
        perror("Successfully Logout\n\n");
        // exit(EXIT_SUCCESS);
    } // end_of_if

    // if the login is successful:
    else
    {
        ip();
    } // end_of_else

    return 0;
}
// program execution ends
