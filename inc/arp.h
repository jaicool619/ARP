#ifndef _ARP_H_
#define _ARP_H_

#include "login.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>       //Header file for strings:
#include <unistd.h>       //Header file which defines miscellaneous symbolic constants and types,and declares miscellaneous functions:
#include <math.h>         //Header file used for arithmatic function:
#include <sys/types.h>    //Header file which defines the data types and structure
#include <sys/socket.h>   //Header file which contains a datatype declaration of socket
#include <net/if_arp.h>
#include <errno.h>
#include <sys/ioctl.h>    //Header file which it contains definitions related to display window like TTY window,socket controls,tcp/ip (network)etc.                         
#include <complex.h>      //Header file which Expands to a constant expression of type const float _Complex:
#include <arpa/inet.h>    //Header file which makes available the in_addr structure:
#include <netinet/in.h>   //Header file used for network programming:
#include <net/ethernet.h> //Header file which enables network connection (local and Internet):
#include <ctype.h>        //Header file which declares several functions that are useful for testing and mapping characters:



// macro definition:
#define TRUE 1
#define FALSE 0

int ip();
int userlogin();         // Function declaration of admin login function:
int intoAcc();            // Function declaration of intoAcc function:
int isValidMacAddress(char *); // Function declaration of isValidMacAddress function
#endif
