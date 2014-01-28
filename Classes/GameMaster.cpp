#include "GameMaster.h"

using namespace cocos2d;
using namespace std;

void GameMaster::show()
{
    scoreStr = CCString::createWithFormat("%d p", 10);
    
    materStr = CCString::createWithFormat("%d M", 0);
    
    materDStr = CCString::createWithFormat("%d M", 0);
    
}
void GameMaster::showPop(int Stat)
{
    //Stat = 0 クリア Stat = 1 ストップ Stat = 2 ゲームオーバー
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    pPop = CCSprite::create("popBack.gif");
    pPop->setPosition(ccp(size.width * 0.2, size.height * 0.1));
    pPop->setAnchorPoint(ccp(0.0, 0.0));
    pPop->setScale(3.0);
    
    CCSize popSize = pPop->getContentSize();
    
    popLabel1 = CCLabelTTF::create("Touch Layer", "arial", 24);
    popLabel1->setString("ゲームクリア！");
    popLabel1->setPosition(ccp(popSize.width * 0.5, popSize.height * 0.8));
    
    popLabel2 = CCLabelTTF::create("Touch Layer", "arial", 18);
    popLabel2->setString("距離");
    popLabel2->setPosition(ccp(popSize.width * 0.3, popSize.height * 0.6));
    
    popLabel3 = CCLabelTTF::create("Touch Layer", "arial", 18);
    popLabel3->setString("300M");
    popLabel3->setPosition(ccp(popSize.width * 0.7, popSize.height * 0.6));
    
    popLabel4 = CCLabelTTF::create("Touch Layer", "arial", 18);
    popLabel4->setString("スコア");
    popLabel4->setPosition(ccp(popSize.width * 0.3, popSize.height * 0.4));
    
    popLabel5 = CCLabelTTF::create("Touch Layer", "arial", 18);
    popLabel5->setString("65535P");
    popLabel5->setPosition(ccp(popSize.width * 0.7, popSize.height * 0.4));
    
    popBtn = CCSprite::create("pop_btn1.gif");
    popBtn->setPosition(ccp(popSize.width * 0.5, popSize.height * 0.2));
    popBtn->setScale(0.5);
    
    pPop->addChild(popLabel1);
    pPop->addChild(popLabel2);
    pPop->addChild(popLabel3);
    pPop->addChild(popLabel4);
    pPop->addChild(popLabel5);
//    pPop->addChild(popBtn);
    
}
