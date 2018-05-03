// ************************** //
//       monsterArm.h         //
//      by Jake Conner        //
// ************************** //

#pragma once

#include "attackEvent.h"
#include "bigMonster.h"
#include <memory>
#include <string>

#ifndef MONSTERARM_H_INCLUDED
#define MONSTERARM_H_INCLUDED

class monsterArm : public bigMonster {
private:
	unsigned int _strength;
	std::shared_ptr<bigMonster> _monster;

public:
	// ctr
	monsterArm() { _strength = 0; };
	monsterArm(const monsterArm & rhs) : _strength(rhs._strength), _monster(rhs._monster) {};
	monsterArm(std::shared_ptr<bigMonster> monster, unsigned int strength) : _strength(strength), _monster(std::move(monster)) {};

	// virtual functions
	void hit(attackEvent e) override;
	void injure(std::string injury) override;
};

#endif