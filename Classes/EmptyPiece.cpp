//
//  EmptyPiece.cpp
//  teamB
//
//  Created by cocos2d-x on 2014/02/02.
//
//

#include "EmptyPiece.h"

EmptyPiece* EmptyPiece::instance = NULL;

EmptyPiece* EmptyPiece::getInstese() {
    if (instance != NULL) {
        return instance;
    }

    instance = create(Variables::FIELD_PIECE_IMAGE_0);
    return  instance;
}

EmptyPiece* EmptyPiece::create(Variables::PIECE_IMAGE image) {
    EmptyPiece *pobSprite = new EmptyPiece();
    if (pobSprite && pobSprite->initWithFile(pobSprite->getPszFileName(image))) {
        pobSprite->pieceImage = image;
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

const char* EmptyPiece::getPszFileName(Variables::PIECE_IMAGE image) {
    return "";
}

EmptyPiece::EmptyPiece() {
    pieceType = Variables::ITEM_PIECE;
    rect = CCRectMake(0, 0, 0, 0);
}

Variables::PIECE_TYPE EmptyPiece::getPieceType() const {
    return Variables::NONE_PIECE;
}

void EmptyPiece::hitPlayer() {
    CCAssert(false, "使用しないメソッド。");
}

bool EmptyPiece::getIsLive() const {
    CCAssert(false, "使用しないメソッド。");
    return false;
}

const CCRect& EmptyPiece::getRect(const CCPoint& mapPosition) {
    return rect;
}
