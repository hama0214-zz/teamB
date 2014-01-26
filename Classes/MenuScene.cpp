#include "Menuscene.h"
#include "GameScene.h"

using namespace cocos2d;
using namespace std;

CCScene* MenuScene::scene()
{
    CCScene* scene = CCScene::create();
    MenuScene* layer = MenuScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool MenuScene::init()
{
    //親クラスwのinitを呼ぶ
    if (!CCLayer::init())
    {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCRect rect;
    
    //背景の準備
    pBG = CCSprite::create("back.jpg");
    pBG->setPosition(ccp(size.width * 0.5, size.height * 0.5));
    this->addChild(pBG);
    
    bgSize = pBG->getContentSize();

    //メニューの設定
    CCSprite* pTi = CCSprite::create("menu_ti.gif");
    pTi->setPosition(ccp(bgSize.width * 0.02, bgSize.height * 0.7));
    pTi->setAnchorPoint(ccp(0.0, 0.0));
    pTi->setScale(2.0);
    pBG->addChild(pTi);
    
    //メインボタンの設定
    pBtn = CCSprite::create("menu_btn0.png");
    pBtn->setPosition(ccp(bgSize.width * 0.4, bgSize.height * 0.2));
    pBtn->setAnchorPoint(ccp(0.0, 0.0));
    pBtn->setScale(1.5);
    pBG->addChild(pBtn);
    
    
    //アニメの表示
    CCSprite* pAniM = CCSprite::create("polara_run_cycle.png");
    sizeM = pAniM->getContentSize();
    
    rect = CCRectMake(0, 0, sizeM.width, sizeM.height/8);
    pAni = CCSprite::create("polara_run_cycle.png", rect);
    pAni->setPosition(ccp(bgSize.width * 0.25, bgSize.height * 1.1));
    pAni->setAnchorPoint(ccp(1.0, 3.0));
    pAni->setScale(1.5);
    
    //スケジュール
    this->schedule(schedule_selector(MenuScene::pAnime), 0.2f);
    
    pBG->addChild(pAni);
    iAni = 0;
    
    //タップイベントを取得する
    setTouchEnabled(true);
    setTouchMode(kCCTouchesOneByOne);
    
    return true;
    
}
bool MenuScene::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    return true;
}
//タップが終了したときの処理
void MenuScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    //タップポイントを取得する
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCPoint touchPoint = pDirector->convertToGL(pTouch->getLocationInView());
    
    CCRect rect;
    if (pBtn != NULL){
        rect= pBtn->boundingBox();
        if (rect.containsPoint(touchPoint))
        {
            pBG->removeChild(pBtn, true);
            pBtn = NULL;
            showStg();
            return;
        }
    }
    if (pBtn1 != NULL){
        rect = pBtn1->boundingBox();
        if (rect.containsPoint(touchPoint))
        {
            CCScene* scene = GameScene::scene();
            CCTransitionFadeBL* tran = CCTransitionFadeBL::create(1, scene);
            CCDirector::sharedDirector()->replaceScene(tran);
            return;
        }
    }
    if (pBtn2 != NULL){
        rect = pBtn2->boundingBox();
        if (rect.containsPoint(touchPoint))
        {
            CCScene* scene = GameScene::scene();
            CCTransitionFlipY* tran = CCTransitionFlipY::create(1, scene);
            CCDirector::sharedDirector()->replaceScene(tran);
            return;
        }
    }
    if (pBtn3 != NULL){
        rect = pBtn3->boundingBox();
        if (rect.containsPoint(touchPoint))
        {
            CCScene* scene = GameScene::scene();
            CCTransitionCrossFade* tran = CCTransitionCrossFade::create(1, scene);
            CCDirector::sharedDirector()->replaceScene(tran);
            return;
        }
    }
    if (pBtn4 != NULL){
        rect = pBtn4->boundingBox();
        if (rect.containsPoint(touchPoint))
        {
            CCScene* scene = GameScene::scene();
            CCTransitionRotoZoom* tran = CCTransitionRotoZoom::create(1, scene);
            CCDirector::sharedDirector()->replaceScene(tran);
            return;
        }
    }
    
    return;
}

void MenuScene::showStg()
{
    //ボタンの設定
    pBtn1 = CCSprite::create("menu_btn1.gif");
    pBtn1->setPosition(ccp(bgSize.width * 0.3, bgSize.height * 0.4));
    pBtn1->setAnchorPoint(ccp(0.0, 0.0));
    pBtn1->setScale(1.5);
    pBG->addChild(pBtn1);
    pBtn2 = CCSprite::create("menu_btn2.gif");
    pBtn2->setPosition(ccp(bgSize.width * 0.65, bgSize.height * 0.4));
    pBtn2->setAnchorPoint(ccp(0.0, 0.0));
    pBtn2->setScale(1.5);
    pBG->addChild(pBtn2);
    pBtn3 = CCSprite::create("menu_btn3.gif");
    pBtn3->setPosition(ccp(bgSize.width * 0.3, bgSize.height * 0.2));
    pBtn3->setAnchorPoint(ccp(0.0, 0.0));
    pBtn3->setScale(1.5);
    pBG->addChild(pBtn3);
    pBtn4 = CCSprite::create("menu_btn4.gif");
    pBtn4->setPosition(ccp(bgSize.width * 0.65, bgSize.height * 0.2));
    pBtn4->setAnchorPoint(ccp(0.0, 0.0));
    pBtn4->setScale(1.5);
    pBG->addChild(pBtn4);
}

void MenuScene::pAnime(float fDelta)
{
    CCSize bgSize = pBG->getContentSize();
    pBG->removeChild(pAni, true);
    
    CCRect rect = CCRectMake(0, sizeM.height/8 * iAni, sizeM.width, sizeM.height/8);
    pAni = CCSprite::create("polara_run_cycle.png", rect);
    pAni->setPosition(ccp(bgSize.width * 0.25, bgSize.height * 1.1));
    pAni->setAnchorPoint(ccp(1.0, 3.0));
    pAni->setScale(1.5);
    pBG->addChild(pAni);
    
    iAni++;
    if (iAni > 7) {
        iAni = 0;
    }
}