//
//  grades.c
//  
//
//  Created by Stephanie Manzano on 7/29/17.
//
//

#include <stdio.h>

/*			prntscan.c
 *
 *        Opens a file of student names and grade point
 *		  averages, reads the file, and puts the names in
 *		  one file and the grade point averages in another.
 *
 *   Point -  To demonstrate some of the printf(), scanf() family
 *		  of functions, sscanf() and fprintf() in particular.
 */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    FILE *fp, *name_fp, *gpa_fp;
    char first[15], last[15], inbuff[80];
    double gpa;
    
    if ( (fp = fopen("studinfo", "r") ) == NULL) {
        printf("Unable to open input file.\n");
        exit(1);
    }
    
    /* Open all files and report any errors.  */
    if ( (name_fp = fopen("names", "w") ) == NULL) {
        printf ("Unable to open names file.\n");
        exit(2);
    }
    
    if ( (gpa_fp = fopen("gpas", "w") ) == NULL) {
        printf ("Unable to open gpa file.\n");
        exit(3);
    }
    
    while  (fgets(inbuff, 80, fp) != NULL) {
        /* Note 1 */
        sscanf (inbuff, "%s %s %f%*c", first, last, &gpa);
        /* Note 2 */
        fprintf (name_fp, "%s, %s\n", last, first);
        fprintf (gpa_fp, "%4.2f\n", gpa);
    }
}
