/*
 * RoleManager.cpp
 *
 *  Created on: 2015-11-9
 *      Author: hsy
 */

#include "RoleManager.h"
#include "Role.h"
#include "RoleHeroPlane.h"
#include "RoleEnemySmall.h"
#include "RoleEnemyMiddle.h"
#include "RoleEnemyBig.h"
#include "RoleSupplySupperGun.h"
#include "RoleSupplyDoubleGun.h"
#include "RoleBulletBlue.h"
#include "RoleBulletYellow.h"

RoleManager::RoleManager() {
	mLayer = nullptr;
}

RoleManager::~RoleManager() {
	stopAddAll();
	if (mLayer != nullptr) {
		mLayer->release();
		mLayer = nullptr;
	}

	if (mHero != nullptr) {
		mHero->release();
		mHero = nullptr;
	}
}

void RoleManager::startAddAll() {
	startAddHero();

	startAddBulletBlue();
	startAddBulletYellow();

	startAddEnemyBig();
	startAddEnemyMiddle();
	startAddEnemySmall();

	startAddSupplyDoubleGun();
	startAddSupplySuperGun();
}

void RoleManager::stopAddAll() {
	stopAddHero();

	stopAddBulletBlue();
	stopAddBulletYellow();

	stopAddEnemyBig();
	stopAddEnemyMiddle();
	stopAddEnemySmall();

	stopAddSupplyDoubleGun();
	stopAddSupplySuperGun();
}

void RoleManager::registerLayer(Layer* layer) {
	if (layer != nullptr) {
		mLayer = layer;
		mLayer->retain();
	}
}

void RoleManager::unRegisterLayer(Layer* layer) {
	if (mLayer != nullptr && mLayer == layer) {
		stopAddAll();
		mLayer->release();
		mLayer = nullptr;
	}
}

void RoleManager::startAddHero() {
	if (mLayer != nullptr) {
		Director::getInstance()->getScheduler()->schedule(
				schedule_selector(RoleManager::doAddHero),/*SEL_SCHEDULE selector*/
				this,/*Ref *target*/
				0,/*float interval*/
				0,/*unsigned int repeat*/
				0,/*float delay*/
				false/*bool paused*/);
	}
}

void RoleManager::stopAddHero() {
	Director::getInstance()->getScheduler()->unschedule(
			schedule_selector(RoleManager::doAddHero),/*SEL_SCHEDULE selector*/
			this/*Ref *target*/);
}

void RoleManager::startAddEnemySmall() {
	if (mLayer != nullptr) {
		Director::getInstance()->getScheduler()->schedule(
				schedule_selector(RoleManager::doAddEnemySmall),/*SEL_SCHEDULE selector*/
				this,/*Ref *target*/
				0.5f,/*float interval*/
				kRepeatForever,/*unsigned int repeat*/
				0,/*float delay*/
				false/*bool paused*/);
	}
}

void RoleManager::stopAddEnemySmall() {
	Director::getInstance()->getScheduler()->unschedule(
			schedule_selector(RoleManager::doAddEnemySmall),/*SEL_SCHEDULE selector*/
			this/*Ref *target*/);
}

void RoleManager::startAddEnemyMiddle() {
	if (mLayer != nullptr) {
		Director::getInstance()->getScheduler()->schedule(
				schedule_selector(RoleManager::doAddAddEnemyMiddle),/*SEL_SCHEDULE selector*/
				this,/*Ref *target*/
				3,/*float interval*/
				kRepeatForever,/*unsigned int repeat*/
				0,/*float delay*/
				false/*bool paused*/);
	}
}

void RoleManager::stopAddEnemyMiddle() {
	Director::getInstance()->getScheduler()->unschedule(
			schedule_selector(RoleManager::doAddAddEnemyMiddle),/*SEL_SCHEDULE selector*/
			this/*Ref *target*/);
}

void RoleManager::startAddEnemyBig() {
	if (mLayer != nullptr) {
		Director::getInstance()->getScheduler()->schedule(
				schedule_selector(RoleManager::doAddEnemyBig),/*SEL_SCHEDULE selector*/
				this,/*Ref *target*/
				6,/*float interval*/
				kRepeatForever,/*unsigned int repeat*/
				0,/*float delay*/
				false/*bool paused*/);
	}
}

void RoleManager::stopAddEnemyBig() {
	Director::getInstance()->getScheduler()->unschedule(
			schedule_selector(RoleManager::doAddEnemyBig),/*SEL_SCHEDULE selector*/
			this/*Ref *target*/);
}

void RoleManager::startAddSupplyDoubleGun() {
	if (mLayer != nullptr) {
		Director::getInstance()->getScheduler()->schedule(
				schedule_selector(RoleManager::doAddSupplyDoubleGun),/*SEL_SCHEDULE selector*/
				this,/*Ref *target*/
				20,/*float interval*/
				kRepeatForever,/*unsigned int repeat*/
				0,/*float delay*/
				false/*bool paused*/);
	}
}

