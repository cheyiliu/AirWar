/*
 * RoleSupplyDoubleGun.h
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#ifndef ROLESUPPLYDOUBLEGUN_H_
#define ROLESUPPLYDOUBLEGUN_H_

#include "Role.h"

class RoleSupplyDoubleGun: public Role, public Sprite {
public:
	RoleSupplyDoubleGun();
	virtual ~RoleSupplyDoubleGun();

	// from Role
	virtual void hit(Role* target);
	virtual void gotDamage(int damage);
	virtual void gotSupply(int supply);
	virtual void down();

	virtual bool init();
	CREATE_FUNC (RoleSupplyDoubleGun);
};

#endif /* ROLESUPPLYDOUBLEGUN_H_ */

