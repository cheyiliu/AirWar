/*
 * SceneLoading.cpp
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#include "SceneLoading.h"
#include "LayerLoading.h"

SceneLoading::SceneLoading() {
	// TODO Auto-generated constructor stub

}

SceneLoading::~SceneLoading() {
	// TODO Auto-generated destructor stub
}

bool SceneLoading::init(){
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!Scene::init());
		auto layerLoading = LayerLoading::create();
		CC_BREAK_IF(!layerLoading);
		this->addChild(layerLoading);
		bRet = true;
	} while (0);

	return bRet;
}
