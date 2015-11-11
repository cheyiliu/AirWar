/*
 * RoleHeroPlane.cpp
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#include "RoleHeroPlane.h"

RoleHeroPlane::RoleHeroPlane() {
	// TODO Auto-generated constructor stub

}

RoleHeroPlane::~RoleHeroPlane() {
	// TODO Auto-generated destructor stub
}

bool RoleHeroPlane::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Sprite::initWithSpriteFrameName("hero1.png"));

		// set physical body
		auto body = PhysicsBody::createBox(getContentSize());
		body->setGroup(PHYSICAL_BODY_HERO_GROUP);
		body->setCategoryBitmask(PHYSICAL_BODY_HERO_BITMASK_CATEGORY);
		body->setContactTestBitmask(PHYSICAL_BODY_HERO_BITMASK_CONTACT_TEST);
		body->setCollisionBitmask(PHYSICAL_BODY_HERO_BITMASK_COLLISION);
		setPhysicsBody(body);

		// set position
		auto winSize = Director::getInstance()->getWinSize();
		setPosition(Point(winSize.width / 2, getContentSize().height / 2));

		// run action
		auto blink = Blink::create(1, 3);
		auto animation = Animation::create();
		animation->setDelayPerUnit(0.1f);
		animation->addSpriteFrame(
				SpriteFrameCache::getInstance()->getSpriteFrameByName(
						"hero1.png"));
		animation->addSpriteFrame(
				SpriteFrameCache::getInstance()->getSpriteFrameByName(
						"hero2.png"));
		auto animate = Animate::create(animation);

		runAction(blink);
		runAction(RepeatForever::create(animate));

		bRet = true;
	} while (0);

	return bRet;
}

void RoleHeroPlane::hit(Role* target) {
	int force = 100;
	target->gotDamage(force);
}

void RoleHeroPlane::gotDamage(int damage) {
//	int life = 100;// TODO life and force settings will be consider after the main process is ready
//	if(life - damage <= 0){
//		life = 0;
//		down();
//	}
	down();
}

void RoleHeroPlane::gotSupply(int supply) {
	log("hero got suppy ");
}

void RoleHeroPlane::down() {
	auto animation = Animation::create();
	animation->setDelayPerUnit(0.2f);
	animation->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(
					"hero_blowup_n1.png"));
	animation->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(
					"hero_blowup_n2.png"));
	animation->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(
					"hero_blowup_n3.png"));
	animation->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(
					"hero_blowup_n4.png"));

	auto animate = Animate::create(animation);
	auto actionDone = RemoveSelf::create(true);
	auto sequence = Sequence::create(animate, actionDone, nullptr);
	stopAllActions();
	runAction(sequence);
}

