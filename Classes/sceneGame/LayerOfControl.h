/*
 * LayerOfControl.h
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#ifndef LAYEROFCONTROL_H_
#define LAYEROFCONTROL_H_

#include "cocos2d.h"

USING_NS_CC;

class LayerOfControl: public cocos2d::Layer {
public:
	LayerOfControl();
	virtual ~LayerOfControl();

	virtual bool init();
	CREATE_FUNC (LayerOfControl);

private:
	void menuPauseCallback(Ref* pSender);

private:
	Label* scoreItem;
	MenuItemSprite* pPauseItem;
};

#endif /* LAYEROFCONTROL_H_ */

