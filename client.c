#include "arp.h" //including header file




//execution of program starts from main function
int main()
{
    	//calling the function and checking if the login is successful or not
    
    	//if the login is unsuccessful   
    	if(adminLogin() == 0)
        {
        	printf("Successfully Logout\n\n");
   	} 
    	
    	//if the login is successful
    	else
    	{
		//structure to pass address of the target pc
		struct sockaddr_in sin = {0};

		//structure to use for ARP request
		struct arpreq myarp = {{0}};

		//ptr to store the IP address
		unsigned char *ptr;

		//variable to store incoming socket
		int sd;

		//The address family for the transport address which is set 
		//to AF_INET (IPv4 connection)
		sin.sin_family = AF_INET;
		
		//variable to store IP address
		char target_ip[20];

    	//Label
    	IP:
    		//Taking IP Address as input from the user
        	printf("Enter IP Address: ");
        	scanf("%s", target_ip);
	
		//Checking the entered IP address with the previous and 
		//incoming IP Addresses over the network
	       	if(inet_aton(target_ip, &sin.sin_addr) == 0)
        	{
		    	getchar();
		    	printf("IP address entered '%s' is not valid\n", target_ip);
		    	
		    	printf("\n\n");
		    
		    	printf("Please press enter key to continue...");
		    	getchar();
		    
		    	system("clear");
		    
		    	//Redirecting to the main menu
		    	
		    	if(intoAcc())
		        {
		        	goto IP;
			}
		   	else
            		{
                		printf("\t\tSuccessfully Logout!\n");
                		return 0;
            		}
        	}

		//it copies the address of our local machine into myarp's 
		//arp table
		memcpy(&myarp.arp_pa, &sin, sizeof(myarp.arp_pa));


		//it creates a socket that listens for incoming connections 
		//from other machines on the network
		sd = socket(AF_INET, SOCK_DGRAM, 0);
		if(sd == -1)
		{
			printf("Socket creation failed...\n");
			exit(0);
		}
		
		if(ioctl(sd,SIOCGARP,&myarp) == 1)
		{
			printf("No entry in ATP cache for '%s'\n",target_ip);
			exit(0);
		}
		
		//storing the address of the receiver if it was connected 
		//before to the client
		ptr = &myarp.arp_pa.sa_data[0];

		//returning MAC address from IP address:
		getchar();
		printf("\nMAC Address for '%s' : ", target_ip);
	
		
		unsigned char macStr[20];
        	snprintf(macStr, sizeof(macStr),"%02x:%02x:%02x:%02x:%02x:%02x",*ptr, *(ptr + 1), *(ptr + 2), *(ptr + 3), *(ptr + 4), *(ptr + 5));
 
       
        	//printing the mac address on the output screen 
        	printf("%02x:%02x:%x:%x:%x:%x\n", *ptr, *(ptr + 1), *(ptr + 2), *(ptr + 3), *(ptr + 4), *(ptr + 5));
 
        
        	//calling the function to check the validity of MAC Address
        	isValidMacAddress(macStr);

		printf("\n\n");
		printf("Please press enter key to continue...");
		getchar();
		
		//Redirecting to main menu after getting MAC address

		if(intoAcc())
		{
			goto IP;
		}
		else
		{
		    	printf("\t\tSuccessfully Logout!\n");
            		return 0;
        	}
    	}
    	return 0;
}
//program execution ends
