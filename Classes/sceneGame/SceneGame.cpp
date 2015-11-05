/*
 * SceneGame.cpp
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#include "SceneGame.h"
#include "LayerOfBg.h"

SceneGame::SceneGame() {
	// TODO Auto-generated constructor stub

}

SceneGame::~SceneGame() {
	// TODO Auto-generated destructor stub
}

bool SceneGame::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Scene::init());
		auto layerBg = LayerOfBg::create();
		CC_BREAK_IF(!layerBg);
		this->addChild(layerBg);
		bRet = true;
	} while (0);

	return bRet;
}