void RoleManager::stopAddSupplyDoubleGun() {
	Director::getInstance()->getScheduler()->unschedule(
			schedule_selector(RoleManager::doAddSupplyDoubleGun),/*SEL_SCHEDULE selector*/
			this/*Ref *target*/);
}

void RoleManager::startAddSupplySuperGun() {
	if (mLayer != nullptr) {
		Director::getInstance()->getScheduler()->schedule(
				schedule_selector(RoleManager::doAddSupplySuperGun),/*SEL_SCHEDULE selector*/
				this,/*Ref *target*/
				20,/*float interval*/
				kRepeatForever,/*unsigned int repeat*/
				5,/*float delay*/
				false/*bool paused*/);
	}
}

void RoleManager::stopAddSupplySuperGun() {
	Director::getInstance()->getScheduler()->unschedule(
			schedule_selector(RoleManager::doAddSupplySuperGun),/*SEL_SCHEDULE selector*/
			this/*Ref *target*/);
}

void RoleManager::startAddBulletBlue() {
	if (mLayer != nullptr) {
		Director::getInstance()->getScheduler()->schedule(
				schedule_selector(RoleManager::doAddBulletBlue),/*SEL_SCHEDULE selector*/
				this,/*Ref *target*/
				0.2f,/*float interval*/
				30,/*unsigned int repeat*/
				0,/*float delay*/
				false/*bool paused*/);
	}
}

void RoleManager::stopAddBulletBlue() {
	Director::getInstance()->getScheduler()->unschedule(
			schedule_selector(RoleManager::doAddBulletBlue),/*SEL_SCHEDULE selector*/
			this/*Ref *target*/);
}

void RoleManager::startAddBulletYellow() {
	if (mLayer != nullptr) {
		Director::getInstance()->getScheduler()->schedule(
				schedule_selector(RoleManager::doAddBulletYellow),/*SEL_SCHEDULE selector*/
				this,/*Ref *target*/
				0.2f,/*float interval*/
				kRepeatForever,/*unsigned int repeat*/
				0,/*float delay*/
				false/*bool paused*/);
	}
}

void RoleManager::stopAddBulletYellow() {
	Director::getInstance()->getScheduler()->unschedule(
			schedule_selector(RoleManager::doAddBulletYellow),/*SEL_SCHEDULE selector*/
			this/*Ref *target*/);
}

void RoleManager::doAddHero(float dt) {
	if (mLayer != nullptr) {
		auto hero = RoleHeroPlane::create();
		if (hero != nullptr) {
			mHero = hero;
			mHero->retain();
			mLayer->addChild(hero);
		}
	}
}

void RoleManager::doAddEnemySmall(float dt) {
	if (mLayer != nullptr) {
		auto enemy = RoleEnemySmall::create();
		mLayer->addChild(enemy);
	}
}

void RoleManager::doAddAddEnemyMiddle(float dt) {
	if (mLayer != nullptr) {
		auto enemy = RoleEnemyMiddle::create();
		mLayer->addChild(enemy);
	}
}

void RoleManager::doAddEnemyBig(float dt) {
	if (mLayer != nullptr) {
		auto enemy = RoleEnemyBig::create();
		mLayer->addChild(enemy);
	}
}

void RoleManager::doAddSupplyDoubleGun(float dt) {
	if (mLayer != nullptr) {
		auto supplyDouble = RoleSupplyDoubleGun::create();
		mLayer->addChild(supplyDouble);
	}
}

void RoleManager::doAddSupplySuperGun(float dt) {
	if (mLayer != nullptr) {
		auto supplySupper = RoleSupplySupperGun::create();
		mLayer->addChild(supplySupper);
	}
}

void RoleManager::doAddBulletBlue(float dt) {
	if (mLayer != nullptr && mHero != nullptr) {
		Point heroPos = mHero->getPosition();
		Point bulletLeft = Point(heroPos.x - 33, heroPos.y + 35);
		Point bulletRight = Point(heroPos.x + 33, heroPos.y + 35);
		auto bulletBlueLeft = RoleBulletBlue::create(bulletLeft.x,
				bulletLeft.y);
		auto bulletBlueRight = RoleBulletBlue::create(bulletRight.x,
				bulletRight.y);
		mLayer->addChild(bulletBlueLeft);
		mLayer->addChild(bulletBlueRight);
	}
}

void RoleManager::doAddBulletYellow(float dt) {
	if (mLayer != nullptr && mHero != nullptr) {
		Point heroPos = mHero->getPosition();
		Point bulletPosition = Point(heroPos.x,
				heroPos.y + mHero->getContentSize().height / 2);
		auto bulletYellow = RoleBulletYellow::create(bulletPosition.x,
				bulletPosition.y);
		mLayer->addChild(bulletYellow);
	}
}


