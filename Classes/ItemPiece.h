//
//  ItemPiece.h
//  teamB
//
//  Created by Yuto Yoshinari on 2014/01/26.
//
//

#ifndef __teamB__ItemPiece__
#define __teamB__ItemPiece__

#include "cocos2d.h"
#include "MapPiece.h"

USING_NS_CC;

class ItemPiece : public MapPiece {
    Variables::PIECE_TYPE  pieceType;
    Variables::PIECE_IMAGE pieceImage;
    bool isUsed;

    const char* getPszFileName(Variables::PIECE_IMAGE image);
    Variables::PIECE_TYPE getPieceType() const;
    void hitPlayer();
    bool getIsLive() const;
    const CCRect& getRect(const CCPoint& mapPosition);
public:
    CCRect rect;

    static ItemPiece* create(Variables::PIECE_IMAGE image);
    ItemPiece();
    void use();
};

#endif /* defined(__teamB__ItemPiece__) */
