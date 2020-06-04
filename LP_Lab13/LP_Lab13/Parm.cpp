#include "Parm.h"
#include <wchar.h>
#include "Error.h"

Parm::PARM Parm::getParm(int argc, _TCHAR* argv[])
{
	int k = 0;
	PARM parm;
	parm.out[0] = '\0';
	parm.log[0] = '\0';
	parm.in[0] = '\0';
	for (int i = 1; i < argc; i++) {
		if (wcsstr(argv[i], PARM_IN)) {
			for (int j = 4; j < wcslen(argv[i]); j++) {
				parm.in[k++] = argv[i][j];
			}
			parm.in[k] = '\0';
		}
		

		k = 0;
		if (wcsstr(argv[i], PARM_OUT)) {
			for (int j = 5; j < wcslen(argv[i]); j++) {
				parm.out[k++] = argv[i][j];
			}
			parm.out[k] = '\0';
		}

		k = 0;
		if (wcsstr(argv[i], PARM_LOG)) {
			for (int j = 5; j < wcslen(argv[i]); j++) {
				parm.log[k++] = argv[i][j];
			}
			parm.log[k] = '\0';
		}
		
	}

	if (parm.in[0] == '\0') {
		throw ERROR_THROW(100);
	}

	if (parm.out[0] == '\0') {
		wcscpy_s(parm.out, parm.in);
		wcsncat_s(parm.out, PARM_OUT_DEFAULT_EXT, 4);
	}

	if (parm.log[0] == '\0') {
		wcscpy_s(parm.log, parm.in);
		wcsncat_s(parm.log, PARM_LOG_DEFAULT_EXT, 4);
	}


	return parm;
}
