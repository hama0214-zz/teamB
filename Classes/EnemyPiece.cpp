//
//  EnemyPiece.cpp
//  teamB
//
//  Created by Yuto Yoshinari on 2014/01/26.
//
//

#include "EnemyPiece.h"

/**
 * FieldPieceを生成するクラスメソッド
 * @static
 * @param {Variables::PIECE_IMAGE} image
 * @return {FieldPiece*}
 */
EnemyPiece* EnemyPiece::create(Variables::PIECE_IMAGE image) {
    EnemyPiece *pobSprite = new EnemyPiece();
    if (pobSprite && pobSprite->initWithFile(pobSprite->getPszFileName(image))) {
        pobSprite->pieceImage = image;
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

/**
 * 対象の画像名を返すメソッド
 * @private
 * @param {Variables::PIECE_IMAGE} image
 * @return {const char*}
 */
const char* EnemyPiece::getPszFileName(Variables::PIECE_IMAGE image) {
    const char* pszFileName;
    switch (image) {
        case Variables::ENEMY_PIECE_IMAGE_0:
            pszFileName = "Icon-72.png";
            break;
        default:
            break;
    }
    return pszFileName;
}

/**
 * コンストラクタ
 */
EnemyPiece::EnemyPiece() {
    isAlive = true;
    pieceType = Variables::ENEMY_PIECE;
}

/**
 * 死ぬ際に呼ばれるメソッド
 */
void EnemyPiece::die() {
    isAlive = false;
    
    // 見た目上画面から消す
    CCScaleTo* action1 = CCScaleTo::create(1, 0.0f);
    CCMoveBy* action2 = CCMoveBy::create(1, ccp(0,40));
    
    CCSequence* sequence = CCSequence::createWithTwoActions(action1, action2);
    runAction(sequence);
}





