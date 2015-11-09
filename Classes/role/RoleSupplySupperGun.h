/*
 * RoleSupplySupperGun.h
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#ifndef ROLESUPPLYSUPPERGUN_H_
#define ROLESUPPLYSUPPERGUN_H_

#include "Role.h"

class RoleSupplySupperGun: public Role, public Sprite {
public:
	RoleSupplySupperGun();
	virtual ~RoleSupplySupperGun();

	// from Role
	virtual void hit(Role* target);
	virtual void gotDamage(int damage);
	virtual void gotSupply(int supply);
	virtual void down();

	virtual bool init();
	CREATE_FUNC (RoleSupplySupperGun);
};

#endif /* ROLESUPPLYSUPPERGUN_H_ */

