//
//  SpineLayer.cpp
//  SampleiOSGame
//
//  Created by Vishal on 15/06/13.
//
//

#include "SpineLayer.h"
#include "BirdNode.h"

using namespace cocos2d;
using namespace cocos2d::extension;

SpineLayer::~SpineLayer() {
    
}

SpineLayer::SpineLayer() {

    setTouchEnabled(true);
    setAccelerometerEnabled(true);
    birdArray = new CCArray();
}

void SpineLayer::creatOcean() {
    
    CCNode *parent = new CCNode();
    addChild(parent);
    CCSprite* grossini = CCSprite::create("Ocean/ocean.png");
    grossini->setScale(1.9);
    parent->addChild(grossini);
    CCActionInterval* lens = CCLens3D::create(0, CCSize(5,5), ccp(240,160), 2);
    CCActionInterval* waves = CCWaves3D::create(20, CCSize(10,10), 8, 6);
    CCActionInterval* lens2 = CCLens3D::create(0, CCSize(5,5), ccp(300,300), 2);
    grossini->runAction(CCRepeatForever::create((CCSequence*)CCSequence::create(waves, lens, lens2 ,NULL ) ) );
    parent->setZOrder(0);
    parent->setVertexZ(-100);

}

bool SpineLayer::init() {
    
    CCSize windowSize = CCDirector::sharedDirector()->getWinSize();
	
    if (!CCLayer::init()) return false;
    
    CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this, 0);
    
    BirdNode *bird1 = new BirdNode(this);
    bird1->setPosition(ccp(windowSize.width / 2, windowSize.height / 2));
    bird1->setZOrder(1,10);
    birdArray->addObject(bird1);
 
    BirdNode *bird2 = new BirdNode(this);
    bird2->setPosition(ccp(windowSize.width / 2, windowSize.height / 2));
    bird2->setZOrder(2,100);
    birdArray->addObject(bird2);

    scheduleUpdate();
    
    this->creaetFog();
    this->creatOcean();
    
	return true;
}

void SpineLayer::initPhysics() {
    
}
// adds a new sprite at a given coordinate
void SpineLayer::addNewSpriteAtPosition(cocos2d::CCPoint p) {
    
}

void SpineLayer::draw() {
    
}

void SpineLayer::ccTouchesBegan(cocos2d::CCSet *touches, cocos2d::CCEvent *event) {
    
}

void SpineLayer::ccTouchesMoved(cocos2d::CCSet *touches, cocos2d::CCEvent *event) {
    CCSetIterator it;
    CCTouch *touch;
    
    for (it = touches->begin(); it != touches->end(); it++) {
        touch = (CCTouch *)(*it);
        
        if (!touch) {
            break;
        }
        
        CCPoint location = touch->getLocationInView();
        location = CCDirector::sharedDirector()->convertToGL(location);
        BirdNode *bird = (BirdNode *)birdArray->objectAtIndex(0);
        bird->setPosition(location);
    }
}

void SpineLayer::ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event) {
    
}

void SpineLayer::update(float dt) {
    
}

void SpineLayer::creaetFog(){
    
    CCParticleSmoke * smoke = CCParticleSmoke::create();
    smoke->setPosition(ccp(284,160));
    addChild(smoke);
    smoke->setZOrder(3);

}

// returns a Scene that contains the HelloWorld as the only child
cocos2d::CCScene* SpineLayer::scene() {
    
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // add layer as a child to scene
    CCLayer *layer = new SpineLayer();
    layer->init();
    scene->addChild(layer);
    layer->release();
    
    return scene;
}