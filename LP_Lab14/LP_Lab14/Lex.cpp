#include "Lex.h"
#include "FST.h"


FST::FST typeInt("", 8,
	FST::NODE(1, FST::RELATION('i', 1)),
	FST::NODE(1, FST::RELATION('n', 2)),
	FST::NODE(1, FST::RELATION('t', 3)),
	FST::NODE(1, FST::RELATION('e', 4)),
	FST::NODE(1, FST::RELATION('g', 5)),
	FST::NODE(1, FST::RELATION('e', 6)),
	FST::NODE(1, FST::RELATION('r', 7)),
	FST::NODE()
);

FST::FST typeString("", 7,
	FST::NODE(1, FST::RELATION('s'), 1),
	FST::NODE(1, FST::RELATION('t'), 1),
	FST::NODE(1, FST::RELATION('r'), 1),
	FST::NODE(1, FST::RELATION('i'), 1),
	FST::NODE(1, FST::RELATION('n'), 1),
	FST::NODE(1, FST::RELATION('g'), 1),
	FST::NODE()
);

FST::FST typeDeclare("", 8,
	FST::NODE(1, FST::RELATION('d'), 1),
	FST::NODE(1, FST::RELATION('e'), 1),
	FST::NODE(1, FST::RELATION('c'), 1),
	FST::NODE(1, FST::RELATION('l'), 1),
	FST::NODE(1, FST::RELATION('a'), 1),
	FST::NODE(1, FST::RELATION('r'), 1),
	FST::NODE(1, FST::RELATION('e'), 1),
	FST::NODE()
);

FST::FST typeFunction("", 9,
	FST::NODE(1, FST::RELATION('f'), 1),
	FST::NODE(1, FST::RELATION('u'), 1),
	FST::NODE(1, FST::RELATION('n'), 1),
	FST::NODE(1, FST::RELATION('c'), 1),
	FST::NODE(1, FST::RELATION('t'), 1),
	FST::NODE(1, FST::RELATION('i'), 1),
	FST::NODE(1, FST::RELATION('o'), 1),
	FST::NODE(1, FST::RELATION('n'), 1),
	FST::NODE()
);

FST::FST typeReturn("", 7,
	FST::NODE(1, FST::RELATION('r'), 1),
	FST::NODE(1, FST::RELATION('e'), 1),
	FST::NODE(1, FST::RELATION('t'), 1),
	FST::NODE(1, FST::RELATION('u'), 1),
	FST::NODE(1, FST::RELATION('r'), 1),
	FST::NODE(1, FST::RELATION('n'), 1),
	FST::NODE()
);

FST::FST typePrint("", 6,
	FST::NODE(1, FST::RELATION('p'), 1),
	FST::NODE(1, FST::RELATION('r'), 1),
	FST::NODE(1, FST::RELATION('i'), 1),
	FST::NODE(1, FST::RELATION('n'), 1),
	FST::NODE(1, FST::RELATION('t'), 1),
	FST::NODE()
);

FST::FST typePrint("", 6,
	FST::NODE(1, FST::RELATION('p'), 1),
	FST::NODE(1, FST::RELATION('r'), 1),
	FST::NODE(1, FST::RELATION('i'), 1),
	FST::NODE(1, FST::RELATION('n'), 1),
	FST::NODE(1, FST::RELATION('t'), 1),
	FST::NODE()
);

FST::FST typeMain("", 5,
	FST::NODE(1, FST::RELATION('m'), 1),
	FST::NODE(1, FST::RELATION('a'), 1),
	FST::NODE(1, FST::RELATION('i'), 1),
	FST::NODE(1, FST::RELATION('n'), 1),
	FST::NODE()
);

FST::FST expression("", 2,
	FST::NODE(4,
		FST::RELATION('+', 1),
		FST::RELATION('-', 1),
		FST::RELATION('*', 1),
		FST::RELATION('/', 1)),
	FST::NODE()
);

FST::FST space("", 2,
	FST::NODE(1, FST::RELATION(' ', 1))
);

FST::FST leftBrace("", 2,
	FST::NODE(1, FST::RELATION('{', 1)),
	FST::NODE()
);

FST::FST rightBrace("", 2,
	FST::NODE(1, FST::RELATION('}', 1)),
	FST::NODE()
);

FST::FST leftThesis("", 2,
	FST::NODE(1, FST::RELATION('(', 1)),
	FST::NODE()
);

FST::FST rightThesis("", 2,
	FST::NODE(1, FST::RELATION(')', 1)),
	FST::NODE()
);

FST::FST semicolon("", 2,
	FST::NODE(1, FST::RELATION(';', 1)),
	FST::NODE()
);

FST::FST comma("", 2,
	FST::NODE(1, FST::RELATION(',', 1)),
	FST::NODE()
);

FST::FST plus("", 2,
	FST::NODE(1, FST::RELATION('+', 1)),
	FST::NODE());

FST::FST minus("", 2,
	FST::NODE(1, FST::RELATION('-', 1)),
	FST::NODE());

FST::FST del("", 2,
	FST::NODE(1, FST::RELATION('/', 1)),
	FST::NODE());

FST::FST mul("", 2,
	FST::NODE(1, FST::RELATION('*', 1)),
	FST::NODE());

FST::FST equal("", 2,
	FST::NODE(1, FST::RELATION('=', 1)),
	FST::NODE());


FST::FST literal("", 2,
	FST::NODE(FST::RELATION('0', 0), FST::RELATION('1', 0), FST::RELATION('2', 0), FST::RELATION('3', 0),
		FST::RELATION('4', 0), FST::RELATION('5', 0), FST::RELATION('6', 0), FST::RELATION('7', 0),
		FST::RELATION('8', 0), FST::RELATION('9', 0), FST::RELATION('1', 1), FST::RELATION('2', 1),
		FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('1', 1), FST::RELATION('1', 1), 
		FST::RELATION('1', 1))
	);