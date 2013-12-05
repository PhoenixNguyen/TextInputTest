#include "DemoTextInput.h"

USING_NS_CC;

cocos2d::Layer* DemoTextInput::mLayer = NULL;
TextInputTestScene* DemoTextInput::mTextInput = NULL;

Scene* DemoTextInput::scene()
{
	Scene* scene = Scene::create();
	DemoTextInput* layer = DemoTextInput::create();
	// mLayer->init();
  scene->addChild(mLayer, 0);
	scene->addChild(layer, 1);
  return scene;

}

DemoTextInput* DemoTextInput::create()
{
	mTextInput = new TextInputTestScene();
	mLayer = mTextInput->runThisTest();
	//mLayer->init();

	DemoTextInput* layer = new DemoTextInput();
	//return (DemoTextInput*)layer;

  if( layer && layer->init())
  {
    layer->autorelease();
		//mTextInput->autorelease();
    return layer;
  }
  else
  {
		CC_SAFE_DELETE(mTextInput);
    CC_SAFE_DELETE(layer);
    return NULL;
  }
}

bool DemoTextInput::init()
{
  /*if(!Layer::create())
    return false;*/

	/////////////////////////////////////////////////////////////////////////////////////////
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	MenuItemImage *closeItem = MenuItemImage::create(
																			"CloseNormal.png",
																			"CloseSelected.png",
																			CC_CALLBACK_1(DemoTextInput::getText, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
															origin.y + closeItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	Menu* menu = Menu::create(closeItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);
	/////////////////////////////////////////////////////////////////////////////////////////

	

	Sprite* sp = Sprite::create("CloseNormal.png");
	sp->setPosition(Point(200, 260));
	addChild(sp, 2);
	return true;
}

void DemoTextInput::getText(cocos2d::Object* pSender)
{
	CCLog("TEXT FIELD TTF: %s", mTextInput->getText());
}