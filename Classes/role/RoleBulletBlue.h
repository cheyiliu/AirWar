/*
 * RoleBulletBlue.h
 *
 *  Created on: 2015-11-6
 *      Author: hsy
 */

#ifndef ROLEBULLETBLUE_H_
#define ROLEBULLETBLUE_H_

#include "Role.h"

class RoleBulletBlue: public Role, public Sprite {
public:
	RoleBulletBlue();
	virtual ~RoleBulletBlue();

	// from Role
	virtual void hit(Role* target);
	virtual void gotDamage(int damage);
	virtual void gotSupply(int supply);
	virtual void down();

	virtual bool init(float x, float y);
	static RoleBulletBlue* create(float x, float y);
};

#endif /* ROLEBULLETBLUE_H_ */
