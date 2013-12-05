#ifndef __DEMO_TEXT_INPUT__
#define __DEMO_TEXT_INPUT__

#include "cocos2d.h"
#include "TextInputTest.h"

class TextInputTestScene;

class DemoTextInput : public cocos2d::Layer
{
	
	static cocos2d::Layer* mLayer;
	static TextInputTestScene* mTextInput;
public:
	static cocos2d::Scene* scene();
  static DemoTextInput* create();
  virtual bool init();

	void getText(cocos2d::Object* pSender);
};

#endif