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
		mLayer->scheduleOnce(CC_SCHEDULE_SELECTOR(RoleManager::doAddHero), 0);
	}
}

void RoleManager::stopAddHero() {
	// do nothing as just schedule once
}

void RoleManager::startAddEnemySmall() {
	if (mLayer != nullptr) {
		mLayer->schedule(CC_SCHEDULE_SELECTOR(RoleManager::doAddEnemySmall), 0);
	}
}

void RoleManager::stopAddEnemySmall() {
	if (mLayer != nullptr) {
		mLayer->unschedule(CC_SCHEDULE_SELECTOR(RoleManager::doAddEnemySmall));
	}
}

void RoleManager::startAddEnemyMiddle() {
	if (mLayer != nullptr) {
		mLayer->schedule(CC_SCHEDULE_SELECTOR(RoleManager::doAddAddEnemyMiddle),
				0);
	}
}

void RoleManager::stopAddEnemyMiddle() {
	if (mLayer != nullptr) {
		mLayer->unschedule(
				CC_SCHEDULE_SELECTOR(RoleManager::doAddAddEnemyMiddle));
	}
}

void RoleManager::startAddEnemyBig() {
	if (mLayer != nullptr) {
		mLayer->schedule(CC_SCHEDULE_SELECTOR(RoleManager::doAddEnemyBig),
				0);
	}
}

void RoleManager::stopAddEnemyBig() {
	if (mLayer != nullptr) {
		mLayer->unschedule(CC_SCHEDULE_SELECTOR(RoleManager::doAddEnemyBig));
	}
}

void RoleManager::startAddSupplyDoubleGun() {
	if (mLayer != nullptr) {
		mLayer->schedule(
				CC_SCHEDULE_SELECTOR(RoleManager::doAddSupplyDoubleGun), 0);
	}
}

void RoleManager::stopAddSupplyDoubleGun() {
	if (mLayer != nullptr) {
		mLayer->unschedule(
				CC_SCHEDULE_SELECTOR(RoleManager::doAddSupplyDoubleGun));
	}
}

void RoleManager::startAddSupplySuperGun() {
	if (mLayer != nullptr) {
		mLayer->schedule(CC_SCHEDULE_SELECTOR(RoleManager::doAddSupplySuperGun),
				0);
	}
}

void RoleManager::stopAddSupplySuperGun() {
	if (mLayer != nullptr) {
		mLayer->unschedule(
				CC_SCHEDULE_SELECTOR(RoleManager::doAddSupplySuperGun));
	}
}

void RoleManager::startAddBulletBlue() {
	if (mLayer != nullptr) {
		mLayer->schedule(CC_SCHEDULE_SELECTOR(RoleManager::doAddBulletBlue), 0);
	}
}

void RoleManager::stopAddBulletBlue() {
	if (mLayer != nullptr) {
		mLayer->unschedule(CC_SCHEDULE_SELECTOR(RoleManager::doAddBulletBlue));
	}
}

void RoleManager::startAddBulletYellow() {
	if (mLayer != nullptr) {
		mLayer->schedule(CC_SCHEDULE_SELECTOR(RoleManager::doAddBulletYellow),
				0);
	}
}

void RoleManager::stopAddBulletYellow() {
	if (mLayer != nullptr) {
		mLayer->unschedule(
				CC_SCHEDULE_SELECTOR(RoleManager::doAddBulletYellow));
	}
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
}

void RoleManager::doAddAddEnemyMiddle(float dt) {
}

void RoleManager::doAddEnemyBig(float dt) {
}

void RoleManager::doAddSupplyDoubleGun(float dt) {
}

void RoleManager::doAddSupplySuperGun(float dt) {
}

void RoleManager::doAddBulletBlue(float dt) {
}

void RoleManager::doAddBulletYellow(float dt) {
}

