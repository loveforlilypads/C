//
//  file2.c
//  
//
//  Created by Stephanie Manzano on 7/29/17.
//
//

/*
 *
 *   Makes a copy of a file.  The names for the original
 *   file and the copy are on the command line.
 *
 *   Point -  To illustrate file handling.
 */

#include <stdio.h>					/* Note 1 */

void main(int argc, char *argv[])
{
	FILE *fpin, *fpout;				/* Note 2 */
	int iochar;

	if (argc != 3) {
		printf ("Usage: cp oldfile newfile\n");
		exit(1);                     		/* Note 3 */
	}

	if ( (fpin = fopen (argv[1], "r")) == NULL) {
		printf("Can't open input file.\n");	/* Note 4 */
		exit(1);
	}
	if ( (fpout = fopen (argv[2], "w")) == NULL ) {
		printf ("Can't open output file.\n");   /* Note 5 */
		exit (1);
	}

	while ( (iochar = getc(fpin)) != EOF)           /* Note 6 */
		putc (iochar, fpout);
}
