/*
 * LayerOfRole.cpp
 *
 *  Created on: 2015-10-28
 *      Author: hsy
 */

#include "LayerOfRole.h"

LayerOfRole::LayerOfRole() {
	// TODO Auto-generated constructor stub

}

LayerOfRole::~LayerOfRole() {
	// TODO Auto-generated destructor stub
}

bool LayerOfRole::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Layer::init());

		bRet = true;
	} while (0);

	return bRet;
}
