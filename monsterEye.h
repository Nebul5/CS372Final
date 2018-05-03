// ************************** //
//       monsterEye.h         //
//      by Jake Conner        //
// ************************** //

#pragma once

#include "attackEvent.h"
#include "monsterHead.h"
#include <memory>
#include <string>

#ifndef MONSTEREYE_H_INCLUDED
#define MONSTEREYE_H_INCLUDED

class monsterEye : public monsterHead {
private:
	bool _blind;
	std::shared_ptr<monsterHead> _head;

public:
	// ctr
	monsterEye() { _blind = false; };
	monsterEye(const monsterEye & rhs) :_blind(rhs._blind), _head(rhs._head) {};
	monsterEye(std::shared_ptr<monsterHead> head) : _head(std::move(head)) { _blind = false; };

	// virtual functions
	void hit(attackEvent e) override;
	void injure(std::string injury) override;
};

#endif