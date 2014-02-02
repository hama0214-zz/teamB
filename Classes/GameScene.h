#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "MapPieceManager.h"
#include "BackgroundLayer.h"
#include "GameMaster.h"

class PlayerSpine;
class CollisionManager;

class GameScene: public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameScene);
    void ccTouchesBegan(cocos2d::CCSet*,
                        cocos2d::CCEvent*);

    /**
     * プレイヤーを取得する。
     * @return プレイヤー
     * Created by C15 川辺兼嗣
     */
    inline PlayerSpine* getPlayerSpine() const {return playerSpine;}
    
    /**
     * マップマネージャーを取得する。
     * @return マップマネージャー
     * Created by C15 川辺兼嗣
     */
    inline MapPieceManager* getMapMgr() const {return mapPieceMgr;}

    /**
     * マップレイヤーの位置を取得する。
     * @return マップレイヤーの位置
     * Created by C15 川辺兼嗣
     */
    const CCPoint& getMapPosition();

    /**
     * マップの移動停止
     * Created by C15 川辺兼嗣
     */
    void moveStop();

private:
    /** 1マス分の距離を何秒で移動するかの定数。 */
    static const float MAP_MOVE_SPEED;

    /** マップの移動アクションのタグ（移動をストップさせるのに使用） */
    static const int TAG_MAP_MOVE_EVENT;

    /** 衝突判定アクションのタグ（判定をストップさせるのに使用） */
    static const int TAG_COLLISION_CHECK_EVENT;

    /** マップ管理オブジェクト */
    MapPieceManager* mapPieceMgr;

    /** マップピースのオブジェクトを設置するノード */
    CCNode* mapNode;
    
    /** プレイヤー */
    PlayerSpine* playerSpine;

    /** 背景レイヤー */
    BackgroundLayer* bgLayer;
    
    /** 衝突を判定するクラス */
    CollisionManager* colMgr;

    /** 
     * マップ移動開始
     * Created by C15 川辺兼嗣
     */
    void moveStart();

    /** スコア類の更新 */
    void upScore();
    CCLabelTTF* scoreLabel;
    CCLabelTTF* materLabel;
    CCLabelTTF* materDLabel;
    int iMater;
    
    GameMaster* gMaster;
};

#endif //__GAME_SCENE_H__