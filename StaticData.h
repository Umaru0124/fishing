#pragma once
#include "e:\cocos2d-x-2.2.5\cocos2dx\cocoa\ccobject.h"
class StaticData :
	public CCObject
{
public:
	StaticData(void);
	~StaticData(void);
		static StaticData* sharedStaticData();

    const char* stringValueFromKey(std::string key);
    int intValueForKey(std::string key);
    float floatValueFromKey(std::string key);
    bool booleanFromKey(std::string key);
    cocos2d::CCPoint pointFromKey(std::string key);
    cocos2d::CCRect rectFromKey(std::string key);
    cocos2d::CCSize sizeFromKey(std::string key);
    void purge();
	
protected:
    cocos2d::CCDictionary* _dictionary;
    std::string_staticFileName;
        bool init();


    
};
