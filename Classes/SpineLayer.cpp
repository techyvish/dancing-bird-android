//
//  SpineLayer.cpp
//  SampleiOSGame
//
//  Created by Vishal on 15/06/13.
//
//

#include "SpineLayer.h"
#include "BirdNode.h"
#include "CloudEmitter.h"

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
    CCSprite* grossini2 = CCSprite::create("Ocean/ocean.png");

    CCSprite* boat1 = CCSprite::create("Ocean/boat.png");
    boat1->setRotation(-90);
    
    CCActionInterval* lens = CCLens3D::create(0, CCSize(5,5), ccp(240,160), 2);
    CCActionInterval* waves = CCWaves3D::create(20, CCSize(10,10), 8, 6);
    CCActionInterval* lens2 = CCLens3D::create(0, CCSize(5,5), ccp(300,300), 2);
    
    
    parallex = CCParallaxNode::create();
    parallexScroll = CCParallaxScrollNode::create();
    parallexScroll->addInfiniteScrollXWithZ(0, ccp(1.,0.2), ccp(0,0), grossini,grossini2, NULL);
    
//    float speedMountainX = 1.5; //this->randomValueBetween(0.15f,0.25f);
//    CCSize screen = CCDirector::sharedDirector()->getWinSize();
//    CCPoint pos = ccp(this->randomValueBetween(0, grossini->getContentSize().width * 2), this->randomValueBetween(screen.height*0.1f,screen.height*0.25f));
//    parallexScroll->addChild(boat1, 2, ccp(speedMountainX,.015f), pos,ccp(grossini->getContentSize().width * 2, 0));
    
    parallexScroll->runAction(CCRepeatForever::create((CCSequence*)CCSequence::create(waves, lens, lens2 ,NULL ) ) );
    addChild(parallexScroll,-1);
    
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
    
    CloudEmitter *cloud = new CloudEmitter();
    cloud->startCouldAtLocation(this,ccp(-10,windowSize.height));
    cloud->startCouldAtLocation(this,ccp(windowSize.width/2,-10));
    delete cloud;
    
    
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
        for ( int i = 0 ; i < birdArray->count() ; i++ ){
            BirdNode *bird = (BirdNode *)birdArray->objectAtIndex(i);
            bird->setPosition(location);
        }
    
    }
}

void SpineLayer::ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event) {
    
}

void SpineLayer::update(float dt) {
    parallexScroll->updateWithVelocity(ccp(4.,0), dt);
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

float SpineLayer::randomValueBetween(float low, float high)
{
    return (((float) arc4random() / 0xFFFFFFFFu) * (high - low)) + low;
}
