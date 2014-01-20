#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"

int main(){
	Node*header;
	Node*blacklist;
	char input[80]="vanban.txt";
	char forbidden[80]="stopw.txt";
	blacklist=newNode();
	header=newNode();
	int i;
	printf("--------------------------------------------------------------------------------\n");
	printf("INPUT FILE: %s.\n",input);
	printf("--------------------------------------------------------------------------------\n");
	readFromFile(header,"vanban.txt");
	printf("--------------------------------------------------------------------------------\n");
	printf("FORBIDDEN FILE: %s.\n",forbidden);
	printf("--------------------------------------------------------------------------------\n");
	readFromFile(blacklist,"stopw.txt");
	deleteWordForbidden(header,blacklist);
	printf("--------------------------------------------------------------------------------\n");
	printf("RESULT:\n");
	printf("--------------------------------------------------------------------------------\n");
	printNode(header);
	
printf("--------------------------------------------------------------------------------\n");
	
}	