// including user-defined header file:
#include "arp.h"
#include <errno.h>
int ip()
{
	// structure to store address in variable addr:
	struct sockaddr_in addr;

	// structure to use for ARP request with no data:
	struct arpreq arpreq;

	// mac_addr to store the mac address:
	unsigned char *mac_addr;

	// The address family for the transport address which is set to AF_INET (providing IPv4 internet protocol):
	addr.sin_family = AF_INET;

	// variable to store IP address:
	char ip_addr[NUM];

// Label for IP address:
IP:

	// Taking IP Address as input from the user:
	printf("Enter IP Address: ");
	scanf("%s", ip_addr);

	/*
	Checking the entered IP address with the previous and incoming IP Addresses over the network
	Converting IP address to 32-bit network byte ordered binary value.
	inet_aton() returns TRUE if the address is a valid one, and it returns FALSE if the address is invalid.
	*/
	if (inet_aton(ip_addr, &addr.sin_addr) == FALSE)
	{
		getchar();

		/*this perror() displays the description of the error that corresponds
		  to an error code stored in the system variable errno.
		  errno is a system variable which holds the error code that describes the error condition.
		*/
		perror("IP address entered is not valid\n");

		printf("\n\n");

		printf("Please press enter key to continue...");
		getchar();

		// system() returns the exit code of the process start:
		system("clear");

		// Redirecting to the main account
		if (intoAcc())
		{
			goto IP;
		} // end_of_if

		else
		{
			perror("\t\tSuccessfully Logout..!\n");
			return 0;
		} // end_of_else

	} // end_of_if

	/*it copies the address of our local machine into myarp's arp table
	  The function memcpy() is used to copy a memory block from one location to another:
	*/
	memcpy(&arpreq.arp_pa, &addr, sizeof(arpreq.arp_pa));

	/*
	 *  Create UDP socket: Creating socket that listens for incoming connections from other machines on the network
	 *  AF_INET --> Internet domain.	(Protocol Family: IPv4)
	 *  SOCK_DGRAM --> Supports datagrams (connectionless0
	 *  IPPROTO_UDP --> 0 and IPPROTO_UDP for UDP Sockets
	 */

	// variable to store incoming socket (socket descriptor):
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	if (sockfd == -1)
	{
		perror("Socket creation failed...\n");
		// The exit () function is used to break out of a loop:
		exit(EXIT_FAILURE);
	} // end_of_if

	/*
	Adding and Modifying in ARP table and check for ATP cache through ioctl function.
	SIOCGARP: Get ARP table entry. The caller specifies the Internet address, and the corresponding MAC address is returned.
	*/
	if (ioctl(sockfd, SIOCGARP, &arpreq) == TRUE)
	{
		perror("No entry in ATP cache for :");
		printf("%s'\n", ip_addr);
		// The exit () function is used to break out of a loop:
		exit(EXIT_FAILURE);
	} // end_of_if

	// storing the address of the receiver if it was connected before to the client:
	mac_addr = &arpreq.arp_pa.sa_data[0];

	// Returning MAC address from IP address:
	getchar();
	printf("\nMAC Address for '%s' : ", ip_addr);

	// variable to store MAC address:
	unsigned char macStr[SIZE];

		snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
         *mac_addr, *(mac_addr + 1), *(mac_addr + 2), *(mac_addr + 3), *(mac_addr + 4), *(mac_addr + 5));
       
        //printing the mac address on the output screen: 
        printf("%02x:%02x:%x:%x:%x:%x\n", *mac_addr, *(mac_addr + 1), *(mac_addr + 2), *(mac_addr + 3), *(mac_addr + 4), *(mac_addr + 5));
 
        
        //Calling the function to check the validity of MAC Address:
       	isValidMacAddress(macStr);


	printf("\n\n");
	printf("Please press enter key to continue...");
	getchar();
		

	//Redirecting to main menu after getting MAC address
	if(intoAcc())
	{
		goto IP;
	}//end_of_if

	else
	{
		perror("\t\tSuccessfully Logout..!\n");
		exit(EXIT_SUCCESS);
        }//end_of_else
}
