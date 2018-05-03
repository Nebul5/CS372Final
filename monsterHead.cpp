// ************************** //
//      monsterHead.cpp       //
//      by Jake Conner        //
// ************************** //

#include "monsterHead.h"

// hit
void monsterHead::hit(attackEvent e) {
	if (e.slice() && _neck > 0) {
		if (e.damage() >= _neck) {
			_monster->injure("missing a head.");
			_neck = 0;
		}
		else {
			_neck -= e.damage();
		}
	}
	else {
		_monster->hit(e);
	}
}

// injure
void monsterHead::injure(std::string injury) {
	_monster->injure(injury);
}