#include "arp.h" //including header file




//This function is used for validation of mac address:
//check whether the Mac Address is valid or not:

int isValidMacAddress(const char* mac)
{
	int i = 0, s = 0;  
	int flag = 0;
	
	while(*mac)
	{
		//check whether the generated mac address is in the form of 		
        	//hexadecimal characters
        	if(isxdigit(*mac)) 
        	{
        		i++;	
		}
	
		//check if the mac address contains : and - separators
        	else if(*mac == ':' || *mac == '-')
        	{
        		if(i==0 || i / 2 - 1 !=s)
        		{
        			s--;
        			break;
        		}
        		++s;
        		flag++;
        	}	
        	else
        	{
    			s = -1;
    			flag = 0;
    			printf("The MAC Address is invalid");
    			break;
    		}
    		++mac;
        }
        if(flag == 5)
        {
        	printf("The MAC Address is valid");
        }
        return 0;
}
