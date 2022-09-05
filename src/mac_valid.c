// including user-defined header file
#include "arp.h"

// This function is used for validation of mac address:
// check whether the Mac Address is valid or not:

/*
return type = int
parameter passed = character pointer
This function will validate mac address
*/

int isValidMacAddress(char *mac)
{
	// variable declaration
	int i = 0, s = 0;
	int flag = 0;

	// while the mac address is generated by the system
	while (*mac)
	{
		// check whether the generated mac address is in the form of hexadecimal characters:
		// isxdigit() checks if the given input is numeric or not:
		if (isxdigit(*mac))
		{
			i++;
		} // end_of_if

		// check if the mac address contains : and - separators:
		else if (*mac == ':' || *mac == '-')
		{
			// check if the mac address contains : and - at the right position
			if (i == 0 || i / 2 - 1 != s)
			{
				s--;
				break;
			} // end_if

			++s;
			flag++;
		} // end_of_elseif

		// if the mac address is invalid, else part will execute
		else
		{
			s = -1;
			flag = 0;
			printf("The MAC Address is invalid");
			break;
		} // end_of_else

		++mac;
	} // end_while_loop
	if (flag == 5)
	{
		printf("The MAC Address is valid");
	} // end_if
	return FALSE;
} // end_isValidMacAddress_function:
