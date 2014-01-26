#include "GameMaster.h"

using namespace cocos2d;
using namespace std;

void GameMaster::show()
{
    CCString* sString;
    scoreStr = CCString::createWithFormat("%d p", 10);

    materStr = CCString::createWithFormat("%d M", 0);

    materDStr = CCString::createWithFormat("%d M", 0);
    
}