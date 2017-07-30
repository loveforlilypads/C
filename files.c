//
//  files.c
//  
//
//  Created by Stephanie Manzano on 7/29/17.
//
//

#include "files.h"

#include <stdio.h>

void main(void)
{
    FILE *fp;
    
    if ( (fp = fopen("info", "r") ) == NULL ) {	/* Note 1 */
        printf ("Input file could not be opened\n");
        exit(1);
    }
    
    /* Other code to process the file might
     * be placed here.
     */
    
    if (fclose(fp) == EOF)				/* Note 2 */
        printf ("File couldn't be closed\n");
}
