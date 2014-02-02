/* 作者: C25 白濱　学 */
//
//  GameManager.h
//  ゲーム全体を管理するクラス
// （衝突判定の方法を変えたので今回は結局使わなかった）
//  teamB
//
//  Created by Yuto Yoshinari on 2014/01/26.
//
//

#ifndef __teamB__GameManager__
#define __teamB__GameManager__

#include "cocos2d.h"
#include "Variables.h"
#include "PlayerSprite.h"

USING_NS_CC;

class GameManager {

    // プレイヤーの状態
    enum PLAYER_STATE {
        RIDE  = 0, // ピースの上に乗っている
        UP    = 1, // 浮いている
        HIT   = 2  // 何かと衝突している
    };
    
    PlayerSprite* player;
    
    // ピースのサイズ
    static int PIECE_SIZE;
    
    int indexY;  // プレイヤーのmap内でのY座標（index）
    int columnH; // column内のピース数
    
    // mapの列情報
    std::vector <Variables::PIECE_TYPE> column;
    
    // メソッド群
    void updateState();
    void updateColumn();
    void updateColumnH();
    void updateIndexY();
    
    float getPlayerY();
    
    PLAYER_STATE getPlayerState();
    void onPlayerRide();
    void onPlayerUp();
    void onPlayerHit();
    
    void assignPlayerEndY();
    Variables::PIECE_TYPE  getRidePieceType();
    Variables::PIECE_TYPE  getHitPieceType();
public:
    GameManager();
};

#endif /* defined(__teamB__GameManager__) */
