// ************************** //
//      monsterArm.cpp        //
//      by Jake Conner        //
// ************************** //

#include "monsterArm.h"

// hit
void monsterArm::hit(attackEvent e) {
	if (e.blunt() && _strength > 0) {
		if (e.damage() >= _strength) {
			_monster->injure("nursing a broken arm.");
			_strength = 0;
		}
	}
	else {
		_monster->hit(e);
	}
}

// injure
void monsterArm::injure(std::string injury) {
	_monster->injure(injury);
}