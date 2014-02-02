//
//  MapPieceFactory.h
//  teamB
//
//  Created by Yuto Yoshinari on 2014/01/19.
//
//

#ifndef __teamB__MapPieceFactory__
#define __teamB__MapPieceFactory__

#include "cocos2d.h"
#include "Variables.h"
#include "FieldPiece.h"
#include "EnemyPiece.h"
#include "ItemPiece.h"

class MapPiece;

USING_NS_CC;

class MapPieceFactory {
public:
    static MapPiece* create(Variables::PIECE_TYPE type, Variables::PIECE_IMAGE image);
};

#endif /* defined(__teamB__MapPieceFactory__) */
