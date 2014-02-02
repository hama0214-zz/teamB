//
//  EmptyPiece.h
//  teamB
//
//  Created by C15 川辺兼嗣 on 2014/02/02.
//
//

#ifndef __teamB__EmptyPiece__
#define __teamB__EmptyPiece__

#include "cocos2d.h"
#include "MapPiece.h"

USING_NS_CC;

/**
 * 空のマップピースデータを表すクラス。
 * シングルトン。
 */
class EmptyPiece : public MapPiece {
    static EmptyPiece* instance;
    Variables::PIECE_TYPE  pieceType;
    Variables::PIECE_IMAGE pieceImage;
    CCRect rect;

    EmptyPiece();

    static EmptyPiece* create(Variables::PIECE_IMAGE image);
    const char* getPszFileName(Variables::PIECE_IMAGE image);
    Variables::PIECE_TYPE getPieceType() const;
    void hitPlayer();
    bool getIsLive() const;
    const CCRect& getRect(const CCPoint& mapPosition);

public:
    static EmptyPiece* getInstese();
};

#endif /* defined(__teamB__EmptyPiece__) */
