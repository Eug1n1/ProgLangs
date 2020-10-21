#include "Headers.h"

namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0, "Íåäîïóñòèìûé êîä îøèáêè"),
		ERROR_ENTRY(1, "Ñèñòåìíûé ñáîé"),
		ERROR_ENTRY_NODEF(2),ERROR_ENTRY_NODEF(3),ERROR_ENTRY_NODEF(4),ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6),ERROR_ENTRY_NODEF(7),ERROR_ENTRY_NODEF(8),ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10),ERROR_ENTRY_NODEF10(20),ERROR_ENTRY_NODEF10(30),ERROR_ENTRY_NODEF10(40),ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF10(60),ERROR_ENTRY_NODEF10(70),ERROR_ENTRY_NODEF10(80),ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "Ïàğàìåòğ -in äîëæåí áûòü çàäàí"),
		ERROR_ENTRY_NODEF(101),ERROR_ENTRY_NODEF(102),ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104, "Ïğåâûøåíà äëèíà âõîäíîãî ïàğàìåòğà"),
		ERROR_ENTRY_NODEF(105),ERROR_ENTRY_NODEF(106),ERROR_ENTRY_NODEF(107),
		ERROR_ENTRY_NODEF(108),ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110, "Îøèáêà ïğè îòêğûòèè ôàéëà ñ èñõîäíûì êîäîì(-in)"),
		ERROR_ENTRY(111, "Íåäîïóñòèìûé ñèìâîë â èñõîäíîì ôàéëå(-in)"),
		ERROR_ENTRY(112, "Îøèáêà ïğè îòêğûòèè ôàéëà ïğîòîêîëà(-log)"),
		ERROR_ENTRY(113, "Ñóùåñòâóåò íåğàñïîçíàííàÿ öåïî÷êà"),
		ERROR_ENTRY(114, "Íåäîïóñòèìîå çíà÷åíèå ğàçìåğà òàáëèöû ëåêñåì"),
		ERROR_ENTRY(115, "Òàáëèöà ëåêñåì ïåğåïîëíåíà"),
		ERROR_ENTRY(116, "Íåäîïóñòèìû èíäåêñ ñòğîêè â òàáëèöå ëèòåğàëîâ"),
		ERROR_ENTRY(117, "Íåäîïóñòèìîå çíà÷åíèå ğàçìåğà òàáëèöû èäåíòèôèêàòîğîâ"),
		ERROR_ENTRY(118, "Òàáëèöà èäåíòèôèêàòîğîâ ïåğåïîëíåíà"),
		ERROR_ENTRY(119, ""),
		ERROR_ENTRY_NODEF10(120),ERROR_ENTRY_NODEF10(130),ERROR_ENTRY_NODEF10(140),ERROR_ENTRY_NODEF10(150),
		ERROR_ENTRY_NODEF10(160),ERROR_ENTRY_NODEF10(170),ERROR_ENTRY_NODEF10(180),ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY_NODEF100(200),ERROR_ENTRY_NODEF100(300),ERROR_ENTRY_NODEF100(400),ERROR_ENTRY_NODEF100(500),
		ERROR_ENTRY_NODEF100(600),ERROR_ENTRY_NODEF100(700),ERROR_ENTRY_NODEF100(800),ERROR_ENTRY_NODEF100(900),
	};
	ERROR geterror(int id) {
		ERROR error;
		if (id > 0 && id < ERROR_MAX_ENTRY) {
			return error = errors[id];
		}

		return error = errors[0];
	}

	ERROR geterrorin(int id, int line = -1, int col = -1) {
		ERROR error;
		if (id > 0 && id < ERROR_MAX_ENTRY) {
			error = errors[id];
			error.inext.col = col;
			error.inext.line = line;
			return error;
		}

		return error = errors[0];
	}

};