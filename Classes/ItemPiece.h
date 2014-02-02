//
//  ItemPiece.h
//  アイテムピース（MapPieceクラスを継承して作られている）
// （今回は結局使わなかった）
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
    // privateプロパティ
    Variables::PIECE_TYPE  pieceType;
    Variables::PIECE_IMAGE pieceImage;
    CCRect rect;
    bool isUsed;

    // privateメソッド
    const char* getPszFileName(Variables::PIECE_IMAGE image);
    
public:
    // publicメソッド
    ItemPiece();
    static ItemPiece* create(Variables::PIECE_IMAGE image);
    void use();
    Variables::PIECE_TYPE getPieceType() const;
    void hitPlayer();
    bool getIsLive() const;
    const CCRect& getRect(const CCPoint& mapPosition);
};

#endif /* defined(__teamB__ItemPiece__) */
