//
//  MapPieceFactory.h
//  teamB
//
//  Created by cocos2d-x on 2014/01/19.
//
//

#ifndef __teamB__MapPieceFactory__
#define __teamB__MapPieceFactory__

#include "cocos2d.h"
#include "Variables.h"
#include "MapPiece.h"
#include "FieldPiece.h"

USING_NS_CC;

class MapPieceFactory {
public:
    static MapPiece* create(Variables::PIECE_TYPE type, const char* pszFileName);
};

#endif /* defined(__teamB__MapPieceFactory__) */
