//
//  GameManager.h
//  teamB
//
//  Created by cocos2d-x on 2014/01/26.
//
//

#ifndef __teamB__GameManager__
#define __teamB__GameManager__

#include "cocos2d.h"
#include "Variables.h"

USING_NS_CC;

class GameManager {

    // プレイヤーの状態
    enum PLAYER_STATE {
        RIDE  = 0, // ピースの上に乗っている
        UP    = 1, // 浮いている
        HIT   = 2  // 何かと衝突している
    };
    
    // ピースのサイズ
    int PIECE_SIZE = 80;
    
    int indexY;  // プレイヤーのmap内でのY座標（index）
    int columnH; // column内のピース数
    
    // mapの列情報
    std::vector <Variables::PIECE_TYPE> column;
    
    // メソッド群
    void updateState();
    void updateColumn();
    void updateColumnH();
    void updateIndexY();
    
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
