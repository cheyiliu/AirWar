/*
 * SceneLoading.h
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#ifndef SCENELOADING_H_
#define SCENELOADING_H_

#include "cocos2d.h"

class SceneLoading : public cocos2d::Scene {
public:
	SceneLoading();
	virtual ~SceneLoading();
	virtual bool init();
	CREATE_FUNC(SceneLoading);

private:
	void checkMusicReady(float dt);
	void preloadMusic();

	bool mIsMusicReady;
};

#endif /* SCENELOADING_H_ */
