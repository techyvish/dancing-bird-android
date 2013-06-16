//
//  BirdNode.h
//  SampleiOSGame
//
//  Created by Vishal on 16/06/13.
//
//

#ifndef __BIRD_NODE_H__
#define __BIRD_NODE_H__

#include <iostream>
#include "Box2D.h"
#include "cocos2d.h"
#include <spine/spine-cocos2dx.h>

using namespace cocos2d;
using namespace cocos2d::extension;

class BirdNode : public CCObject {
    
    CCSkeleton *skeletonNode;
    void creatNode();
public:

    ~BirdNode();
    BirdNode(CCLayer *parent);
    void createNode(const char *skeletonDataFile, const char *atlasFile);
    void setPosition(CCPoint p);
    void setZOrder(int z, float zVertex);

};

#endif /* defined(__BIRD_NODE_H__) */
