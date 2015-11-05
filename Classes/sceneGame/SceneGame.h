/*
 * SceneGame.h
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#ifndef SCENEGAME_H_
#define SCENEGAME_H_

#include "cocos2d.h"

class SceneGame : public cocos2d::Scene {
public:
	SceneGame();
	virtual ~SceneGame();

	virtual bool init();
	CREATE_FUNC(SceneGame);
};

#endif /* SCENEGAME_H_ */
