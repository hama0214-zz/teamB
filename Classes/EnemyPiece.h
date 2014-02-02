//
//  EnemyPiece.h
//  敵のピース（MapPieceクラスを継承して作られている）
//  teamB
//
//  Created by Yuto Yoshinari on 2014/01/26.
//
//

#ifndef __teamB__EnemyPiece__
#define __teamB__EnemyPiece__

#include "cocos2d.h"
#include "MapPiece.h"
#include "spine/spine-cocos2dx.h"

USING_NS_CC;
using namespace cocos2d::extension;

class EnemyPiece : public MapPiece {
    // privateプロパティ
    Variables::PIECE_TYPE  pieceType;
    Variables::PIECE_IMAGE pieceImage;
    bool isAlive;
    CCRect rect;

    // privateメソッド
    const char* getPszFileName(Variables::PIECE_IMAGE image);
    void createEnemy();

public:
    // publicメソッド
    EnemyPiece();
    static EnemyPiece* create(Variables::PIECE_IMAGE image);
    void die();
    Variables::PIECE_TYPE getPieceType() const;
    void hitPlayer();
    bool getIsLive() const;
    const CCRect& getRect(const CCPoint& mapPosition);
};

#endif /* defined(__teamB__EnemyPiece__) */
