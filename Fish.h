#ifndef FISH_H
#define FISH_H
#pragma once
#include"cocos2d.h"
USING_NS_CC;

typedef enum{
	k_Fish_Type_SmallFish = 0,
	k_Fish_Type_Croaker,
	k_Fish_Type_Count=18,
	k_Fish_Type_AngleFish,
	k_Fish_Type_Amphiprion,	//Ğ¡³óÓã
	k_Fish_Type_PufferS,	//´Ìëà
	k_Fish_Type_Bream,		//À¶É«
	k_Fish_Type_Progy,		//ºìÉ«
	k_Fish_Type_Chelonian,	//ÎÚ¹ê
	k_Fish_Type_Lantern,	//µÆÁıÓã
	k_Fish_Type_Ray,		//Ä§¹íÓã
	k_Fish_Type_Shark,		//À¶öèÓã
	k_Fish_Type_GoldenTrout,
	k_Fish_Type_GShark,		//½ğÉ«öèÓã
	k_Fish_Type_GMarlineFish,
	k_Fish_Type_GrouperFish,
	k_Fish_Type_JadePerch,	//±¦Ê¯Óã
	k_Fish_Type_MarlineFish,
	k_Fish_Type_PufferB,	//pufferÊÜµ½¹¥»÷
	
}FishType;

//using namespace cocos2d;
class Fish :public CCNode
{
public:
	Fish(void);
	virtual ~Fish(void); 
	static Fish *create(FishType type = k_Fish_Type_SmallFish);
	virtual bool init(FishType type = k_Fish_Type_SmallFish);
	int getScore();
	int getSpeed();
	CC_SYNTHESIZE(FishType,_type,Type);

protected:
	CCSprite *_fishSprite;
};
#endif