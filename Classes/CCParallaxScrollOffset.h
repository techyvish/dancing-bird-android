//
//  CCParallaxScrollOffset.h
//  ParallaxScrollNodeTest
//
//  Created by Jason Marziani on 3/26/12.
//  Made compatible with Cocos2d-x 2.x by Stefan Nguyen on 7/30/12.
//
//  Copyright (c) 2012 Vinova Pte Ltd. All rights reserved.
//
//  Made compatible with Cocos2d-x 2.x by Stefan Nguyen on 7/30/12.
//

#ifndef ParallaxScrollNodeTest_CCParallaxScrollOffset_h
#define ParallaxScrollNodeTest_CCParallaxScrollOffset_h

// for the subclass of CCLayer, each has to implement the static "create" method
#define LAYER_CREATE_FUNC(layer) \
static layer* create() \
{ \
layer *pRet = new layer(); \
if (pRet && pRet->init()) \
{ \
pRet->autorelease(); \
return pRet; \
} \
else \
{ \
delete pRet; \
pRet = NULL; \
return NULL; \
} \
}

#include "cocos2d.h"
using namespace cocos2d;

class CCParallaxScrollOffset : public cocos2d::CCLayer
{
public:
	virtual bool init();  
	LAYER_CREATE_FUNC(CCParallaxScrollOffset);
    //
    CC_SYNTHESIZE(CCPoint, scrollOffset, ScrollOffset);
    CC_SYNTHESIZE(CCPoint, origPosition, OrigPosition);
    CC_SYNTHESIZE(CCPoint, relVelocity, RelVelocity);
    CC_SYNTHESIZE(CCPoint, ratio, Ratio);
    CC_SYNTHESIZE(CCPoint, buffer, Buffer);
    CC_SYNTHESIZE(CCNode*, theChild, TheChild);
    
    static CCParallaxScrollOffset* scrollWithNode(CCNode *node, CCPoint r, CCPoint p, CCPoint s);
    static CCParallaxScrollOffset* scrollWithNode(CCNode *node, CCPoint r, CCPoint p, CCPoint s, CCPoint v);
    CCParallaxScrollOffset* initWithNode(CCNode *node, CCPoint r, CCPoint p, CCPoint s, CCPoint v);
    CCParallaxScrollOffset* initWithNode(CCNode *node, CCPoint r, CCPoint p, CCPoint s);
};

#endif
