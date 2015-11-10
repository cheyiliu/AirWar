/*
 * LayerOfRole.cpp
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#include "LayerOfRole.h"
#include "../role/Role.h"
//#include "../role/RoleHeroPlane.h"
//#include "../role/RoleEnemySmall.h"
//#include "../role/RoleEnemyMiddle.h"
//#include "../role/RoleEnemyBig.h"
//#include "../role/RoleSupplySupperGun.h"
//#include "../role/RoleSupplyDoubleGun.h"
//#include "../role/RoleBulletBlue.h"
//#include "../role/RoleBulletYellow.h"
#include "../role/RoleManager.h"

LayerOfRole::LayerOfRole() {
	mRoleManager = new (std::nothrow) RoleManager();
	if (mRoleManager != nullptr) {
		mRoleManager->registerLayer(this);
	}
}

LayerOfRole::~LayerOfRole() {
	if (mRoleManager != nullptr) {
		mRoleManager->unRegisterLayer(this);
		mRoleManager->release();
		mRoleManager = nullptr;
	}
}

bool LayerOfRole::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Layer::init());

		registerPhysicalEventListener();
		cacheAnimation();

		if (mRoleManager != nullptr) {
			mRoleManager->startAddAll();
		}
		//auto hero = RoleHeroPlane::create();
		//addChild(hero);

		//auto enemySmall = RoleEnemySmall::create();
		//addChild(enemySmall);

		//auto enemyMiddle = RoleEnemyMiddle::create();
		//addChild(enemyMiddle);

		//auto enemyBig = RoleEnemyBig::create();
		//addChild(enemyBig);

		//auto supplySupper = RoleSupplySupperGun::create();
		//addChild(supplySupper);

		//auto supplyDouble = RoleSupplyDoubleGun::create();
		//addChild(supplyDouble);

		//auto winSize = Director::getInstance()->getWinSize();
		//auto bulletYellow = RoleBulletYellow::create(winSize.width / 2,
		//		getContentSize().height / 2);
		//addChild(bulletYellow);
		//
		//auto bulletBlue = RoleBulletBlue::create(winSize.width / 2 + 20,
		//		getContentSize().height / 2);
		//addChild(bulletBlue);

		bRet = true;
	} while (0);

	return bRet;
}

void LayerOfRole::registerPhysicalEventListener() {
	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin =
			[](PhysicsContact& contact)
			{
				Role* a = dynamic_cast<Role * >(contact.getShapeA()->getBody()->getNode());
				Role* b = dynamic_cast<Role * >(contact.getShapeB()->getBody()->getNode());
				if(a && b) {
					a->hit(b);
					b->hit(a);
				}

				return true;
			};

	listener->onContactPreSolve = [] (PhysicsContact& contact,
			PhysicsContactPreSolve& solve) {
		return true;
	};

	listener->onContactPostSolve = [] (PhysicsContact& contact,
			const PhysicsContactPostSolve& solve) {
	};

	listener->onContactSeparate = [](PhysicsContact& contact) {
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(
			listener, 1);
}

void LayerOfRole::cacheAnimation() {

	auto animation1 = Animation::create();
	animation1->setDelayPerUnit(0.1f);
	animation1->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(
					"enemy1_down1.png"));
	animation1->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(
					"enemy1_down2.png"));
	animation1->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(
					"enemy1_down3.png"));
	animation1->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(
					"enemy1_down4.png"));

	auto animation2 = Animation::create();
	animation2->setDelayPerUnit(0.1f);
	animation2->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(
					"enemy2_down1.png"));
	animation2->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(
					"enemy2_down2.png"));
	animation2->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(
					"enemy2_down3.png"));
	animation2->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(
					"enemy2_down4.png"));

	auto animation3 = Animation::create();
	animation3->setDelayPerUnit(0.1f);
	animation3->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(
					"enemy3_down1.png"));
	animation3->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(
					"enemy3_down2.png"));
	animation3->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(
					"enemy3_down3.png"));
	animation3->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(
					"enemy3_down4.png"));
	animation3->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(
					"enemy3_down5.png"));
	animation3->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(
					"enemy3_down6.png"));

	AnimationCache::getInstance()->addAnimation(animation1, "Enemy1Blowup");
	AnimationCache::getInstance()->addAnimation(animation2, "Enemy2Blowup");
	AnimationCache::getInstance()->addAnimation(animation3, "Enemy3Blowup");

}


