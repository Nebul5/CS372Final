// ************************** //
//       attackEvent.h        //
//      by Jake Conner        //
// ************************** //

#pragma once

#ifndef ATTACKEVENT_H_INCLUDED
#define ATTACKEVENT_H_INCLUDED

// attack types
#define FIRE	1
#define PIERCE	2
#define SLICE	4
#define BLUNT	16

class attackEvent {
private:
	using eType = const unsigned int;
	eType _type;
	eType _damage;

public:
	// ctr
	attackEvent() = delete;
	attackEvent(eType type, eType damage) :_type(type), _damage(damage) {};

	// effect checks
	bool fire();
	bool pierce();
	bool slice();
	bool blunt();

	// get damage
	unsigned int damage();
};

// NOTE: I could use the decorator pattern here, but I'm opting not to in order to focus on the pattern I actually want to demonstrate. 

#endif