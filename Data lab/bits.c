/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ~((~x)|(~y));
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
	return 0xff & (x>>(n<<3));

}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
   int mask = ~(((0x1<<31)>>n)<<1);
	return (x>>n) & mask;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    unsigned m1 = 0x55555555;
	unsigned m2 = 0x33333333;
	unsigned m4 = 0x0f0f0f0f;
	x -= (x >> 1) & m1;             
    x = (x & m2) + ((x >> 2) & m2); 
    x = (x + (x >> 4)) & m4;        
    x += x >>  8;  
    x += x >> 16;  
 
    return x &0xff;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  int op = ~x+1;//0xffff
  int op_sign = (op>>31)&0x1;//0x1
  int sign = (x>>31)&0x1; //0
  return (op_sign | sign)^0x1;//0^1=
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return (0x1<<31);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  int shift_num = 32 + (~n + 1);
  return !((x<<shift_num)>>shift_num ^ x);
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    int mask =  x>>31;
	int bias = (0x1<<n) -1;
	return (x + (mask & bias))>>n;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.  0--0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
	int is_zero = !x;
	int is_neg = (x>>31)&0x1;
    return !(is_zero | is_neg);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	int x_sign = (x>>31)&0x1;
	int y_sign = (y>>31)&0x1;
	int z_sign = ((x-y)>>31)&0x1;
	return (x_sign&(!y_sign)) | ((!(x_sign^y_sign))&z_sign) | (!(x^y));
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
/*
int ilog2(int x) {
	int result=0;
	int t1 = !!(x>>16);
	if(t1)
		{x = x>>16;result+=16;}
	int t2 = !!(x>>8);
	if(t2)
		{x=x>>8;;result+=8;}
	int t3 = !!(x>>4);
	if(t3)
		{x=x>>4;result+=4;}
	int t4 = !!(x>>2);
	if(t4)
		{x=x>>2;result+=2;}
	int t5 = !!(x>>1);
	if(t5)
		{result+=1;}
	return result;
}
*/
int ilog2(int x)
{
	int result = 0;
	int t1 = (((!!(x>>16))<<31)>>31)&0x10;
	x = x>>t1;
	result = result + t1;
	
	int t2 = (((!!(x>>8))<<31)>>31)&0x8;
	x = x>>t2;
	result = result + t2;

	int t3 = (((!!(x>>4))<<31)>>31)&0x4;
	x = x>>t3;
	result = result + t3;

	int t4 = (((!!(x>>2))<<31)>>31)&0x2;
	x = x>>t4;
	result = result + t4;

	int t5 = (((!!(x>>1))<<31)>>31)&0x1;
	x = x>>t5;
	result = result + t5;
	
	return result;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */

unsigned float_neg(unsigned uf) {
	unsigned exp_mask = 0xff<<23;
	unsigned exp_is_all_one = !((uf & exp_mask)^exp_mask);
	unsigned frac_mask = (0x1<<23) + (~0);
	unsigned frac= (frac_mask & uf);
	if(exp_is_all_one && frac)
		return uf;
	return (uf ^ (0x1<<31));
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */

unsigned float_i2f(int x)
{
	if(x==0)
		return x;
	int sign,  exponent,fraction;
	//get sign
	sign = (x>>31)&0x1;
	//get positive x
	if(sign)
	{
		if(x==0x8000000)
		{
			//if x==Tmin, ~x+1 will upper overflow
			exponent = 158;
			fraction = 0x0;
			goto Done;
		}else
		{
			x = ~x+1;
		}
	}
	//get exponent
	int i = 31;
	while(!(x>>i))
	{ --i;}
	exponent = i + 127;
	//get fraction
	x = x << (31-i);
	int fraction_mask = 0x007fffff;
	fraction = fraction_mask & (x>>8);//dropped 8 bits data
	//she ru
	int dropped_data = x&0xff;
	//if dropped_data > 127.5, fraction should plus 1
	if(dropped_data > 128 || ((dropped_data==128) && (fraction&0x1)))
		fraction += 1;
	if(fraction>>23)
	{
		fraction &= fraction_mask;
		exponent++;
	}
	
Done:
	return (sign<<31) | (exponent<<23) | fraction;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
	int sign = (uf>>31)&0x1;
	int exponent = (uf>>23)&0xff;
	//case 3,4:
	if(!(exponent^0xff))
		return uf;
	//case 2:
	else if(!(exponent^0x0))
	{
		return (sign<<31)|(uf<<1);
	}
	//case 3:
	else
	{	
		if(!(exponent^(0xfe)))
			return (sign<<31)|0x7f800000;
		else
			return (sign<<31)|((exponent+1)<<23)|(uf)&0x7fffff;
	}
}
