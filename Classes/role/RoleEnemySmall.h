/*
 * RoleEnemySmall.h
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#ifndef ROLEENEMYSMALL_H_
#define ROLEENEMYSMALL_H_

#include "Role.h"

class RoleEnemySmall: public Role, public Sprite {
public:
	RoleEnemySmall();
	virtual ~RoleEnemySmall();

	// from Role
	virtual void hit(Role* target);
	virtual void gotDamage(int damage);
	virtual void gotSupply(int supply);
	virtual void down();

	virtual bool init();
	CREATE_FUNC (RoleEnemySmall);
};

#endif /* ROLEENEMYSMALL_H_ */


