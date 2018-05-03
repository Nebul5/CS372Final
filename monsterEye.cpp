// ************************** //
//      monsterEye.cpp        //
//      by Jake Conner        //
// ************************** //

#include "monsterEye.h"

// hit
void monsterEye::hit(attackEvent e) {
	if (e.fire() && !_blind) {
		_head->injure("blinded in one eye.");
		_blind = true;
	}
	else {
		_head->hit(e);
	}
}

// injure
void monsterEye::injure(std::string injury) {
	_head->injure(injury);
}