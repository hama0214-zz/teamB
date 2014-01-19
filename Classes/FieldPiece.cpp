//
//  FieldPiece.cpp
//  teamB
//
//  Created by cocos2d-x on 2014/01/19.
//
//

#include "FieldPiece.h"

FieldPiece* FieldPiece::create(const char* pszFileName) {
    FieldPiece *pobSprite = new FieldPiece();
    if (pobSprite && pobSprite->initWithFile(pszFileName)) {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}