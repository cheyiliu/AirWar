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

		auto winSize = Director::getInstance()->getWinSize();

		setPosition(
				Point(winSize.width / 2, getContentSize().height / 2));

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
}

void RoleHeroPlane::gotDamage(int damage) {
}

void RoleHeroPlane::gotSupply(int supply) {
}

void RoleHeroPlane::down() {
}
