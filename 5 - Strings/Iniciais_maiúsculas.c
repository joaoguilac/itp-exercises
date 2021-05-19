#include <stdio.h>
#include<ctype.h>
#include <string.h>

int main(){
	int i;
	char frase[61];
	
	fgets(frase, 61, stdin);
	
	for (i=0; i<strlen(frase); i++){
		if (i == 0){
			frase[i] = toupper(frase[i]); 
		}
		else if (frase[i-1] == ' '){
			frase[i] = toupper(frase[i]); 
		}
		else {
			frase[i] = tolower(frase[i]);
		}
	}
	
	printf("%s", frase);
	
	return 0;
}