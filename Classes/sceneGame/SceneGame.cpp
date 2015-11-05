/*
 * SceneGame.cpp
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#include "SceneGame.h"
#include "LayerOfBg.h"
#include "LayerOfRole.h"

USING_NS_CC;

SceneGame::SceneGame() {
	// TODO Auto-generated constructor stub

}

SceneGame::~SceneGame() {
	// TODO Auto-generated destructor stub
}

Scene* SceneGame::create() {
	auto scene = Scene::createWithPhysics();

	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto body = PhysicsBody::createEdgeBox(visibleSize,
			PHYSICSBODY_MATERIAL_DEFAULT, 5.0f);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	edgeNode->setPhysicsBody(body);
	scene->addChild(edgeNode);
	Vect gravity = Vect(0.0f, 0.0f);
	scene->getPhysicsWorld()->setGravity(gravity);

	auto layerBg = LayerOfBg::create();
	scene->addChild(layerBg, 10);

	auto layerRole = LayerOfRole::create();
	scene->addChild(layerRole, 20);

	return scene;
}
