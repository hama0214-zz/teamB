//
//  CollisionManager.cpp
//  teamB
//
//  Created by Kenji on 14/02/02.
//
//

#include "CollisionManager.h"
#include "GameScene.h"
#include "PlayerSpine.h"
#include "MapPieceManager.h"
#include "MapPiece.h"

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
        
        if (!mapPiece->getIsLive() || playerRect.intersectsRect(mapPiece->getRect())) {
            continue;
        }
        
        
        
    }
}
