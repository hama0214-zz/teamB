#include "GameMaster.h"

using namespace cocos2d;
using namespace std;

void GameMaster::show()
{
    scoreStr = CCString::createWithFormat("%d p", 0);
    materStr = CCString::createWithFormat("%d M", 0);
    materDStr = CCString::createWithFormat("%d M", 0);
    iPoint = 0;
    iMater = 0;
}
void GameMaster::showPop(int Stat)
{
    CCString *sTmp;
    //Stat = 0 クリア Stat = 1 ストップ Stat = 2 ゲームオーバー
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    pPop = CCSprite::create("popBack.gif");
    pPop->setPosition(ccp(size.width * 0.2, size.height * 0.1));
    pPop->setAnchorPoint(ccp(0.0, 0.0));
    pPop->setScale(3.0);
    
    CCSize popSize = pPop->getContentSize();
    
    popLabel1 = CCLabelTTF::create("Touch Layer", "arial", 24);
    if (popLabel1 != NULL) {
        if (Stat == 0) {
            popLabel1->setColor(ccc3(255, 105, 180));
            popLabel1->setString("ゲームクリア！");
        } else {
            popLabel1->setColor(ccc3(255, 0, 127));
            popLabel1->setString("ゲームオーバー");
        }
        popLabel1->setPosition(ccp(popSize.width * 0.5, popSize.height * 0.8));
    }
    
    popLabel2 = CCLabelTTF::create("Touch Layer", "arial", 18);
    if (popLabel2 != NULL) {
        popLabel2->setColor(ccc3(0, 0, 0));
        popLabel2->setString("距離");
        popLabel2->setPosition(ccp(popSize.width * 0.3, popSize.height * 0.6));
    }
    
    popLabel3 = CCLabelTTF::create("Touch Layer", "arial", 18);
    if (popLabel3 != NULL) {
        popLabel3->setColor(ccc3(200, 0, 0));
        sTmp = CCString::createWithFormat("%d M", iMater);
        popLabel3->setString(sTmp->getCString());
        popLabel3->setPosition(ccp(popSize.width * 0.7, popSize.height * 0.6));
    }
    
    popLabel4 = CCLabelTTF::create("Touch Layer", "arial", 18);
    if (popLabel4 != NULL) {
        popLabel4->setColor(ccc3(0, 0, 0));
        popLabel4->setString("スコア");
        popLabel4->setPosition(ccp(popSize.width * 0.3, popSize.height * 0.4));
    }
    
    popLabel5 = CCLabelTTF::create("Touch Layer", "arial", 18);
    if (popLabel5 != NULL) {
        popLabel5->setColor(ccc3(254, 0, 0));
        sTmp = CCString::createWithFormat("%d P", iPoint);
        popLabel5->setString("65535P");
        popLabel5->setPosition(ccp(popSize.width * 0.7, popSize.height * 0.4));
    }
    
    popBtn = CCSprite::create("pop_btn1.gif");
    popBtn->setPosition(ccp(popSize.width * 0.5, popSize.height * 0.2));
    popBtn->setScale(0.5);
    
    if (popLabel1 != NULL) {
        pPop->addChild(popLabel1);
    }
    if (popLabel2 != NULL) {
        pPop->addChild(popLabel2);
    }
    if (popLabel3 != NULL) {
        pPop->addChild(popLabel3);
    }
    if (popLabel4 != NULL) {
        pPop->addChild(popLabel4);
    }
    if (popLabel5 != NULL) {
        pPop->addChild(popLabel5);
    }
//    pPop->addChild(popBtn);
    
}
