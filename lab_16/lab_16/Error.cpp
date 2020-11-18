﻿#include "Error.h"

namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] = 
	{
		ERROR_ENTRY(0, "Недопустимый код ошибки"), // код ошибки вне диапазона 0 - ERROR_MAX_ENTRY
		ERROR_ENTRY(1, "Системный сбой"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "Параметр -in должен быть задан"),
		ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104, "Превышена длина входного параметра"),
		ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107),
		ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110, "Ошибка при открытии файла с исходным кодом (-in)"),
		ERROR_ENTRY(111, "Недопустимый символ в исходном коде (-in)"),
		ERROR_ENTRY(112, "Ошибка при создании файла протокола (-log)"),
		ERROR_ENTRY_NODEF(113),
		ERROR_ENTRY_NODEF(114),
		ERROR_ENTRY_NODEF(115),
		ERROR_ENTRY_NODEF(116),
		ERROR_ENTRY_NODEF(117), ERROR_ENTRY_NODEF(118), ERROR_ENTRY_NODEF(119),
		ERROR_ENTRY(120, "Таблица лексем переполнена."),
		ERROR_ENTRY(121, "Нераспознанная лексема"),
		ERROR_ENTRY(122, "Таблица идентификаторов переполнена"),
		ERROR_ENTRY(123, "Перезапись идентификатора"),
		ERROR_ENTRY(124, "Выход за границу таблицы лексем (или идентификаторов)"),
		ERROR_ENTRY(125, "Не удалось создать файл с лексемами (или идентификаторами)"),
		ERROR_ENTRY(126, "Слишком длинный литерал"),
		ERROR_ENTRY(127, "Неверный формат строкового литерала"),
		ERROR_ENTRY(128, "Слишком длинное имя переменной"),
		ERROR_ENTRY(129, "Неизвестная переменная"),
		ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150),
		ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY_NODEF100(200), ERROR_ENTRY_NODEF100(300), ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500),
		ERROR_ENTRY(600, "Неверная структура программы"),
		ERROR_ENTRY(601, "Ошибочный сепаратор"),
		ERROR_ENTRY(602, "Ошибка в выражении"),
		ERROR_ENTRY(603, "Ошибка в параметрах функции"),
		ERROR_ENTRY(604, "Ошибка в параметрах вызываемой функции"),
		ERROR_ENTRY_NODEF(605), ERROR_ENTRY_NODEF(606), ERROR_ENTRY_NODEF(607), ERROR_ENTRY_NODEF(608), ERROR_ENTRY_NODEF(609),
		ERROR_ENTRY_NODEF10(610), ERROR_ENTRY_NODEF10(620), ERROR_ENTRY_NODEF10(630), ERROR_ENTRY_NODEF10(640),
		ERROR_ENTRY_NODEF10(650), ERROR_ENTRY_NODEF10(660), ERROR_ENTRY_NODEF10(670), ERROR_ENTRY_NODEF10(680),
		ERROR_ENTRY_NODEF10(690),
		ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)
	};
	ERROR geterror(int id) {
		ERROR err;
		if (id < 0 || id > ERROR_MAX_ENTRY) {
			err.id = errors[0].id;
			strcpy_s(err.message, errors[0].message);
		}
		else {
			err.id = errors[id].id;
			strcpy_s(err.message, errors[id].message);
		}
		return err;
	}
	ERROR geterrorin(int id, int line = -1, int col = -1) {
		ERROR err;
		if (id < 0 || id > ERROR_MAX_ENTRY) {
			err.id = errors[0].id;
			strcpy_s(err.message, errors[0].message);
		}
		else {
			err.id = errors[id].id;
			strcpy_s(err.message, errors[id].message);
		}
		err.inext.line = line;
		err.inext.col = col;
		return err;
	}
}
