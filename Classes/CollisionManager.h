//
//  CollisionManager.h
//  teamB
//
//  Created by Kenji on 14/02/02.
//
//

#ifndef __teamB__CollisionManager__
#define __teamB__CollisionManager__

#include "cocos2d.h"

USING_NS_CC;

class GameScene;

class CollisionManager : CCObject
{
public:
    /**
     * クリエイトメソッド。
     * @param ゲームシーン
     * @return インスタンス
     */
    static CollisionManager* create(GameScene* gameScene);
    
private:
    /** ゲームシーン */
    GameScene* m_gameScene;
    
    /** デストラクタ */
    ~CollisionManager();

    /**
     * 初期化。
     * @param gameScene ゲームシーン
     * @return 初期化に成功したかどうか。
     */
    bool init(GameScene* gameScene);

    /** 衝突を検出する */
    void updateCollisionCheck();

};

#endif /* defined(__teamB__CollisionManager__) */
