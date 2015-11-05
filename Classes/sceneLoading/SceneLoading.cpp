/*
 * SceneLoading.cpp
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#include "SceneLoading.h"
#include "LayerLoading.h"
#include "../sceneGame/SceneGame.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

SceneLoading::SceneLoading() {
	// TODO Auto-generated constructor stub
	mIsMusicReady = false;
}

SceneLoading::~SceneLoading() {
	// TODO Auto-generated destructor stub
}

bool SceneLoading::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Scene::init());
		auto layerLoading = LayerLoading::create();
		CC_BREAK_IF(!layerLoading);
		this->addChild(layerLoading);

		auto preLoadAudioThread = std::thread(&SceneLoading::preloadMusic,
				this);
		preLoadAudioThread.detach();

		schedule(schedule_selector(SceneLoading::checkMusicReady), 1.0f);
		bRet = true;
	} while (0);

	return bRet;
}

void SceneLoading::preloadMusic() {
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(
			"sound/game_music.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
			"sound/bullet.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
			"sound/enemy1_down.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
			"sound/enemy2_down.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
			"sound/enemy3_down.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
			"sound/game_over.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
			"sound/get_bomb.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
			"sound/get_double_laser.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
			"sound/use_bomb.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
			"sound/big_spaceship_flying.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
			"sound/achievement.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
			"sound/out_porp.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
			"sound/button.mp3");

	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(
			"sound/game_music.mp3", true);

	// Set flag
	mIsMusicReady = true;
}

void SceneLoading::checkMusicReady(float dt) {
	if (mIsMusicReady) {
		mIsMusicReady = false;// Anti-reentrant
		auto sceneGame = SceneGame::create();
		auto animateScene = TransitionMoveInB::create(0.5f,sceneGame);
		Director::getInstance()->replaceScene(animateScene);
	}
}
