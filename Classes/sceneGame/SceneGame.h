/*
 * SceneGame.h
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#ifndef SCENEGAME_H_
#define SCENEGAME_H_

#include "cocos2d.h"

USING_NS_CC;

class SceneGame {
public:
	SceneGame();
	virtual ~SceneGame();

	static Scene* create();
};

#endif /* SCENEGAME_H_ */
