// ************************** //
//      monsterClaw.cpp       //
//      by Jake Conner        //
// ************************** //

#include "monsterClaw.h"

// hit
void monsterClaw::hit(attackEvent e) {
	if (e.pierce() && !_impaled) {
		_arm->injure("impaled through the hand.");
		_impaled = true;
	}
	else {
		_arm->hit(e);
	}
}

// injure
void monsterClaw::injure(std::string injury) {
	_arm->injure(injury);
}