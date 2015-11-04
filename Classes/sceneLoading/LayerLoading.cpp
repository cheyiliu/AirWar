/*
 * LayerLoading.cpp
 *
 *  Created on: 2015-10-29
 *      Author: hsy
 */

#include "LayerLoading.h"
USING_NS_CC;

LayerLoading::LayerLoading() {
	// TODO Auto-generated constructor stub

}

LayerLoading::~LayerLoading() {
	// TODO Auto-generated destructor stub
}

bool LayerLoading::init(){
		bool bRet=false;
	do 
	{
		CC_BREAK_IF(!Layer::init());

		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui/shoot_background.plist");
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui/shoot.plist");

		auto winSize = Director::getInstance()->getWinSize();

		auto background = Sprite::createWithSpriteFrameName("background.png");
		background->setPosition(Point(winSize.width/2,winSize.height/2));
		this->addChild(background);

		auto copyright = Sprite::createWithSpriteFrameName("shoot_copyright.png");
		copyright->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
		copyright->setPosition(Point(winSize.width/2,winSize.height/2));
		this->addChild(copyright);

		auto loading = Sprite::createWithSpriteFrameName("game_loading1.png");
		loading->setPosition(Point(winSize.width/2,winSize.height/2-40));
		this->addChild(loading);

		auto animation = Animation::create();
		animation->setDelayPerUnit(0.2f);
		animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("game_loading1.png"));
		animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("game_loading2.png"));
		animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("game_loading3.png"));
		animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("game_loading4.png"));

		auto animate = Animate::create(animation);
		auto repeat = RepeatForever::create(animate);
		loading->runAction(repeat);

		bRet = true;
	} while (0);

	return bRet;
}
