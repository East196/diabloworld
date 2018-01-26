#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import division, print_function, unicode_literals

from cocos.layer import Layer
from cocos.director import director


class LoadingLayer(Layer):
    def __init__(self):
        super(LoadingLayer, self).__init__()
        # CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("loading.plist");
        # CCSpriteFrameCache * cache = CCSpriteFrameCache::sharedSpriteFrameCache();
        size = director.get_window_size()

        # ar = CCArray::create();
        # // ar = CCArray::createWithCapacity(12);
        # char
        # str[64] = {0};
        # for (int i = 1; i <= 12; i++)
        # {
        #     sprintf(str, "load%d.png", i);
        # CCSpriteFrame * frame = cache->spriteFrameByName(str);
        # ar->addObject(frame);
        #
        # }
        # animation = CCAnimation::createWithSpriteFrames(ar, 0.1
        # f);
        # CCSprite * sp = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(
        #     "load1.png"));
        # sp->setPosition(ccp(size.width / 2, size.height / 2));
        # this->addChild(sp);
        # CCActionInterval * action = CCAnimate::create(animation);
        # go = CCRepeatForever::create(action);
        # sp->runAction(go);