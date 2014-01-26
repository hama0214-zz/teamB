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
    /** マップ管理オブジェクト */
    MapPieceManager* mapPieceMgr;

    /** マップピースのオブジェクトを設置するノード */
    CCNode* mapNode;
};

#endif //__GAME_SCENE_H__