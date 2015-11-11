/*
 * RoleBulletBlue.cpp
 *
 *  Created on: 2015-11-6
 *      Author: hsy
 */

#include "RoleBulletBlue.h"

RoleBulletBlue::RoleBulletBlue() {
	// TODO Auto-generated constructor stub

}

RoleBulletBlue::~RoleBulletBlue() {
	// TODO Auto-generated destructor stub
}

RoleBulletBlue* RoleBulletBlue::create(float x, float y) {
	RoleBulletBlue *pRet = new (std::nothrow) RoleBulletBlue();
	if (pRet && pRet->init(x, y)) {
		pRet->autorelease();
		return pRet;
	} else {
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool RoleBulletBlue::init(float x, float y) {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Sprite::initWithSpriteFrameName("bullet2.png"));

		// set physical body
		auto body = PhysicsBody::createBox(getContentSize());
		body->setGroup(PHYSICAL_BODY_BULLET_GROUP);
		body->setCategoryBitmask(PHYSICAL_BODY_BULLET_BITMASK_CATEGORY);
		body->setContactTestBitmask(PHYSICAL_BODY_BULLET_BITMASK_CONTACT_TEST);
		body->setCollisionBitmask(PHYSICAL_BODY_BULLET_BITMASK_COLLISION);
		setPhysicsBody(body);

		// set position
		Point bulletPosition = Point(x, y);
		setPosition(bulletPosition);

		// run action
		float length = Director::getInstance()->getWinSize().height
				+ getContentSize().height / 2 - bulletPosition.y;
		float velocity = 420 / 1; //420pixel/sec
		float realMoveDuration = length / velocity;

		auto actionMove = MoveTo::create(realMoveDuration,
				Point(bulletPosition.x,
						Director::getInstance()->getWinSize().height
								+ getContentSize().height / 2));
		auto actionDone = RemoveSelf::create(true);
		auto sequence = Sequence::create(actionMove, actionDone, nullptr);
		runAction(sequence);

		bRet = true;
	} while (0);

	return bRet;
}

void RoleBulletBlue::hit(Role* target) {
	int force = 100;
	target->gotDamage(force);
}

void RoleBulletBlue::gotDamage(int damage) {
	down();
}

void RoleBulletBlue::gotSupply(int supply) {
}

void RoleBulletBlue::down() {
	auto actionDone = RemoveSelf::create(true);
	runAction(actionDone);
}

