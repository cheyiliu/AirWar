/*
 * LayerOfRole.h
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#ifndef LAYEROFROLE_H_
#define LAYEROFROLE_H_

#include "cocos2d.h"

USING_NS_CC;

class LayerOfRole : public cocos2d::Layer {
public:
	LayerOfRole();
	virtual ~LayerOfRole();

	virtual bool init();
	CREATE_FUNC(LayerOfRole);

private:
	void registerPhysicalEventListener();
};

#endif /* LAYEROFROLE_H_ */
