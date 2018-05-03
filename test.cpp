// ************************** //
//         test.cpp           //
//      by Jake Conner        //
// ************************** //

#include "bigMonster.h"
#include "monsterHead.h"
#include "monsterArm.h"
#include "monsterEye.h"
#include "monsterClaw.h"
#include <iostream>

int main() {

	// BUILD THE MONSTER //
	bigMonster hydra("hydra", 400);
	auto m = std::make_shared<bigMonster>(hydra);
	monsterHead headOne(m, 20);
	monsterHead headTwo(m, 20);
	monsterHead headThree(m, 40);

	auto h1 = std::make_shared<monsterHead>(headOne);
	auto h2 = std::make_shared<monsterHead>(headTwo);
	auto h3 = std::make_shared<monsterHead>(headThree);

	monsterArm leftArm(m, 50);
	monsterArm rightArm(m, 20);

	auto a1 = std::make_shared<monsterArm>(leftArm);
	auto a2 = std::make_shared<monsterArm>(rightArm);

	monsterClaw leftClaw(a1);
	monsterClaw rightClaw(a2);

	auto c1 = std::make_shared<monsterClaw>(leftClaw);
	auto c2 = std::make_shared<monsterClaw>(rightClaw);

	monsterEye eyeOne(h1);
	monsterEye eyeTwo(h2);
	monsterEye eyeThree(h3);

	auto e1 = std::make_shared<monsterEye>(eyeOne);
	auto e2 = std::make_shared<monsterEye>(eyeTwo);
	auto e3 = std::make_shared<monsterEye>(eyeThree);
	// END //


	// MAKE SOME ATTACK EVENTS //
	attackEvent fireball(FIRE, 100);
	attackEvent spearAttack(PIERCE, 10);
	attackEvent swordAttack(SLICE, 10);
	attackEvent clubAttack(BLUNT, 20);
	attackEvent bigClub(BLUNT, 50);
	// END //


	std::cout << m->report() << std::endl;

	std::cout << "\n * Do damage directly to the monster" << std::endl;
	
	int numAttk = 10;
	for (auto i = 0; i < numAttk; i++) {
		m->hit(swordAttack);
	}
	std::cout << m->report() << std::endl;

	numAttk = 5;
	std::cout << "\n * Do damage to the head \n * Since this is blunt the attack should propagate to the monster" << std::endl;
	for (auto i = 0; i < numAttk; i++) {
		h1->hit(clubAttack);
	}
	std::cout << m->report() << std::endl;

	std::cout << "\n * Cut off one of the hydra's heads with two slicing attacks" << std::endl;
	h1->hit(swordAttack);
	std::cout << m->report() << std::endl;

	h1->hit(swordAttack);
	std::cout << m->report() << std::endl;

	std::cout << "\n * Hitting it 5 times in the arm with a club should do nothing \n * 50 blunt damage in a single hit is needed to break an arm" << std::endl;
	for (auto i = 0; i < numAttk; i++) {
		leftArm.hit(clubAttack);
	}
	std::cout << m->report() << std::endl;

	std::cout << "\n * Actually break the arm" << std::endl;
	leftArm.hit(bigClub);
	std::cout << m->report() << std::endl;


	std::cout << "\n * Slice an eye twice. Damage should propagate to head twice causing it to be cut off" << std::endl;
	e2->hit(swordAttack);
	std::cout << m->report() << std::endl;

	e2->hit(swordAttack);
	std::cout << m->report() << std::endl;

	std::cout << "\n * Now use fire on an eye." << std::endl;
	e3->hit(fireball);
	std::cout << m->report() << std::endl;

	std::cout << "\n * Now hit it in the eye with a club. Damage should propagate to the body" << std::endl;
	e3->hit(bigClub);
	e3->hit(bigClub);
	std::cout << m->report() << std::endl;

	std::cout << "\n * Hit its right claw with a piercing attack." << std::endl;
	c2->hit(spearAttack);
	std::cout << m->report() << std::endl;

	std::cout << "\n * Hit its right claw with a club. Damage should propagate to its arm and break it." << std::endl;
	c2->hit(bigClub);
	std::cout << m->report() << std::endl;

	std::cout << "\n * Hit the same claw with a fireball. Damage should propagate to its body finishing it off." << std::endl;
	c2->hit(fireball);
	std::cout << m->report() << std::endl;

	return 0;
}