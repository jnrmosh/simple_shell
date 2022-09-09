#include "main.h"

/**
 * errorHandler - prints error message for shell
 * @build: the build config
 */

void errorHandler(config *build)
{
	register int len;
	static char error[BUFSIZE];
	char *ptr, *alpha;

	alpha = itoa(build->lineCounter);
	_strcat(error, build->shellName);
	_strcat(error, ": ");
	_strcat(error, alpha);
	_strcat(error, ": ");
	_strcat(error, build->args[0]);
	_strcat(error, getErrorMessage());
	if (build->args[1])
	{
		if (errno != EBADCD)
			_strcat(error, ": ");
		_strcat(error, build->args[1]);
	}
