#include "GameScene.h"


GameScene::GameScene(void)
{
}


GameScene::~GameScene(void)
{
	CC_SAFE_RELEASE_NULL(_MenuLayer);
}
bool GameScene::init(){
	do{
		if(!!CCScene::init()){
			break;
		}
		_BackgroundLayer=BackgroundLayer::create();
		CC_BREAK_IF(!_BackgroundLayer);
		this ->addChild(_BackgroundLayer);
		_FishLayer=FishLayer::create();
		CC_BREAK_IF(!_FishLayer);
		this ->addChild(_FishLayer);
		_MenuLayer=MenuLayer::create();
		CC_BREAK_IF(!_MenuLayer);
		CC_SAFE_RETAIN(_MenuLayer);
		return true;
	}while(0);
	return false;
}