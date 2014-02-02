//
//  EnemyPiece.cpp
//  teamB
//
//  Created by Yuto Yoshinari on 2014/01/26.
//
//

#include "EnemyPiece.h"
#include "MapPieceManager.h"

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
        pobSprite->init();
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
            pszFileName = "empty_piece.png";
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
    rect = CCRectMake(0, 0, MapPieceManager::CELL_WIDTH, MapPieceManager::CELL_HEIGHT);
}

bool EnemyPiece::init() {
    // 親クラスを初期化できているかの確認
    if (!MapPiece::init()) {
        return false;
    }
    
    CCSkeletonAnimation* enemy = CCSkeletonAnimation::createWithFile("dragon.json", "dragon.atlas");
    enemy->setPosition(ccp(40, 20));
    enemy->setScale(-0.15, 0.15); // 左右を反転させている
    enemy->setAnimation("flying", true);
    enemy->timeScale = 1.5f; // 再生スピード。1で等倍。
    addChild(enemy);
    
    return true;
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

Variables::PIECE_TYPE EnemyPiece::getPieceType() const {
    return pieceType;
}

void EnemyPiece::hitPlayer() {
    // 何もしない
    setVisible(false);
}

bool EnemyPiece::getIsLive() const {
    return isAlive;
}

const CCRect& EnemyPiece::getRect(const CCPoint& mapPosition) {
    rect.setRect(getPositionX() + mapPosition.x - MapPieceManager::CELL_WIDTH / 2.0f,
                 getPositionY() - MapPieceManager::CELL_HEIGHT / 2.0f,
                 MapPieceManager::CELL_WIDTH,
                 MapPieceManager::CELL_HEIGHT);
    return rect;
}

