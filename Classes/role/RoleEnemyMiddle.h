/*
 * RoleEnemyMiddle.h
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#ifndef ROLEENEMYMIDDLE_H_
#define ROLEENEMYMIDDLE_H_

#include "Role.h"

class RoleEnemyMiddle: public Role, public Sprite {
public:
	RoleEnemyMiddle();
	virtual ~RoleEnemyMiddle();

	// from Role
	virtual void hit(Role* target);
	virtual void gotDamage(int damage);
	virtual void gotSupply(int supply);
	virtual void down();

	virtual bool init();
	CREATE_FUNC (RoleEnemyMiddle);
};

#endif /* ROLEENEMYMIDDLE_H_ */

