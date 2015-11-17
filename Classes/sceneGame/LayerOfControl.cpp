/*
 * LayerOfControl.cpp
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#include "LayerOfControl.h"
#include "SimpleAudioEngine.h"

LayerOfControl::LayerOfControl() {
	// TODO Auto-generated constructor stub

}

LayerOfControl::~LayerOfControl() {
	// TODO Auto-generated destructor stub
}

bool LayerOfControl::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Layer::init());
		auto winSize = Director::getInstance()->getWinSize();

		auto normalPause = Sprite::createWithSpriteFrameName(
				"game_pause_nor.png");
		auto pressedPause = Sprite::createWithSpriteFrameName(
				"game_pause_pressed.png");
		pPauseItem = MenuItemSprite::create(normalPause, pressedPause,
				CC_CALLBACK_1(LayerOfControl::menuPauseCallback, this));
		pPauseItem->setPosition(
				Point(normalPause->getContentSize().width / 2 + 10,
						winSize.height
								- normalPause->getContentSize().height / 2
								- 10));
		auto menuPause = Menu::create(pPauseItem, nullptr);
		menuPause->setPosition(Point::ZERO);
		this->addChild(menuPause, 101);

		scoreItem = Label::createWithBMFont("font/font.fnt", "0");
		scoreItem->setColor(Color3B(143, 146, 147));
		scoreItem->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
		scoreItem->setPosition(
				Point(
						pPauseItem->getPositionX()
								+ normalPause->getContentSize().width / 2 + 5,
						pPauseItem->getPositionY()));
		this->addChild(scoreItem);
		bRet = true;
	} while (0);

	return bRet;
}

void LayerOfControl::menuPauseCallback(Ref* pSender) {
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/button.mp3");
	if (!CCDirector::getInstance()->isPaused()) {
		pPauseItem->setNormalImage(
				Sprite::createWithSpriteFrameName("game_resume_nor.png"));
		pPauseItem->setSelectedImage(
				Sprite::createWithSpriteFrameName("game_resume_pressed.png"));
		CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		CocosDenshion::SimpleAudioEngine::getInstance()->stopAllEffects();
		Director::getInstance()->pause();
	} else {
		pPauseItem->setNormalImage(
				Sprite::createWithSpriteFrameName("game_pause_nor.png"));
		pPauseItem->setSelectedImage(
				Sprite::createWithSpriteFrameName("game_pause_pressed.png"));
		CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		Director::getInstance()->resume();
	}
}

