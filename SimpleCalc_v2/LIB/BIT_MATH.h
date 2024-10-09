#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_
#define SET_BIT(REG,BIT_NO) REG|=(1<<BIT_NO)
#define CLR_BIT(REG,BIT_NO) REG&=~(1<<BIT_NO)
#define TOGGLE_BIT(REG,BIT_NO) REG^=(1<<BIT_NO)
#define GET_BIT(REG,BIT_NO) ((REG>>BIT_NO) &1)  

#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) Conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif




