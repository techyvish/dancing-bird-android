//
//  SpineLayer.h
//  SampleiOSGame
//
//  Created by Vishal on 15/06/13.
//
//

#ifndef __SPINE_LAYER_H__
#define __SPINE_LAYER_H__

#include "cocos2d.h"
#include "Box2D.h"
#include <spine/spine-cocos2dx.h>

class SpineLayer : public cocos2d::CCLayer  {
    
public:

    
    ~SpineLayer();
    SpineLayer();
    
    
    // returns a Scene that contains the HelloWorld as the only child
    static cocos2d::CCScene* scene();
    
    void initPhysics();
    // adds a new sprite at a given coordinate
    void addNewSpriteAtPosition(cocos2d::CCPoint p);
    
    virtual bool init();
    virtual void draw();
    
    // Touch Handlers
    virtual void ccTouchesBegan( cocos2d::CCSet * touches, cocos2d::CCEvent * event );  // When touches are started.
    virtual void ccTouchesMoved( cocos2d::CCSet * touches, cocos2d::CCEvent * event );  // When touches are moved
    virtual void ccTouchesEnded( cocos2d::CCSet * touches, cocos2d::CCEvent * event );  // When touches are ended.
    
    void update(float dt);
    void creatOcean();
    void creaetFog();

private:
    
    b2World* world;
    cocos2d::CCTexture2D* m_pSpriteTexture; // weak ref
    cocos2d::CCArray *birdArray;
    
};


#endif /* defined(__SPINE_LAYER_H__) */
