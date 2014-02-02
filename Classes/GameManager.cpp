/* 作者: C25 白濱　学 */
//
//  GameManager.cpp
//  ゲーム全体を管理するクラス
// （衝突判定の方法を変えたので今回は結局使わなかった）
//  teamB
//
//  Created by Yuto Yoshinari on 2014/01/26.
//
//

#include "GameManager.h"

int GameManager::PIECE_SIZE = 80;

/**
 * コンストラクタ関数
 */
GameManager::GameManager() {
}

/**
 * 状態を更新するメソッド
 */
void GameManager::updateState() {
    
    // TODO: もしも現在プレイヤーがいる位置の列をまだ取得していなかったら、
    if (true) {
        updateColumn();   // 列情報を更新
        updateColumnH();  // 列の高さを更新
        updateIndexY();   // プレイヤーのY座標（index）を更新
    }
    
    // プレイヤーの状態に応じてメソッドを呼ぶ
    switch (getPlayerState()) {
        
        case RIDE: // プレイヤーがピースの上に乗っている
            onPlayerRide();
            break;
            
        case UP: // プレイヤーが浮いていたら、
            onPlayerUp();
            break;
            
        case HIT: // プレイヤーが何かと衝突していたら、
            onPlayerHit();
            break;
            
        default:
            break;
    }
}

/**
 * 現在プレイヤーがいる位置のMapの列情報を更新するメソッド
 * @private
 */
void GameManager::updateColumn() {
    // TODO: MapからcurrentXの列を取得してcolumnに代入
    
    // 仮で配列を生成
    for (int y = 0; y < 3; y++) {
        column.push_back(Variables::FIELD_PIECE);
    }
    for (int y = 0; y < 6; y++) {
        column.push_back(Variables::NONE_PIECE);
    }
}

/**
 * 現在のMap内の高さ（ピース数）を更新するメソッド
 */
void GameManager::updateColumnH() {
    int height;
    
    for (int y = 0; y < column.size(); y++) {
        Variables::PIECE_TYPE type  = column[y];
        // ピースが存在したら
        if (type != Variables::NONE_PIECE) {
            height++;
        }
    }
    columnH = height;
}

/**
 * プレイヤーのY座標（index）を更新するメソッド
 * @private
 */
void GameManager::updateIndexY() {
    float playerY = getPlayerY();

    indexY = (int)(playerY/PIECE_SIZE);
}

/**
 * プレイヤーのY座標（実際の座標）を取得するメソッド
 * @private
 */
float GameManager::getPlayerY() {
    float playerY;
    CCRect rect = player->getRect();
    playerY = rect.origin.y - rect.size.height/2;
    return playerY;
}

/**
 * プレイヤーの状態を返すメソッド
 * @private
 */
GameManager::PLAYER_STATE GameManager::getPlayerState() {
    float playerY = getPlayerY();
    
    if (columnH * PIECE_SIZE < playerY) {
        return UP;
    }
    if (columnH * PIECE_SIZE > playerY) {
        return HIT;
    }
    return RIDE;
}

/**
 * プレイヤーがピースの上に乗っていた際に呼ばれるメソッド
 * @private
 */
void GameManager::onPlayerRide() {
    Variables::PIECE_TYPE pieceType; // TODO: Mapの一番上のピースのタイプを取得する
    
    switch (pieceType) {
        case Variables::FIELD_PIECE:
            // そのまま
            break;
        /*
        case Variables::ENEMY_PIECE:
            // 敵を消してプレイヤーをジャンプさせる
            break;
        case Variables::ITEM_PIECE:
            // アイテムを消す
            // 着地のY座標を更新する
            // アイテムの効果を発動する
            break;
        */
        default:
            break;
    }

}

/**
 * プレイヤーが浮いていた際に呼ばれるメソッド
 * @private
 */
void GameManager::onPlayerUp() {
    // プレイヤーの着地座標を設定
    assignPlayerEndY();
}

/**
 * プレイヤーが何かと衝突していた際に呼ばれるメソッド
 * @private
 */
void GameManager::onPlayerHit() {
    Variables::PIECE_TYPE pieceType = getHitPieceType(); // TODO: プレイヤーが衝突しているピースのタイプを取得する
    
    switch (pieceType) {
        case Variables::FIELD_PIECE:
            // 死亡
            break;
        /*
        case Variables::ENEMY_PIECE:
            // 死亡
            break;
        case Variables::ITEM_PIECE:
            // アイテムを消す
            // 着地のY座標を更新する
            // アイテムの効果を発動する
            break;
        */
        default:
            break;
    }
}

/**
 * プレイヤーが着地するY座標を設定するメソッド
 * @private
 */
void GameManager::assignPlayerEndY() {
    // TODO: プレイヤーが着地するY座標を設定する
    // float endY = columnH * PIECE_SIZE;
}

/**
 * プレイヤーが乗っているピースのタイプを取得するメソッド
 * @private
 */
Variables::PIECE_TYPE GameManager::getRidePieceType() {
    if (indexY > 0) {
        return column[indexY-1];
    }
    return Variables::NONE_PIECE; // おそらくあり得ない（死亡？）
}

/**
 * プレイヤーが衝突しているピースのタイプを取得するメソッド
 * @private
 */
Variables::PIECE_TYPE GameManager::getHitPieceType() {
    return column[indexY];
}