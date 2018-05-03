// ************************** //
//       bigMonster.h         //
//      by Jake Conner        //
// ************************** //

#pragma once

#include "attackEvent.h"
#include <string>
#include <vector>

#ifndef BIGMONSTER_H_INCLUDED
#define BIGMONSTER_H_INCLUDED

class bigMonster {
private:
	std::string _name;
	int _maxHp;
	int _curHp;
	std::vector<std::string> _injuries;

public:
	// ctrs
	bigMonster() { _maxHp = 0; _curHp = 0; _name = ""; };
	bigMonster(std::string name, int hp) : _name(std::move(name)), _maxHp(hp) { _curHp = hp; };
	bigMonster(const bigMonster & rhs) = default;

	// virtual functions
	virtual void hit(attackEvent e);
	virtual void injure(std::string injury);

	// report the status of the monster
	std::string report();
};

#endif