// ************************** //
//       monsterClaw.h        //
//      by Jake Conner        //
// ************************** //

#pragma once

#include "attackEvent.h"
#include "monsterArm.h"
#include <memory>
#include <string>

#ifndef MONSTERCLAW_H_INCLUDED
#define MONSTERCLAW_H_INCLUDED

class monsterClaw : public monsterArm {
private:
	bool _impaled;
	std::shared_ptr<monsterArm> _arm;

public:
	// ctr
	monsterClaw() { _impaled = false; };
	monsterClaw(const monsterClaw & rhs) :_impaled(rhs._impaled), _arm(rhs._arm) {};
	monsterClaw(std::shared_ptr<monsterArm> arm) : _arm(arm) { _impaled = false; };

	// virtual functions
	virtual void hit(attackEvent e);
	virtual void injure(std::string injury);
};

#endif