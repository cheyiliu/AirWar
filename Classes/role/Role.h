/*
 * Role.h
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#ifndef ROLE_H_
#define ROLE_H_

class Role {
public:
	Role();
	virtual ~Role();

	virtual void hit(Role* target) = 0;
	virtual void gotDamage(int damage)= 0;
	virtual void gotSupply(int supply)= 0;
	virtual void down()= 0;
};

#endif /* ROLE_H_ */
