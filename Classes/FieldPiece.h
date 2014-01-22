//
//  FieldPiece.h
//  teamB
//
//  Created by cocos2d-x on 2014/01/19.
//
//

#ifndef __teamB__FieldPiece__
#define __teamB__FieldPiece__

#include "cocos2d.h"
#include "MapPiece.h"

USING_NS_CC;

class FieldPiece : public MapPiece {
    const char* getPszFileName(Variables::PIECE_IMAGE image);
public:
    static FieldPiece* create(Variables::PIECE_IMAGE image);
};

#endif /* defined(__teamB__FieldPiece__) */
