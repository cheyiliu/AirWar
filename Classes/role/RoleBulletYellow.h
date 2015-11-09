/*
 * RoleBulletYellow.h
 *
 *  Created on: 2015-11-6
 *      Author: hsy
 */

#ifndef ROLEBULLETYELLOW_H_
#define ROLEBULLETYELLOW_H_

#include "Role.h"

class RoleBulletYellow: public Role, public Sprite {
public:
	RoleBulletYellow();
	virtual ~RoleBulletYellow();

	// from Role
	virtual void hit(Role* target);
	virtual void gotDamage(int damage);
	virtual void gotSupply(int supply);
	virtual void down();

	virtual bool init(float x, float y);
	static RoleBulletYellow* create(float x, float y);
};

#endif /* ROLEBULLETYELLOW_H_ */
