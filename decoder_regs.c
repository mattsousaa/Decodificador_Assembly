#include <stdio.h>
#include "decoder_regs.h"

void name_reg(int num, int TYPE){
	int reg, immed, register_list, flag = 0;
	switch(TYPE){
		case TYPE_1:
			//primeiro registrador
			reg = num & 0x7;
			printf(" %s,", decoder_reg(reg));		
			//segundo registrador
			reg = (num & 0x38) >> 3;
			printf(" %s,", decoder_reg(reg));
			//tamanho
			immed = (num>>6) & 0x1F;
			printf(" #%d\n", immed);
		break;

		case TYPE_1_1:
			//primeiro registrador
			reg = num & 0x7;
			printf(" %s,", decoder_reg(reg));		
			//segundo registrador
			reg = (num & 0x38) >> 3;
			printf(" [%s,", decoder_reg(reg));
			//tamanho
			immed = (num>>6) & 0x1F;
			printf(" #%d]\n", immed);
		break;
		
			case TYPE_2:
			//primeiro registrador
			reg = num & 0x7;
			printf(" %s,", decoder_reg(reg));		
			//segundo registrador
			reg = (num & 0x38) >> 3;
			printf(" %s,", decoder_reg(reg));
			//terceiro registrador
			reg = (num & 0x1C0) >> 6;
			printf(" %s", decoder_reg(reg));
		break;

		case TYPE_3:
			//segundo registrador
			reg = num & 0x7;
			printf(" %s,", decoder_reg(reg));		
			//segundo registrador
			reg = (num & 0x38) >> 3;
			printf(" %s,", decoder_reg(reg));
			//tamanho
			immed = (num>>6) & 0x7;
			printf(" #%d\n", immed);
		break;

		case TYPE_4:
			//registrador
			reg = (num>>8) & 0x7;
			printf(" %s,", decoder_reg(reg));
			//tamanho
			immed = num & 0xFF;
			printf(" #%d\n", immed);
		break;	

		case TYPE_4_1:
			//registrador
			reg = (num>>8) & 0x7;
			printf(" %s,", decoder_reg(reg));
			//tamanho
			immed = num & 0xFF;
			printf(" [pc, #%d]\n", immed);
		break;

		case TYPE_4_2:
			//registrador
			reg = (num>>8) & 0x7;
			printf(" %s,", decoder_reg(reg));
			//tamanho
			immed = num & 0xFF;
			printf(" [sp, #%d]\n", immed);
		break;	

		case TYPE_5:
			//primeiro registrador
			reg = num & 0x7;
			printf(" %s,", decoder_reg(reg));		
			//segundo registrador
			reg = (num & 0x38) & 0x3;
			printf(" %s", decoder_reg(reg));
		break;	

		case TYPE_6:
			//registrador
			reg = (num >> 8) & 0x7;
			printf(" %s!", decoder_reg(reg));

			//Register List
			register_list = num & 0xFF;
			printf(", {");
			if(register_list & 0x1){
				printf("r0");
				flag = 1;
			}
			if(register_list & 0x2){
				if(flag) printf(", ");
				printf("r1");
				flag = 1;
			}
			if(register_list & 0x4){
				if(flag) printf(", ");
				printf("r2");
				flag = 1;
			}
			if(register_list & 0x8){
				if(flag) printf(", ");
				printf("r3");
				flag = 1;
			}
			if(register_list & 0x10){
				if(flag) printf(", ");
				printf("r4");
				flag = 1;
			}
			if(register_list & 0x20){
				if(flag) printf(", ");
				printf("r5");
				flag = 1;
			} 
			if(register_list & 0x40){
				if(flag) printf(", ");
				printf("r6");
				flag = 1;
			}
			if(register_list & 0x80){
				if(flag) printf(", ");
				printf("r7");
				flag = 1;
			}
			printf("}\n");
		break;

		case TYPE_6_1:
			register_list = num & 0x1FF;
			printf(" {");
			if(register_list & 0x1){
				printf("r0");
				flag = 1;
			}
			if(register_list & 0x2){
				if(flag) printf(", ");
				printf("r1");
				flag = 1;
			}
			if(register_list & 0x4){
				if(flag) printf(", ");
				printf("r2");
				flag = 1;
			}
			if(register_list & 0x8){
				if(flag) printf(", ");
				printf("r3");
				flag = 1;
			}
			if(register_list & 0x10){
				if(flag) printf(", ");
				printf("r4");
				flag = 1;
			}
			if(register_list & 0x20){
				if(flag) printf(", ");
				printf("r5");
				flag = 1;
			} 
			if(register_list & 0x40){
				if(flag) printf(", ");
				printf("r6");
				flag = 1;
			}
			if(register_list & 0x80){
				if(flag) printf(", ");
				printf("r7");
				flag = 1;
			}
			if(register_list & 0x100){
				if(flag) printf(", ");
				printf("lr");
			}
			printf("}\n");
		break;

		case TYPE_6_2:
			register_list = num & 0x1FF;
			printf(" {");
			if(register_list & 0x1){
				printf("r0");
				flag = 1;
			}
			if(register_list & 0x2){
				if(flag) printf(", ");
				printf("r1");
				flag = 1;
			}
			if(register_list & 0x4){
				if(flag) printf(", ");
				printf("r2");
				flag = 1;
			}
			if(register_list & 0x8){
				if(flag) printf(", ");
				printf("r3");
				flag = 1;
			}
			if(register_list & 0x10){
				if(flag) printf(", ");
				printf("r4");
				flag = 1;
			}
			if(register_list & 0x20){
				if(flag) printf(", ");
				printf("r5");
				flag = 1;
			} 
			if(register_list & 0x40){
				if(flag) printf(", ");
				printf("r6");
				flag = 1;
			}
			if(register_list & 0x80){
				if(flag) printf(", ");
				printf("r7");
				flag = 1;
			}
			if(register_list & 0x100){
				if(flag) printf(", ");
				printf("pc");
			}
			printf("}\n");
		break;

		case TYPE_7:
			immed = num & 0xFF;
			printf(" #%d\n", immed);
		break;

		case TYPE_8:
			immed = num & 0x7FF;
			printf(" #%d\n", immed);
		break;
	}
}

char *decoder_reg(int reg){
	switch(reg){
		case R0:
			return "r0";
			break;
		case R1:
			return "r1";
			break;
		case R2:
			return "r2";
			break;
		case R3:
			return "r3";
			break;
		case R4:
			return "r4";
			break;		
		case R5:
			return "r5";
			break;
		case R6:
			return "r6";
			break;
		case R7:
			return "r7";
			break;
		case R8:
			return "r8";
			break;
		case R9:
			return "r9";
			break;
		case R10:
			return "r10";
			break;
		case R11:
			return "r11";
			break;
		case R12:
			return "r12";
			break;
		case R13:
			return "r13";
			break;
		case R14:
			return "r14";
			break;
		case R15:
			return "r15";
			break;													
	}
}