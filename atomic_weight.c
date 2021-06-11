/*****************************************************************************************************************/
/*					     Atomic Weight Calculator          				         */
/*****************************************************************************************************************/

/*
 * Author:      Aly Khan Nuruddin
 * Date:        May 26, 2021
 *
 * Purpose:     This program reads the atomic compositions of various amino acids from a data file, and then
 *              prints ther identification numbers and computed atomic weights on the screen, for the user.
 */

/*****************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS					// Prohibit the compiler from suggesting secure versions of library functions.

#include <stdio.h>						// Include the standard input and output library in C.

#define OXYGEN_ATOMIC_MASS 15.99940				// Define the atomic mass of oxygen in a.m.u.
#define CARBON_ATOMIC_MASS 12.01100				// Define the atomic mass of carbon in a.m.u.
#define NITROGEN_ATOMIC_MASS 14.00674				// Define the atomic mass of nitrogen in a.m.u.
#define SULFUR_ATOMIC_MASS 32.06600				// Define the atomic mass of sulfur in a.m.u.
#define HYDROGEN_ATOMIC_MASS 1.00794				// Define the atomic mass of hydrogen in a.m.u.

int main(void)							// Define the function "main".
{
	FILE* inputFile;					// Define the file pointer for the data file that is to be opened.

	inputFile = fopen("amino_acids.txt", "r");		// Open the file that stores the identification numbers and number of moles of each element for each amino acid.

	if (inputFile == NULL)					// Define the condition when the file operation fails.
	{
		printf("Error: The file cannot be opened! ");	// Notify the user that the file cannot be opened.
		printf("Please check for a valid file. ");	// Request the user to check for a valid file.
	}

	else							// Define the condition when the file operation succeeds.
	{
		int identificationNumber;			// Define the variable that stores the identification number of each amino acid.

		int oxygenMoles;				// Define the variable that stores the number of moles of oxygen.
		int carbonMoles;				// Define the variable that stores the number of moles of carbon.
		int nitrogenMoles;				// Define the variable that stores the number of moles of nitrogen.
		int sulfurMoles;				// Define the variable that stores the number of moles of sulfur.
		int hydrogenMoles;				// Define the variable that stores the number of moles of hydrogen.

		float atomicWeight;				// Define the variable that stores the atomic weight of each amino acid.

		printf("For each amino acid, the first column indicates its identification number while the second column refers to its atomic weight, computed to six decimal places in g/mol.\n ");	// Inform the user what the data value in each column represents.

		while (fscanf(inputFile, "%d %d %d %d %d %d", &identificationNumber, &oxygenMoles, &carbonMoles, &nitrogenMoles, &sulfurMoles, &hydrogenMoles) != EOF)	 // Read the identification number and number of moles of each element for, row by row, from the data file.
		{
			atomicWeight = (oxygenMoles * OXYGEN_ATOMIC_MASS) + (carbonMoles * CARBON_ATOMIC_MASS) + (nitrogenMoles * NITROGEN_ATOMIC_MASS) + (sulfurMoles * SULFUR_ATOMIC_MASS) + (hydrogenMoles * HYDROGEN_ATOMIC_MASS);	// Compute the atomic weight of each amino acid in grams per mol.

			printf("\n%d %.6f\n\n", identificationNumber, atomicWeight);   // Print the identification number and atomic weight of each amino acid upto six decimal places.
		}

		fclose(inputFile);				// Close the file that stores the identification numbers and number of moles of each element for each amino acid.
	}

	system("PAUSE");					// Suspend the execution of the program.
	return 0;						// Terminate the execution of the program.
}
