//
//  EnemyPiece.cpp
//  敵のピース（MapPieceクラスを継承して作られている）
//  teamB
//
//  Created by Yuto Yoshinari on 2014/01/26.
//
//

#include "EnemyPiece.h"
#include "MapPieceManager.h"

/**
 * コンストラクタ
 * @public
 */
EnemyPiece::EnemyPiece() {
    isAlive = true;
    pieceType = Variables::ENEMY_PIECE;
    rect = CCRectMake(0, 0, MapPieceManager::CELL_WIDTH, MapPieceManager::CELL_HEIGHT);
}

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
        pobSprite->createEnemy();
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
    // 背景画像要らないから透明な画像を返す
    return "empty_piece.png";
}

/**
 * 敵のスパインデータを生成するメソッド
 * @private
 */
void EnemyPiece::createEnemy() {
    
    // Spineから敵のデータを生成
    switch (pieceImage) {
        case Variables::ENEMY_PIECE_IMAGE_0: {
            CCSkeletonAnimation* enemy = CCSkeletonAnimation::createWithFile("dragon.json", "dragon.atlas");
            enemy->setPosition(ccp(40, 20));
            enemy->setScale(-0.15, 0.15); // 左右を反転させている
            enemy->setAnimation("flying", true);
            enemy->timeScale = 1.5f; // 再生スピード。1で等倍。
            addChild(enemy);
            break;
        }
        case Variables::ENEMY_PIECE_IMAGE_1: {
            CCSkeletonAnimation* enemy = CCSkeletonAnimation::createWithFile("goblins.json", "goblins.atlas");
            enemy->setSkin("goblin");
            enemy->setToSetupPose();
            enemy->setPosition(ccp(40, -40));
            enemy->setScale(-0.35, 0.35); // 左右を反転させている
            enemy->setAnimation("walk", true);
            enemy->timeScale = 1.5f; // 再生スピード。1で等倍。
            addChild(enemy);
            break;
        }
        case Variables::ENEMY_PIECE_IMAGE_2: {
            CCSkeletonAnimation* enemy = CCSkeletonAnimation::createWithFile("goblins.json", "goblins.atlas");
            enemy->setSkin("goblingirl");
            enemy->setToSetupPose();
            enemy->setPosition(ccp(40, -40));
            enemy->setScale(-0.35, 0.35); // 左右を反転させている
            enemy->setAnimation("walk", true);
            enemy->timeScale = 1.5f; // 再生スピード。1で等倍。
            addChild(enemy);
            break;
        }
        default:
            break;
    }
}

/**
 * 死ぬ際に呼ばれるメソッド
 * @public
 */
void EnemyPiece::die() {
    isAlive = false;
    
    // 見た目上画面から消す
    CCScaleTo* action1 = CCScaleTo::create(1, 0.0f);
    CCMoveBy* action2 = CCMoveBy::create(1, ccp(0,40));
    
    CCSequence* sequence = CCSequence::createWithTwoActions(action1, action2);
    runAction(sequence);
}


/**
 * ピースのタイプを取得するメソッド
 * @public
 */
Variables::PIECE_TYPE EnemyPiece::getPieceType() const {
    return pieceType;
}

/**
 * ピースに当たったときの処理を行うメソッド
 * @public
 */
void EnemyPiece::hitPlayer() {
    // 何もしない
    setVisible(false);
}

/**
 * ピースが生存しているかどうかを返すメソッド
 * @public
 */
bool EnemyPiece::getIsLive() const {
    return isAlive;
}

/**
 * ピースのrect情報を取得する
 * @public
 */
const CCRect& EnemyPiece::getRect(const CCPoint& mapPosition) {
    rect.setRect(getPositionX() + mapPosition.x - MapPieceManager::CELL_WIDTH / 2.0f,
                 getPositionY() - MapPieceManager::CELL_HEIGHT / 2.0f,
                 MapPieceManager::CELL_WIDTH,
                 MapPieceManager::CELL_HEIGHT);
    return rect;
}

