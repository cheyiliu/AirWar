/*
 * RoleBulletYellow.cpp
 *
 *  Created on: 2015-11-6
 *      Author: hsy
 */

#include "RoleBulletYellow.h"

RoleBulletYellow::RoleBulletYellow() {
	// TODO Auto-generated constructor stub

}

RoleBulletYellow::~RoleBulletYellow() {
	// TODO Auto-generated destructor stub
}

RoleBulletYellow* RoleBulletYellow::create(float x, float y) {
	RoleBulletYellow *pRet = new (std::nothrow) RoleBulletYellow();
	if (pRet && pRet->init(x, y)) {
		pRet->autorelease();
		return pRet;
	} else {
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool RoleBulletYellow::init(float x, float y) {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Sprite::initWithSpriteFrameName("bullet1.png"));

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
		float velocity = 320 / 1; //320pixel/sec
		float realMoveDuration = length / velocity;

		auto actionMove = MoveTo::create(realMoveDuration,
				Point(bulletPosition.x,
						Director::getInstance()->getWinSize().height
								+ getContentSize().height / 2));
		auto actionDone = CallFuncN::create(
				CC_CALLBACK_0(RoleBulletYellow::removeFromParent, this));

		auto sequence = Sequence::create(actionMove, actionDone, nullptr);
		runAction(sequence);

		bRet = true;
	} while (0);

	return bRet;
}

void RoleBulletYellow::hit(Role* target) {
	int force = 100;
	target->gotDamage(force);
}

void RoleBulletYellow::gotDamage(int damage) {
	down();
}

void RoleBulletYellow::gotSupply(int supply) {
}

void RoleBulletYellow::down() {
	removeFromParent();
}

