/*
Written by: Adam Stillman
            11/25/14
            CSC 139
            program  assignment 5
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

#define SERVER 1L
tpyedef struct{
	long msg_to;
	long msg_fm;
	char buffer[BUFSIZ];
} MESSAGE;

int mid;
key_t key;
struct msqid_ds buff;
MESSAGE msg;

FILE *fp0, *fp1, *fp2;
pthread_t server_t, client1_t, client2_t;


void *server();
void *client1();
void *client2();

void main(int argc, char *argv[]){

	//check if empty and if two entries
	if( (argv[1]== NULL) || argc <4 || argc >4){printf("Correct usage: prog5 infile infile infile\n"); return;  }

	//create threads in the if statement and if it fails let the user know
	//it it succeeds
	int r0, r1, r2;
	//create threads catch errors
	if( (r0= pthread_create(&server, NULL, server_t, (void*) 0)) ) printf("thread creation failed: 1\n"); 
	if( (r1= pthread_create(&client1, NULL, client1_t, (void*) 1)) ) printf("thread creation failed: 2\n"); 
	if( (r2= pthread_create(&client2, NULL, client2_t, (void*) 1)) ) printf("thread creation failed: 3\n"); 

	//open file streams to read from fp0 1 and
	fp0 = fopen(argv[1],"rb");
	fp1 = fopen(argv[2],"rb");
	fp2 = fopen(argv[3],"rb");

	

	////wait to close the threads
	pthread_join(server, NULL);
	pthread_join(client1, NULL);
	pthread_join(client2, NULL);
	////close the files
	fclose(fp0);
	fclose(fp1);
	fclose(fp2);

	

}

void *server(){}
void *client1(){
	char tbuff[SLOTSIZE];
	strncpy(tbuff, "tmpbuff", sizeof(tbuff));
	
	while(tbuff != NULL){
		strncpy(tbuff, buffer[out], sizeof(tbuff));
		fputs(tbuff, fp1);
		if ((feof(fp0) !=0) && (count==0)) pthread_exit(NULL);
	}
pthread_exit(NULL);


	

}
void *client2(){

	
}
