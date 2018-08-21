#include <stdio.h>
#include <stdlib.h>
#include "decoder.h"

void read_file(){

char *hexa;
int num, instruction = 0, opcode_num, option, a = 0, contador = 0, i = 0;
int valid = 0;

hexa = (char *)calloc(10000000, sizeof(char));

	FILE *arquivo;

	arquivo = fopen("dados.txt","r");

	if(arquivo == NULL){
		printf("Arquivo não encontrado!\n");
		exit(1);
	}

	while(fgets(hexa, 10000000, arquivo) != NULL){
    	/* writing content to stdout */
    	//puts(hexa);

		sscanf(hexa, "%x", &num);

	/*
		while(hexa[i] != '\n'){
			for(i = 0; i < 10000000; i++){
				if((hexa[i] == '0' || hexa[i] == '1' || hexa[i] == '2' || hexa[i] == '3' || hexa[i] == '4' || hexa[i] == '5' || 
					hexa[i] == '6' || hexa[i] == '7' || hexa[i] == '8' || hexa[i] == '9' || hexa[i] == 'a' || hexa[i] == 'b' || 
					hexa[i] == 'c' || hexa[i] == 'd' || hexa[i] == 'e' || hexa[i] == 'f'|| hexa[i] == 'A' || hexa[i] == 'B' || 
					hexa[i] == 'C'|| hexa[i] == 'D'|| hexa[i] == 'E'|| hexa[i] == 'F')){

					valid++;
				}
			}
		}
	
			if(valid != 4){
				printf("Instrução inválida.\n");
			}
	*/
    		while(hexa[a] != '\n'){
				contador++;
				a++;
			}

			if(contador > 4 || contador < 4){
				printf("Instrução inválida!\n");
				printf("\n");	
			}

				else{ 

   					printf("Value in hexa: %x\n", num);

	   				opcode_num = opcode(instruction, num);
	
					printf("Decoded instruction:\n");
					instruction_decoder(instruction, opcode_num, num);

					printf("\n");

				}

			contador = 0;
			a = 0;
	}

	free(hexa);

	fclose(arquivo);
}