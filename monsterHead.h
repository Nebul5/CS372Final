// ************************** //
//       monsterHead.h        //
//      by Jake Conner        //
// ************************** //

#pragma once

#include "attackEvent.h"
#include "bigMonster.h"
#include <memory>
#include <string>

#ifndef MONSTERHEAD_H_INCLUDED
#define MONSTERHEAD_H_INCLUDED

class monsterHead : public bigMonster {
private:
	unsigned int _neck;
	std::shared_ptr<bigMonster> _monster;

public:
	// ctr
	monsterHead() { _neck = 0; };
	monsterHead(const monsterHead & rhs) : _neck(rhs._neck), _monster(rhs._monster) {};
	monsterHead(std::shared_ptr<bigMonster> monster, unsigned int neck) : _neck(neck), _monster(monster) {};

	// virtual functions
	virtual void hit(attackEvent e);
	virtual void injure(std::string injury);
};

#endif