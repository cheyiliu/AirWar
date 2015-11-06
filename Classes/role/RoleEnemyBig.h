/*
 * RoleEnemyBig.h
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#ifndef ROLEENEMYBIG_H_
#define ROLEENEMYBIG_H_

#include "Role.h"

class RoleEnemyBig: public Role, public Sprite {
public:
	RoleEnemyBig();
	virtual ~RoleEnemyBig();

	// from Role
	virtual void hit(Role* target);
	virtual void gotDamage(int damage);
	virtual void gotSupply(int supply);
	virtual void down();

	virtual bool init();
	CREATE_FUNC (RoleEnemyBig);
};

#endif /* ROLEENEMYBIG_H_ */

