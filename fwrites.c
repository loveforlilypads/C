//
//  fwrites.c
//  
//
//  Created by Stephanie Manzano on 7/29/17.
//
//

/*			fwrite.c
 *
 *   Synopsis  -  Inputs information about banking transactions, and
 *		  stores the information in a file.
 *
 *   Objective -  To illustrate the use of fwrite() to do block
 *		  output of a structure.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define TRUE   1
#define FALSE  0
#define BUFFSIZE  50

struct trans {						/* Note 1 */
    int t_type;
    char payee_memo[BUFFSIZE];
    float amount;
    unsigned tax_deduct:1;
    unsigned cleared:1;
};

void main(void)
{
    struct trans transact;
    FILE *fp;
    int  get_type(void);
    void get_trans(struct trans * tp),
    put_trans(struct trans * tp, FILE *fp);
    /* Note 2 */
    if ( (fp = fopen("transact", "a+") ) == NULL) {
        printf ("Transaction file couldn't be opened.\n");
        exit(1);
    }
    
    /*  The following while loop will continue until the
     *  user types a 'Q' for the transaction type.  Each
     *  time the loop is executed, one transaction is input
     *  and stored in the file.
     */
    while ( (transact.t_type = get_type() ) != 'Q') {
        get_trans(&transact);
        put_trans(&transact, fp);
    }
    fclose (fp);
}
/********************************************   gettype() **********/
/*  Requests and inputs the transaction type from the keyboard.
 *  Any letter entered is converted to upper case before returning,
 *  and a string of digits is converted to type int.  Ensures that
 *  a correct transaction type is returned.
 */
int get_type(void)
{
    char buffer[80];
    int correct = FALSE, t_type;
    
    while (!correct) {
        printf ("D=deposit, W=withdrawal, or Check Number\n");
        printf ("Enter transaction type or 'Q' to quit: ");
        gets(buffer);
        if (isdigit(*buffer) ) {
            /* convert string of digits to
             * type int
             */
            correct = TRUE;
            t_type = atoi(buffer);
        }
        else {
            /* Translate any alphabetic character
             * to upper case for testing and storage.
             */
            t_type = toupper( (int) *buffer );
            if ( (t_type !='D' ) && (t_type !='W')
                && (t_type != 'Q') )
                printf("Incorrect type, try again\n");
            else
                correct = TRUE;
        }
    }
    return (t_type);
}
/******************************************   get_trans() ***********/
/*  Inputs a single transaction from the terminal.
 */
void get_trans(struct trans *trans_ptr)
{
    char inbuf[80];
    
    printf("Amount: $");
    trans_ptr->amount = atof(gets(inbuf));
    
    switch(trans_ptr->t_type) {
        case 'W':
        case 'D': printf ("Memo: ");
            fgets(trans_ptr->payee_memo, BUFFSIZE,
                  stdin);
            break;
        default:  printf ("Payee: ");
            fgets (trans_ptr->payee_memo, BUFFSIZE,
                   stdin);
    }
    
    printf ("Tax_deductible? (y/n) : ");
    gets(inbuf);
    if ( (*inbuf == 'y') || (*inbuf == 'Y') )
        trans_ptr->tax_deduct = 1;
    else
        trans_ptr->tax_deduct = 0;
    
    printf ("Cleared? (y/n) : ");
    gets(inbuf);
    if ( (*inbuf == 'y') || (*inbuf == 'Y') )
        trans_ptr->cleared = 1;
    else
        trans_ptr->cleared = 0;
}
/*********************************************  put_trans() *********/
/*  Outputs the structure pointed to by trans_ptr to the file
 *  associated with fp.
 */
void put_trans(struct trans *trans_ptr, FILE *fp)
{
    /* Note 3 */
    fwrite (trans_ptr, sizeof(struct trans), 1, fp);
}
