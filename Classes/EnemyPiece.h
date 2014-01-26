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

USING_NS_CC;

class EnemyPiece : public MapPiece {
    Variables::PIECE_TYPE  pieceType;
    Variables::PIECE_IMAGE pieceImage;
    bool isAlive;
    
    const char* getPszFileName(Variables::PIECE_IMAGE image);
public:
    static EnemyPiece* create(Variables::PIECE_IMAGE image);
    EnemyPiece();
    void die();
};

#endif /* defined(__teamB__EnemyPiece__) */
