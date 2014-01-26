#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "MapPieceManager.h"

class GameScene: public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameScene);
    void ccTouchesBegan(cocos2d::CCSet*,
                        cocos2d::CCEvent*);


private:
    /** 1マス分の距離を何秒で移動するかの定数。 */
    static const float MAP_MOVE_SPEED;

    /** マップの移動アクションのタグ（移動をストップさせるのに使用） */
    static const int TAG_MAP_MOVE_EVENT;

    /** マップ管理オブジェクト */
    MapPieceManager* mapPieceMgr;

    /** マップピースのオブジェクトを設置するノード */
    CCNode* mapNode;

    /** マップ移動開始 */
    void moveStart();

    /** マップの移動停止 */
    void moveStop();
};

#endif //__GAME_SCENE_H__