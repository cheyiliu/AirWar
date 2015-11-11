/*
 * RoleSupplyDoubleGun.cpp
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#include "RoleSupplyDoubleGun.h"

RoleSupplyDoubleGun::RoleSupplyDoubleGun() {
	// TODO Auto-generated constructor stub

}

RoleSupplyDoubleGun::~RoleSupplyDoubleGun() {
	// TODO Auto-generated destructor stub
}

bool RoleSupplyDoubleGun::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Sprite::initWithSpriteFrameName("ufo1.png"));

		// set physical body
		auto body = PhysicsBody::createBox(getContentSize());
		body->setGroup(PHYSICAL_BODY_SUPPLY_GROUP);
		body->setCategoryBitmask(PHYSICAL_BODY_SUPPLY_BITMASK_CATEGORY);
		body->setContactTestBitmask(PHYSICAL_BODY_SUPPLY_BITMASK_CONTACT_TEST);
		body->setCollisionBitmask(PHYSICAL_BODY_SUPPLY_BITMASK_COLLISION);
		setPhysicsBody(body);

		// set position
		auto bigBoomSize = getContentSize();
		auto winSize = Director::getInstance()->getWinSize();
		int minX = bigBoomSize.width/2;
		int maxX = winSize.width-bigBoomSize.width/2;
		int rangeX = maxX-minX;
		int actualX = (rand()%rangeX)+minX;
		setPosition(Point(actualX, winSize.height+bigBoomSize.height/2));

		// run action
		auto move1 = MoveBy::create(0.5, Point(0, -150));
		auto move2 = MoveBy::create(0.3, Point(0, 100));
		auto move3 = MoveBy::create(1.0, Point(0, 0-winSize.height-bigBoomSize.height/2));
		auto actionDone = RemoveSelf::create(true);
		auto sequence = Sequence::create(move1, move2, move3, actionDone, nullptr);
		runAction(sequence);

		bRet = true;
	} while (0);

	return bRet;
}

void RoleSupplyDoubleGun::hit(Role* target) {
	target->gotSupply(SUPPLY_SUPPER_GUN);
}

void RoleSupplyDoubleGun::gotDamage(int damage) {
	down();
}

void RoleSupplyDoubleGun::gotSupply(int supply) {
}

void RoleSupplyDoubleGun::down() {
	auto actionDone = RemoveSelf::create(true);
	runAction(actionDone);
}


