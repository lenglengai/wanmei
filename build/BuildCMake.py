#!/usr/bin/env python
#-*- coding:utf-8 -*-

import os
import platform
import buildbase

class BuildCMake(buildbase.BuildBase):

    @staticmethod
    def getName():
        return 'me'

    def interName(self):
        return BuildCMake.getName()
    
    def __init__(self, nWorkspace, nProject):
        self.mWorkspace = nWorkspace
        self.mProject = nProject
        self.__initChdir()
        self.__initSource()
        
    def __initChdir(self):
        cmdPath = '../%s/build/%s/' % (self.mWorkspace, self.mProject)
        buildbase.BuildBase.runChdir(self, cmdPath)

    def __initSource(self):
        if 'journey' == self.mProject:
            self.mSource = '../../../build/build-cmake/journey/'
        else:
            self.mSource = '../../../build/build-cmake/source/'
        self.mSource = os.path.abspath(self.mSource)
            
    def insertBuildParameter(self, nBuildParameter):
        sysName = platform.system()
        if 'Windows' == sysName:
            if 'e' == nBuildParameter:
                self.mPlatform = 'Visual Studio 12 2013'
            if 'm' == nBuildParameter:
                self.mPlatform = 'NMake Makefiles'
        elif 'Darwin' == sysName:
            if 'e' == nBuildParameter:
                self.mPlatform = 'Xcode'
            if 'm' == nBuildParameter:
                self.mPlatform = 'Unix Makefiles'
        else:
            self.mPlatform = 'Unix Makefiles'
            
    def runBuild(self):
        cmakeCmd = 'cmake %s -G\"%s\" -D__WORKSPACE__=%s -D__PROJECT__=%s' % (self.mSource, self.mPlatform, self.mWorkspace, self.mProject)
        buildbase.BuildBase.interBuild(self, cmakeCmd)

