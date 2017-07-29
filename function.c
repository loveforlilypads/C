
/*
* Stephanie Manzano
*  function.c
*
*/

/* include files */
#include <stdio.h>

/* function prototypes */
int f( int x );

/*
* precondition: x can be any integer
* postcondition: the value returned is x+3
*/

int main ( void )
{	

	int x, y, z;

/* the line y = f (z) ; calls the function f ( ) with the value of z as the parameter and assigns the return value to y. /*

z = 4
y = f (z ) ;
printf ( “y is %d\n “, y );

x = y + f ( 3 );
printf ( “the value of x is %d\n, x ); 

/* operand call to f ( ) arithmetic addition. the sum is determined with C by finding the value of f ( 3 ). Calling the function f ( ) with 3 as the parameter. The returned value gets added to y as well as assigned to x. */

f ( x ) ; /* for the third time a call to f ( ) is in f ( x )
printf ( “ The value of f ( 5 ) is d%\n, f ( 5 ) ) ;

return 0;
}

int f ( int x )
{
	return x + 3;
}
