/*
 * RoleEnemyBig.cpp
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#include "RoleEnemyBig.h"
#include "SimpleAudioEngine.h"

RoleEnemyBig::RoleEnemyBig() {
	// TODO Auto-generated constructor stub

}

RoleEnemyBig::~RoleEnemyBig() {
	// TODO Auto-generated destructor stub
}

bool RoleEnemyBig::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Sprite::initWithSpriteFrameName("enemy3_n1.png"));

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
				CC_CALLBACK_0(RoleEnemyBig::removeFromParent, this));

		auto sequence = Sequence::create(actionMove, actionDone, nullptr);
		runAction(sequence);

		auto enemy3SpriteFrame_1 =
				SpriteFrameCache::getInstance()->getSpriteFrameByName(
						"enemy3_n1.png");
		auto enemy3SpriteFrame_2 =
				SpriteFrameCache::getInstance()->getSpriteFrameByName(
						"enemy3_n2.png");
		auto animation = Animation::create();
		animation->setDelayPerUnit(0.2f);
		animation->addSpriteFrame(enemy3SpriteFrame_1);
		animation->addSpriteFrame(enemy3SpriteFrame_2);
		auto animate = Animate::create(animation);
		runAction(RepeatForever::create(animate));

		bRet = true;
	} while (0);

	return bRet;
}

void RoleEnemyBig::hit(Role* target) {
	target->gotDamage(100);
}

void RoleEnemyBig::gotDamage(int damage) {
	down();
}

void RoleEnemyBig::gotSupply(int supply) {
}

void RoleEnemyBig::down() {
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(
			"sound/enemy3_down.mp3");
	auto animation = AnimationCache::getInstance()->getAnimation(
			"Enemy3Blowup");
	auto animate = Animate::create(animation);

	auto remove = CallFunc::create(
			CC_CALLBACK_0(RoleEnemyBig::removeFromParent, this));
	auto sequence = Sequence::create(animate, remove, nullptr);
	runAction(sequence);
}

