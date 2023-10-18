#include "shell.h"
/**
 *prompt - function to print shell prompt
 *No return Value
 */

void prompt(void)
{
		/*Display prompt*/
		write(STDOUT_FILENO, "#cisfun$ ", 9);
}
