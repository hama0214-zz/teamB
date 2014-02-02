//
//  FieldPiece.h
//  teamB
//
//  Created by Yuto Yoshinari on 2014/01/19.
//
//

#ifndef __teamB__FieldPiece__
#define __teamB__FieldPiece__

#include "cocos2d.h"
#include "MapPiece.h"

USING_NS_CC;

class FieldPiece : public MapPiece {
    Variables::PIECE_TYPE  pieceType;
    Variables::PIECE_IMAGE pieceImage;

    const char* getPszFileName(Variables::PIECE_IMAGE image);
    Variables::PIECE_TYPE getPieceType() const;
    void hitPlayer();
    bool getIsLive() const;
    const CCRect& getRect();
public:
    CCRect rect;

    static FieldPiece* create(Variables::PIECE_IMAGE image);
    FieldPiece();
};

#endif /* defined(__teamB__FieldPiece__) */
