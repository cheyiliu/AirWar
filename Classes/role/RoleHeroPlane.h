/*
 * RoleHeroPlane.h
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#ifndef ROLEHEROPLANE_H_
#define ROLEHEROPLANE_H_

#include "Role.h"

class RoleHeroPlane: public Role, public Sprite {
public:
	RoleHeroPlane();
	virtual ~RoleHeroPlane();

	// from Role
	virtual void hit(Role* target);
	virtual void gotDamage(int damage);
	virtual void gotSupply(int supply);
	virtual void down();

	virtual bool init();
	CREATE_FUNC (RoleHeroPlane);

private:
	void doRemoveSelf();
};

#endif /* ROLEHEROPLANE_H_ */

