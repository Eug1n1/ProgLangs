#include "Parm.h"
#include <wchar.h>

Parm::PARM Parm::getParm(int argc, _TCHAR* argv[])
{
	int k = 0;
	PARM parm;
	for (int i = 1; i < argc; i++) {
		if (wcsstr(argv[i], PARM_IN)) {
			for (int j = 4; j < wcslen(argv[i]); j++) {
				parm.in[k++] = argv[i][j];
			}
		}
	}

	for (int i = 1; i < argc; i++) {

		k = 0;
		if (wcsstr(argv[i], PARM_OUT)) {
			for (int j = 5; j < wcslen(argv[i]); j++) {
				parm.out[k++] = argv[i][j];
			}
		}
		else {
			for (int j = 0; j < wcslen(argv[i]) - 8; j++) {
				parm.out[k++] = parm.in[j];
			}
			parm.out[k] = '\0';
			wcsncat_s(parm.out, PARM_OUT_DEFAULT_EXT, 4);
		}
	}

	for (int i = 1; i < argc; i++) {
		k = 0;
		if (wcsstr(argv[i], PARM_LOG)) {
			for (int j = 5; j < wcslen(argv[i]); j++) {
				parm.log[k++] = argv[i][j];
			}
		}
		else {
			for (int j = 0; j < wcslen(argv[i]) - 8; j++) {
				parm.log[k++] = parm.in[j];
			}
			parm.log[k] = '\0';
			wcsncat_s(parm.log, PARM_LOG_DEFAULT_EXT, 4);
		}
	}
	return parm;
}
