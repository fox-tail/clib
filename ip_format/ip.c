#include <stdio.h>

int ip_to_int(char *s)
{
	if(!s){
		return -1;	
	}
	
	int a1 = -1, a2 = -1, a3 = -1, a4 = -1;
	sscanf(s, "%u.%u.%u.%u", &a1, &a2, &a3, &a4);
	printf("%u.%u.%u.%u\n", a1, a2, a3, a4);	
	if((a1 < 0)||(a2 < 0)||(a3 < 0)||(a4 < 0)){
		return -1;
	}
	int ip = (a4 << 24)|(a3 << 16)|(a2 << 8)|a1;
	 
	return ip;
}

int ip_to_str(int ip, char *s)
{
	if(ip < 0){
		return -1;
	}
	
	int a1 = ip & 0xff,
		a2 = (ip & 0xff00) >> 8,
		a3 = (ip & 0xff0000) >> 16, 
		a4 = (ip & 0xff000000) >> 24; 

	int len = sprintf(s, "%u.%u.%u.%u", a1, a2, a3, a4);
	if(len < 0){
		return -1;
	}

	return 0;
}



