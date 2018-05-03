// ************************** //
//      attackEvent.cpp       //
//      by Jake Conner        //
// ************************** //

#include "attackEvent.h"

bool attackEvent::fire() {
	return _type & FIRE;
}

bool attackEvent::pierce() {
	return _type & PIERCE;
}

bool attackEvent::slice() {
	return _type & SLICE;
}

bool attackEvent::blunt() {
	return _type & BLUNT;
}

unsigned int attackEvent::damage() {
	return _damage;
}


