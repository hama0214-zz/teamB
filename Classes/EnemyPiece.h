//
//  EnemyPiece.h
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
    Variables::PIECE_TYPE  pieceType;
    Variables::PIECE_IMAGE pieceImage;
    bool isAlive;
    
    const char* getPszFileName(Variables::PIECE_IMAGE image);
    Variables::PIECE_TYPE getPieceType() const;
    void hitPlayer();
    bool getIsLive() const;
    const CCRect& getRect(const CCPoint& mapPosition);
public:
    CCRect rect;
    
    static EnemyPiece* create(Variables::PIECE_IMAGE image);
    void createEnemy();
    EnemyPiece();
    void die();
};

#endif /* defined(__teamB__EnemyPiece__) */
