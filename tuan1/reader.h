#include "linklist.h"
int findChar(char*word, char a){
	int i;
	int check=-1;
	for(i=0;i<strlen(word);i++)
		if(word[i]==a){
			check=i;
			break;
		}
	return check;
}

void deleteCharByLocation(char*word,int l){
	int i;
	for(i=l;i<strlen(word);i++)
		word[i]=word[i+1];
}

void spellByWord(char*word){
	int i;
	for(i=0;i<strlen(word);i++){
		if(word[i]>=65 && word[i]<=90)
			word[i]=word[i]+32;
	}
	for(i=0;i<strlen(word);i++){
		if(word[i]<65 || (word[i]>90 && word[i]<97) || word[i]>122)
			word[i]=' ';
	}
	while(findChar(word,' ')!=-1)
		deleteCharByLocation(word,findChar(word,' '));
	
	while(word[0]==' '){
		for(i=0;i<strlen(word);i++)
			word[i]=word[i+1];
	}
	while(word[strlen(word)-1]==' ') 
		word[strlen(word)-1]='\0';
}

int findString(char*des,char*sour){
	int check =-1,i,j;
	if(strlen(des)>strlen(sour)) check=-1;
	else for(i=0;i<strlen(sour)-strlen(des);i++){
		for(j=0;j<strlen(des);j++)
			if(sour[i+j]!=des[j]){
				check=0;
				break;
			}
		if(j==(strlen(des)-1)){
			check=i;
			break;
		}
	}
	return check;
}

int isAlphabet(char c){
	if(c<65 || (c>90 && c<77) || c>122)
		return 1;
	else return 0;
}
int isCap(char c){
	if(c>=65 && (c<=90))
		return 1;
	else return 0;
}
int isLower(char c){
	if(c>=97 && (c<=122))
		return 1;
	else return 0;
}
int checkStringCap(char*c){
	int i;
	int check=0;
	for (i=0;i<strlen(c);i++)
		if(isCap(c[i])){
			check=1;
			break;
		}
	return check;
}
void spellByLine(char*line){
	int i,j;
	while(line[0]==' ')//xoa ki tu trong dau
		for(i=0;i<strlen(line);i++)
			line[i]=line[i+1];

	for(i=0;i<strlen(line);i++){// chuyen doi tu Cap sang lower
		if(line[i]>=65 && line[i]<=90)
			if(i==0 || line[i-2]=='.')
				line[i]=line[i]+32;
	}
	for(i=0;i<strlen(line);i++){//xoa ki tu khong thuoc bang chu cai
		if(line[i]<65 || (line[i]>90 && line[i]<97) || line[i]>122)
			line[i]=' ';
	}
	while(line[0]==' '){//xoa ki tu trong dau
		for(i=0;i<strlen(line);i++)
			line[i]=line[i+1];
	}
	while(line[strlen(line)-1]==' ') //xoa ki tu trong cuoi cung
		line[strlen(line)-1]='\0';
	for(i=0;i<strlen(line);i++){
		while(line[i]==' ' && line[i+1]==' ')
			for(j=i;j<strlen(line);j++)
				line[j]=line[j+1];
	}
}
void readByWord(Node*header,char*fileName){
	FILE*f;
	char tmp[80];
	Node*node;
	f=fopen(fileName,"r+");
	while(!feof(f)){
		fscanf(f,"%s",tmp);
		spellByWord(tmp);
		printf("%s ",tmp);
		if(searchNodeContent(header,tmp)!=NULL){
			node=searchNodeContent(header,tmp);
			node->count++;
		}else
		addNodeSort(header,newNodeContent(tmp));
	}
	fclose(f);
}
char*cutString(char*text){
	int i,n;
	char*tmp;
	if(findChar(text,' ')==-1){
		tmp=(char*)malloc(sizeof(char)*(strlen(text)+1));
		strcpy(tmp,text);
		text[0]='\0';
	}else{
		n=findChar(text,' ');
		tmp=(char*)malloc(sizeof(char)*(n+1));
		for(i=0;i<n;i++) tmp[i]=text[i];
			tmp[n]='\0';
		for(i=0;text[i]!='\0';i++){
			text[i]=text[i+n+1];
		}
		text[i+1]='\0';
	}
	return tmp;
}
void readByLine(Node*header,char*fileName){
	FILE*f;
	char tmp[161];
	f=fopen(fileName,"r+");
	while(!feof(f)){
		fgets(tmp,160,f);
		spellByLine(tmp);
		if(!feof(f)){
			while(strlen(tmp)!=0)
				printf("%s ",cutString(tmp));
		}
	}
}

void readFromFile(Node*header,char*fileName){
	FILE*f;
	char*tmp;
	Node*temp;
	Node*search;
	Node*search1;
	char ab[10];
	int i=1;
	char str[161];
	f=fopen(fileName,"r+");
	while(!feof(f)){
		fgets(str,160,f);
		printf("%s",str);
		spellByLine(str);
		while(strlen(str)!=0){
			tmp=cutString(str);
			if(checkStringCap(tmp))
				continue;
			temp=newNodeContent(tmp);
			search=searchNode(header,temp);
			if(search==NULL){
				//printf("%s",temp->text);
				addNodeSort(header,temp);
				addCol(temp,i);
			}else{
				addCol(search,i);
			}
		}
		i++;
	}
}

void deleteWordForbidden(Node*header,Node*blacklist){
	Node*tmp;
	while(blacklist->next!=NULL && header->next!=NULL){
		if(compare(blacklist->next,header->next)==0){
			deleteAfter(header);
			blacklist=blacklist->next;
		}
		else{
			header=header->next;
		}
	}
}
