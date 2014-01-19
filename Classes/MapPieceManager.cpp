//
//  MapPieceManager.cpp
//  teamB
//
//  Created by cocos2d-x on 2014/01/19.
//
//

#include "MapPieceManager.h"

MapPieceManager::~MapPieceManager() {}

MapPieceManager* MapPieceManager::create() {
    MapPieceManager *ret = new MapPieceManager();
    if (ret != NULL && ret->init()) {
        ret->autorelease();
        return ret;
    }

    CC_SAFE_DELETE(ret);
    return NULL;
}

bool MapPieceManager::init() {
    return true;
}

void MapPieceManager::makeMapForNode(CCNode* node) {
    CCAssert(node != NULL, "指定されたノードが存在しない。");

    CCSprite* piece1 = CCSprite::create("CloseNormal.png");
    CCSprite* piece2 = CCSprite::create("CloseNormal.png");
    CCSprite* piece3 = CCSprite::create("CloseNormal.png");

    node->addChild(piece1);
    node->addChild(piece2);
    node->addChild(piece3);
}
