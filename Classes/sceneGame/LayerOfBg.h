/*
 * LayerOfBg.h
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#ifndef LAYEROFBG_H_
#define LAYEROFBG_H_

#include "cocos2d.h"

USING_NS_CC;

class LayerOfBg : public cocos2d::Layer {
public:
	LayerOfBg();
	virtual ~LayerOfBg();

	virtual bool init();
	CREATE_FUNC(LayerOfBg);

	void updateBg(float dt);

private:
	Sprite* mBg1;
	Sprite* mBg2;
};

#endif /* LAYEROFBG_H_ */
