#include "StaticData.h"


StaticData::StaticData(void)
{
	 _staticDataPath = STATIC_DATA_PATH;
}


StaticData::~StaticData(void)
{
	    CC_SAFE_RELEASE_NULL(_dictionary);
}

StaticData* StaticData::sharedStaticData()
{
    if(_sharedStaticData == NULL){
        _sharedStaticData = new StaticData();
        _sharedStaticData->init();
    }
    return _sharedStaticData;
}
bool StaticData::init()
{
    _dictionary = CCDictionary::createWithContentsOfFile(_staticDataPath.c_str());
    CC_SAFE_RETAIN(_dictionary);
    return true;
}


const char* StaticData::stringFromKey(string key)
{
    return _dictionary->valueForKey(key)->getCString();
}


int StaticData::intValueForKey(string key)
{
    return _dictionary->valueForKey(key)->intValue();
}

float StaticData::floatValueFromKey(string key)
{
    return _dictionary->valueForKey(key)->floatValue();
}


bool StaticData::booleanFromKey(string key)
{
    return _dictionary->valueForKey(key)->boolValue();
}

cocos2d::CCPoint StaticData::pointFromKey(string key)
{
    return CCPointFromString(_dictionary->valueForKey(key)->getCString());
}


cocos2d::CCRect StaticData::rectFromKey(string key)
{
    return CCRectFromString(_dictionary->valueForKey(key)->getCString());
}
cocos2d::CCSize StaticData::sizeFromKey(string key)
{
    return CCSizeFromString(_dictionary->valueForKey(key)->getCString());
}


void StaticData::purge()
{
    CC_SAFE_RELEASE_NULL(_sharedStaticData);
}
