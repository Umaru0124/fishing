#include "FishLayer.h"
#include "Fish.h"
#define FISH_MAX_COUNT 50


FishLayer::FishLayer(void)
{
}

FishLayer::~FishLayer(void)
{
	CC_SAFE_RELEASE_NULL(_fishes);
}
bool FishLayer::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	_fishes = CCArray::createWithCapacity(FISH_MAX_COUNT);

	CC_SAFE_RETAIN(_fishes);
	for (int i = 0; i < FISH_MAX_COUNT; i++)
	{
		int type = CCRANDOM_0_1() * k_Fish_Type_Count - 1;
		CCLOG("FishLayer type=%d",type);
		Fish *fish = Fish::create((FishType)type);
		_fishes->addObject(fish);
	}
	this->schedule(schedule_selector(FishLayer::addFish),3.0f);
	return true;
}

void FishLayer::addFish(float delta)
{
	int addToCount = CCRANDOM_0_1() * 5 + 1;
	int count = 0;
	CCObject *obj;
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCARRAY_FOREACH(_fishes, obj)
	{
		Fish *fish = (Fish *)obj;
		if (fish->isRunning())
		{
			continue;
		}
		count++;
		fish->setPosition(ccp(CCRANDOM_0_1()*winSize.width, CCRANDOM_0_1()*winSize.height));
		this->addChild(fish);
		if (count == addToCount)
		{
			break;
		}
	}
}