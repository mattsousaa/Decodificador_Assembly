#include <stdio.h>
#include <string.h>
#include "decoder.h"
#include "decoder_regs.h"
#include "decoder_cond.h"

void instruction_decoder(int instruction, int opcode, int num){
	instruction = num >> 12;
	int reg = 0, immed = 0;
	switch(instruction){
		case 0x0:
		if(!opcode){
			printf("LSL");
			name_reg(num, TYPE_1);
		}	
		else{
			printf("LSR");
			name_reg(num, TYPE_1);
		}
		break;
				
		case 0x1:
			if(opcode == 0){
				printf("ASR");
				name_reg(num, TYPE_1);
			}
			else if(opcode == 4){
				printf("ADD");
				name_reg(num, TYPE_2);
			}
			else if(opcode == 5){
				printf("SUB");
				name_reg(num, TYPE_2);
			}	
			else if(opcode == 6){
				printf("ADD");	
				name_reg(num, TYPE_3);
			}
			else if(opcode == 7){
				printf("SUB");
				name_reg(num, TYPE_3);
			}
			break;

		case 0x2:
			if(opcode == 0){
				printf("MOV");
				name_reg(num, TYPE_4);
			}	
			else{
				printf("CMP");
				name_reg(num, TYPE_4);
			}	
		break;

		case 0x3:
			if(opcode == 0){
				printf("ADD");
				name_reg(num, TYPE_4);
			}	
			else{
				printf("SUB");
				name_reg(num, TYPE_4);
			}	
		break;

		case 0x4:
			switch(opcode){
				case 0x0:
					printf("AND");
					name_reg(num, TYPE_5);
				break;
				case 0x1:
					printf("EOR");
					name_reg(num, TYPE_5);
				break;
				case 0x2:
					printf("LSL");
					name_reg(num, TYPE_5);
				break;
				case 0x3:
					printf("LSR");
					name_reg(num, TYPE_5);
				break;
				case 0x4:
					printf("ASR");
					name_reg(num, TYPE_5);
				break;
				case 0x5:
					printf("ADC");
					name_reg(num, TYPE_5);
				break;
				case 0x6:
					printf("SBC");
					name_reg(num, TYPE_5);
				break;
				case 0x7:
					printf("ROR");
					name_reg(num, TYPE_5);
				break;
				case 0x8:
					printf("TST");
					name_reg(num, TYPE_5);
				break;
				case 0x9:
					printf("NEG");
					name_reg(num, TYPE_5);
				break;
				case 0xA:
					printf("CMP");
					name_reg(num, TYPE_5);
				break;
				case 0xB:
					printf("CMN");
					name_reg(num, TYPE_5);
				break;
				case 0xC:
					printf("ORR");
					name_reg(num, TYPE_5);
				break;
				case 0xD:
					printf("MUL");
					name_reg(num, TYPE_5);
				break;
				case 0xE:
					printf("BIC");
					name_reg(num, TYPE_5);
				break;
				case 0xF:
					printf("MVN");
					name_reg(num, TYPE_5);
				break;
				case 0x11:
					printf("ADD");
					name_reg(num, TYPE_5);
				break;
				case 0x12:
					printf("ADD");
					name_reg(num, TYPE_5);
				break;
				case 0x13:
					printf("ADD");
					name_reg(num, TYPE_5);
				break;
				case 0x19:
					printf("MOV");
					name_reg(num, TYPE_5);
				break;
				case 0x1A:
					printf("MOV");
					name_reg(num, TYPE_5);
				break;
				case 0x1B:
					printf("MOV");
					name_reg(num, TYPE_5);
				break;
				case 0x18:
					printf("CPY");
					name_reg(num, TYPE_5);
				break;
				case 0x15:
					printf("CMP");
					name_reg(num, TYPE_5);
				break;
				case 0x16:
					printf("CMP");
					name_reg(num, TYPE_5);
				break;
				case 0x17:
					printf("CMP");
					name_reg(num, TYPE_5);
				break;
				case 0x1C:
					printf("BX");
				break;
				case 0x1E:
					printf("BLX");
				break;
				case 0xFF:
					printf("LDR");
					name_reg(num, TYPE_4_1);
				break;
			}
		break;

		case 0x5:
			switch(opcode){
				case 0x0:
					printf("STR");
				break;
				case 0x1:
					printf("STRH") ;
				break;
				case 0x2:
					printf("STRB") ;
				break;
				case 0x3:
					printf("LDRSB") ;
				break;
				case 0x4:
					printf("LDR") ;
				break;
				case 0x5:
					printf("LDRH") ;
				break;
				case 0x6:
					printf("LDRB") ;
				break;
				case 0x7:
					printf("LDRSH") ;
				break;
				name_reg(num, TYPE_2);
			}
		break;

		case 0x6:
			if(!opcode)
				printf("STR");
			else
				printf("LDR");
			name_reg(num, TYPE_1_1); 
		break;

		case 0x7:
			if(!opcode)
				printf("STRB");
			else
				printf("LDRB");
			name_reg(num, TYPE_1_1);
		break;

		case 0x8:
			if(!opcode)
				printf("STRH") ;
			else
				printf("LDRH");
			name_reg(num, TYPE_1_1); 
		break;

		case 0x9:
			if(!opcode)
				printf("STR") ;
			else
				printf("LDR") ;
			name_reg(num, TYPE_4_2);
		break;

		case 0xA:
			printf("ADD") ;
			if(!opcode)
				name_reg(num, TYPE_4_1);	
			else
				name_reg(num, TYPE_4_2);

		break;
		
		case 0xB:
			switch(opcode){
				case 0x0:
					printf("ADD sp,");
					immed = num & 0x7F;
					printf(" #%d\n", immed);
				break;
				
				case 0x1:
					printf("SUB sp,");
					immed = num & 0x7F;
					printf(" #%d\n", immed);
				break;

				case 0x8:
					printf("SXTH");
					name_reg(num, TYPE_5);
				break;
				
				case 0x9:
					printf("SXTB");
					name_reg(num, TYPE_5);
				break;

				case 0xA:
					printf("UXTH");
					name_reg(num, TYPE_5);
				break;

				case 0xB:
					printf("UXTB");
					name_reg(num, TYPE_5);
				break;

				case 0x28:
					printf("REV");
					name_reg(num, TYPE_5);
				break;
				
				case 0x29:
					printf("REV16");
					name_reg(num, TYPE_5);
				break;
		
				case 0x2B:
					printf("REVSH");
					name_reg(num, TYPE_5);
				break;
			
				case 0x2:
					printf("PUSH");
					name_reg(num, TYPE_6);
				break;
				
				case 0x6:
					printf("POP");
					name_reg(num, TYPE_6_1);
				break;

				case 0x14:
					printf("SETEND LE");
				break;
			
				case 0x15:
					printf("SETEND BE");
				break;

				case 0xC:
					printf("CPSIE");
				break;

				case 0xE:
					printf("CPSID");					
				break;

				case 0xF:
					printf("BKPT");
					name_reg(num, TYPE_7);
				break;	

				default:
					printf("Instrução Inválida!\n");
				break;
			}
		break;

		case 0xC:
			if(!opcode)
				printf("STMIA");
			else
				printf("LDMIA");
			name_reg(num, TYPE_6);
		break;

		case 0xD:
			if(opcode == 0xF){
				printf("SWI");
			}else{
				printf("B");
				printf("%s", decoder_cond(num));
			}
			name_reg(num, TYPE_7);
		break;

		case 0xE:
			if(!opcode)
				printf("B");
			else
				printf("BLX");
			name_reg(num, TYPE_8);
		break;

		case 0xF:
			printf("BL");
			name_reg(num, TYPE_8);
		break;

		default:
			printf("Instrução Inválida!\n");
		break;
	}
}

