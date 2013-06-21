//
//  BirdNode.cpp
//  SampleiOSGame
//
//  Created by Vishal on 16/06/13.
//
//

#include "BirdNode.h"

BirdNode::BirdNode(CCLayer *parent) {
    createNode("skeleton.json", "bird_anim.atlas");
    parent->addChild(skeletonNode);
}

BirdNode::~BirdNode() {
    
}

void BirdNode::createNode(const char *skeletonDataFile, const char *atlasFile){
    skeletonNode =  CCSkeleton::createWithFile(skeletonDataFile, atlasFile);
    AnimationState_setAnimationByName(skeletonNode->state, "fly", true);
	skeletonNode->timeScale = 1.0f;
	//skeletonNode->debugBones = true;
	skeletonNode->runAction(CCRepeatForever::create(CCSequence::create(CCFadeOut::create(1),
                                                                       CCFadeIn::create(1),
                                                                       CCDelayTime::create(5),
                                                                       NULL)));
	skeletonNode->setRotation(-90);
}

void BirdNode::setPosition(CCPoint p) {
    skeletonNode->setPosition(p);
}

void BirdNode::setZOrder(int z, float zVertex) {
    skeletonNode->setZOrder(z);
    skeletonNode->setVertexZ(zVertex);
}
