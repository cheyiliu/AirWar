/*
 * LayerOfBg.cpp
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#include "LayerOfBg.h"

LayerOfBg::LayerOfBg() {
	// TODO Auto-generated constructor stub

}

LayerOfBg::~LayerOfBg() {
	// TODO Auto-generated destructor stub
}

bool LayerOfBg::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Layer::init());

		mBg1 = Sprite::createWithSpriteFrameName("background.png");
		mBg1->setAnchorPoint(Point::ZERO);
		mBg1->setPosition(Point::ZERO);
		mBg1->getTexture()->setAliasTexParameters();
		this->addChild(mBg1);

		mBg2 = Sprite::createWithSpriteFrameName("background.png");
		mBg2->setAnchorPoint(Point::ZERO);
		mBg2->setPosition(Point(0, mBg2->getContentSize().height - 2));
		mBg2->getTexture()->setAliasTexParameters();
		this->addChild(mBg2);

		this->schedule(schedule_selector(LayerOfBg::updateBg), 0.01f);

		bRet = true;
	} while (0);

	return bRet;
}

void LayerOfBg::updateBg(float dt) {
	mBg1->setPositionY(int(mBg1->getPositionY()) - 2);
	mBg2->setPositionY(
			int(mBg1->getPositionY()) + int(mBg1->getContentSize().height) - 2);
	if (mBg2->getPositionY() == 0) {
		mBg1->setPositionY(0);
	}
}
