//
//  retval.c
//  
//
//  Created by Stephanie Manzano on 7/29/17.
//
//

#include <stdio.h>

/*			retval.c
 *
 *   Synopsis  -  Requests and accepts input of a string, an int, a
 *		  char, and a float.  Echoes those quantities and
 *		  outputs the values returned by printf() and scanf().
 *
 *   Objective -  To allow the student to experiment with input to
 *		  scanf() to get a feel for when and how conversions
 *		  are made and what feedback is provided by scanf().
 */


void main(void)
{
    char charvar, buff[80];
    int intvar, printret, scanret;
    float floatvar;
    
    printf ("Enter a string, an int, a character, and a float: ");
    /* Note 1 */
    scanret = scanf("%s%d%c%f", buff, &intvar,
                    &charvar, &floatvar);
    /* Note 2 */
    printret = printf("Values : %s, %d, |%c|, %5.3f\n",
                      buff, intvar, charvar, floatvar);
    printf ("printret %d, scanret %d\n", printret, scanret);
}
