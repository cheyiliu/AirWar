/*
 * RoleEnemyMiddle.cpp
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#include "RoleEnemyMiddle.h"
#include "SimpleAudioEngine.h"

RoleEnemyMiddle::RoleEnemyMiddle() {
	// TODO Auto-generated constructor stub

}

RoleEnemyMiddle::~RoleEnemyMiddle() {
	// TODO Auto-generated destructor stub
}

bool RoleEnemyMiddle::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Sprite::initWithSpriteFrameName("enemy2.png"));

		// set physical body
		auto body = PhysicsBody::createBox(getContentSize());
		body->setGroup(PHYSICAL_BODY_ENEMY_GROUP);
		body->setCategoryBitmask(PHYSICAL_BODY_ENEMY_BITMASK_CATEGORY);
		body->setContactTestBitmask(PHYSICAL_BODY_ENEMY_BITMASK_CONTACT_TEST);
		body->setCollisionBitmask(PHYSICAL_BODY_ENEMY_BITMASK_COLLISION);
		setPhysicsBody(body);

		// set position
		auto enemy1Size = getContentSize();
		auto winSize = Director::getInstance()->getWinSize();
		int minX = enemy1Size.width / 2;
		int maxX = winSize.width - enemy1Size.width / 2;
		int rangeX = maxX - minX;
		int actualX = (rand() % rangeX) + minX;
		setPosition(Point(actualX, winSize.height + enemy1Size.height / 2));

		// run action
		float minDuration, maxDuration;
		minDuration = 2.0f;
		maxDuration = 4.0f;

		int rangeDuration = maxDuration - minDuration;
		int actualDuration = (rand() % rangeDuration) + minDuration;

		auto actionMove = MoveTo::create(actualDuration,
				Point(actualX, 0 - getContentSize().height / 2));
		auto actionDone = CallFuncN::create(
				CC_CALLBACK_0(RoleEnemyMiddle::removeFromParent, this));

		auto sequence = Sequence::create(actionMove, actionDone, nullptr);
		runAction(sequence);

		bRet = true;
	} while (0);

	return bRet;
}

void RoleEnemyMiddle::hit(Role* target) {
	target->gotDamage(100);
}

void RoleEnemyMiddle::gotDamage(int damage) {
	down();
}

void RoleEnemyMiddle::gotSupply(int supply) {
}

void RoleEnemyMiddle::down() {
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(
			"sound/enemy2_down.mp3");
	auto animation = AnimationCache::getInstance()->getAnimation(
			"Enemy2Blowup");
	auto animate = Animate::create(animation);

	auto remove = CallFunc::create(
			CC_CALLBACK_0(RoleEnemyMiddle::removeFromParent, this));
	auto sequence = Sequence::create(animate, remove, nullptr);
	runAction(sequence);
}

