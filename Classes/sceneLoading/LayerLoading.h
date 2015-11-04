/*
 * LayerLoading.h
 *
 *  Created on: 2015-10-29
 *      Author: hsy
 */

#ifndef LAYERLOADING_H_
#define LAYERLOADING_H_

#include "cocos2d.h"

class LayerLoading : public cocos2d::Layer  {
public:
	LayerLoading();
	virtual ~LayerLoading();
	virtual bool init();
	CREATE_FUNC(LayerLoading);
};

#endif /* LAYERLOADING_H_ */
