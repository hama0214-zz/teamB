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

    // TODO: ダミーのマップピース。実際にはマップデータをファクトリーに情報を渡してオブジェクトを作る。
    CCSprite* piece1 = CCSprite::create("CloseNormal.png");
    piece1->setPosition(ccp(100, 100));

    CCSprite* piece2 = CCSprite::create("CloseNormal.png");
    piece2->setPosition(ccp(200, 100));

    CCSprite* piece3 = CCSprite::create("CloseNormal.png");
    piece3->setPosition(ccp(300, 100));

    // MapFactoryからピースを生成
    FieldPiece* piece4 = (FieldPiece*)MapPieceFactory::create(Variables::FIELD_PIECE, Variables::FIELD_PIECE_IMAGE_0);
    piece4->setPosition(ccp(400, 100));

    node->addChild(piece1);
    node->addChild(piece2);
    node->addChild(piece3);
    node->addChild(piece4);
}
