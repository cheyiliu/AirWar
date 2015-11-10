/*
 * RoleManager.h
 *
 *  Created on: 2015-11-9
 *      Author: hsy
 */

#ifndef ROLEMANAGER_H_
#define ROLEMANAGER_H_

#include "cocos2d.h"

USING_NS_CC;

class RoleManager: public Ref {
public:
	RoleManager();
	virtual ~RoleManager();

public:
	/**
	 * start to add all role
	 */
	void startAddAll();

	/*
	 * stop to add all role
	 */
	void stopAddAll();

	/**
	 * register the layer, in which the role will be add into
	 */
	void registerLayer(Layer* layer);

	/**
	 * unregister the layer
	 */
	void unRegisterLayer(Layer* layer);

	/**
	 * start to add hero
	 */
	void startAddHero();

	/**
	 * stop to add hero
	 */
	void stopAddHero();

	/**
	 * start to add enemy small
	 */
	void startAddEnemySmall();

	/**
	 * stop to add enemy small
	 */
	void stopAddEnemySmall();

	/**
	 * start to add enemy middle
	 */
	void startAddEnemyMiddle();

	/**
	 * stop to add enemy middle
	 */
	void stopAddEnemyMiddle();

	/**
	 * start to add enemy big
	 */
	void startAddEnemyBig();

	/**
	 * stop to add enemy big
	 */
	void stopAddEnemyBig();

	/**
	 * start to add supply double gun
	 */
	void startAddSupplyDoubleGun();

	/**
	 * stop to add supply double gun
	 */
	void stopAddSupplyDoubleGun();

	/**
	 * start to add supply supper gun
	 */
	void startAddSupplySuperGun();

	/**
	 * stop to add supper gun
	 */
	void stopAddSupplySuperGun();

	/**
	 * start to add bullet blue
	 */
	void startAddBulletBlue();

	/**
	 * stop to add bullet blue
	 */
	void stopAddBulletBlue();

	/**
	 * start to add bullet yellow
	 */
	void startAddBulletYellow();

	/**
	 * stop to add bullet yellow
	 */
	void stopAddBulletYellow();

private:
	void doAddHero(float dt);

	void doAddEnemySmall(float dt);
	void doAddAddEnemyMiddle(float dt);
	void doAddEnemyBig(float dt);

	void doAddSupplyDoubleGun(float dt);
	void doAddSupplySuperGun(float dt);

	void doAddBulletBlue(float dt);
	void doAddBulletYellow(float dt);

private:
	Layer* mLayer;
	Sprite* mHero;
};

#endif /* ROLEMANAGER_H_ */
