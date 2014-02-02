//
//  BackgroundLayer.h
//  teamB
//
//  Created by Yuto Yoshinari on 2014/02/02.
//
//

#ifndef __teamB__BackgroundLayer__
#define __teamB__BackgroundLayer__

#include "cocos2d.h"
USING_NS_CC;

class BackgroundLayer : public cocos2d::CCLayer {
    // privateプロパティ
    CCSpriteBatchNode* batchNode;
    CCSize bgSpriteSize;
    int bgIndex;

    // privateメソッド
    void move();
    void updateBackgroundAtIndex(int index);
    void drawBackgroundAtIndex(int index);
    void removeBackgroundAtIndex(int index);
public:
    // pubicメソッド
    virtual bool init();
    void moveStart();
    void moveStop();
    CREATE_FUNC(BackgroundLayer);
};

#endif /* defined(__teamB__BackgroundLayer__) */
