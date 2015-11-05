/*
 * LayerOfRole.cpp
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#include "LayerOfRole.h"
#include "../role/Role.h"

LayerOfRole::LayerOfRole() {
	// TODO Auto-generated constructor stub

}

LayerOfRole::~LayerOfRole() {
	// TODO Auto-generated destructor stub
}

bool LayerOfRole::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Layer::init());
		registerPhysicalEventListener();
		bRet = true;
	} while (0);

	return bRet;
}

void LayerOfRole::registerPhysicalEventListener() {
	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin =
			[](PhysicsContact& contact)
			{
				Role* a = dynamic_cast<Role * >(contact.getShapeA()->getBody()->getNode());
				Role* b = dynamic_cast<Role * >(contact.getShapeB()->getBody()->getNode());
				if(a && b) {
					a->hit(b);
					b->hit(a);
				}

				return true;
			};

	listener->onContactPreSolve = [] (PhysicsContact& contact,
			PhysicsContactPreSolve& solve) {
		return true;
	};

	listener->onContactPostSolve = [] (PhysicsContact& contact,
			const PhysicsContactPostSolve& solve) {
	};

	listener->onContactSeparate = [](PhysicsContact& contact) {
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(
			listener, 1);
}
