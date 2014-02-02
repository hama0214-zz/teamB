//
//  CollisionManager.cpp
//  teamB
//
//  Created by C15 川辺兼嗣 on 2014/02/02.
//
//

#include "CollisionManager.h"
#include "GameScene.h"
#include "PlayerSpine.h"
#include "MapPieceManager.h"
#include "MapPiece.h"
#include "EmptyPiece.h"

CollisionManager::~CollisionManager()
{
    m_gameScene = NULL;
}

CollisionManager* CollisionManager::create(GameScene* gameScene)
{
    CollisionManager *ret = new CollisionManager();
    if (ret != NULL && ret->init(gameScene)) {
        ret->autorelease();
        return ret;
    }
    
    CC_SAFE_DELETE(ret);
    return NULL;    
}

bool CollisionManager::init(GameScene *gameScene)
{
    m_gameScene = gameScene;
    return true;
}

void CollisionManager::updateCollisionCheck()
{
    PlayerSpine* playerSpine = m_gameScene->getPlayerSpine();
    CCRect playerRect = playerSpine->getRect();
    CCArray* mapPieces = m_gameScene->getMapMgr()->getAllMapPieces();
    CCPoint mapPosition = m_gameScene->getMapPosition();

    // 画面にあるすべてのピースオブジェクトとプレイヤーの当たり判定を比較し、
    // ぶつかっていれば双方の衝突時のメソッドを呼ぶ
    CCObject* mapPieceObj = NULL;
    CCARRAY_FOREACH(mapPieces, mapPieceObj) {
        MapPiece* mapPiece = NULL;
        mapPiece = dynamic_cast<MapPiece*>(mapPieceObj);
        CCAssert(mapPiece != NULL, "マップピースオブジェクト配列内のデータがマップピースでない。");

        if (!mapPiece->getIsLive() ||                                   // マップピースが活動状態（判定がある状態）か
            !playerRect.intersectsRect(mapPiece->getRect(mapPosition))) // 判定同士がぶつかっているか
        {
            continue;
        }
        
        mapPiece->hitPlayer();
        
        Variables::PIECE_TYPE pieceType = mapPiece->getPieceType();
        playerSpine->hitObject(pieceType);

        // ゲームシーンへ送るイベント
        switch (pieceType) {
            // 敵との衝突
            case Variables::ENEMY_PIECE:
                m_gameScene->moveStop();
                break;

            case Variables::FIELD_PIECE:
            case Variables::ITEM_PIECE:
                // 何もしない
                break;

            default:
                CCAssert(false, "不正なピースタイプを指定された。");
                break;
        }
    }
}
