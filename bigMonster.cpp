// ************************** //
//      bigMonster.cpp        //
//      by Jake Conner        //
// ************************** //

#include "bigMonster.h"

// hit
void bigMonster::hit(attackEvent e) {
	_curHp -= e.damage();
}

// injure
void bigMonster::injure(std::string injury) {
	_injuries.push_back(injury);
}

// report
std::string bigMonster::report() {
	double p = 100.0 / _maxHp;
	p *= _curHp;
	std::string out = "( hp: " + std::to_string(_curHp) + " ) " +_name;

	if (p > 75.0) {
		out += " is acting almost unhurt.";
	}
	else if (p > 50.0) {
		out += " is acting wounded.";
	}
	else if (p > 25.0) {
		out += " is acting badly wounded.";
	}
	else if (p > 0.0) {
		out += " is looking almost finished.";
	}
	else {
		out += " is dead.";
	}

	for(auto i : _injuries){
		out += ("\n    " +_name + " is " +i);
	}

	return out;
}