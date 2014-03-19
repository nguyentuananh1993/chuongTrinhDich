#include <stdio.h>

int main(){
	int i;
	for(i=0;i<16*16-1;i++){
		if(i%10==0) printf("\n");
		printf("%d = %c ",i,i);
	}
}