int opcode(int instruction, int num){
	int opcode = 0;
	instruction = num >> 12;

	switch(instruction){
		case 0x0:
			opcode = (num>>11) & 0b1;
		break;

		case 0x1:
			if(((num>>11) & 0b1) == 0)
				opcode = 0;
			else if(((num>>11) & 0b1) && ((num>>10) & 0b1))
				opcode = ((num>>9) & 0b111);
			else
				opcode = ((num>>9) & 0b111);
		break;

		case 0x2:
				opcode = (num>>11) & 0b1;
		break;

		case 0x3:
				opcode = (num>>11) & 0b1;
		break;
				
		case 0x4:
				if(!((num>>11)&0b1)){
					if(((num>>8) & 0b111) == 0b111)
						opcode = ((num>>7) & 0b1111) * 2;  //para evitar o conflito com o outro opcode
					else
						opcode = (num>>6) & 0b11111;
				}
				else
					opcode = 0b11111111;
		break;

		case 0x5:
				opcode = (num>>9) & 0b111;
		break;
		
		case 0x6 ... 0xA:
			opcode = (num>>11) & 0b1;
		break;
		
		case 0xB:
			if(((num>>9) & 0b11) == 0b10)
				opcode = (num>>9 & 0b111);

			if((num>>8 & 0b1111) == 0)
				opcode = (num>>7 & 0b1);

			if((num>>8 & 0b11) == 0b10)
				opcode = (num>>6 & 0b111111);

			if((num>>9 & 0b11) == 0b11)
				opcode = (num>>3 & 0b1111) * 2;
			
			if((num>>9 & 0b111) == 0b111)
				opcode = 0b1111;
		break;

		case 0xC:
			opcode = ((num>>11) & 0b1);
		break;

		case 0xD:
			opcode = ((num>>8) & 0b1111);
		break;

		case 0xE:
			opcode = (num>>11) & 0b1;
		break;

		case 0xF:
			opcode = (num>>11) & 0b1;
		break;

		default:
			opcode = 0;
		break;					
	}

	return opcode;
}
