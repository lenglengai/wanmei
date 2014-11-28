#!/usr/bin/env python
#-*- coding:utf-8 -*-

import os
import platform
import buildbase

class BuildCMake(buildbase.BuildBase):

    @staticmethod
    def getName():
        return 'cemdr'

    def interName(self):
        return BuildCMake.getName()
    
    def __init__(self, nWorkspace, nProject):
        self.mWorkspace = nWorkspace
        self.mProject = nProject
        self.mMake = False
        self.mCMake = False
        self.mBuild = False
        self.__initChdir()
        self.__initSource()
        
    def __initChdir(self):
        cmdPath = '../%s/build/%s/' % (self.mWorkspace, self.mProject)
        buildbase.BuildBase.runChdir(self, cmdPath)

    def __initSource(self):
        if 'journey' == self.mProject:
            self.mSource = '../../../cmake/build-cmake/journey/'
        else:
            self.mSource = '../../../cmake/'
        self.mSource = os.path.abspath(self.mSource)
        
    def insertBuildParameter(self, nBuildParameter):
        sysName = platform.system()
        if 'Windows' == sysName:
            if 'e' == nBuildParameter:
                self.mPlatform = 'Visual Studio 12 2013'
                self.mCMake = True
            if 'c' == nBuildParameter:
                self.mPlatform = 'NMake Makefiles'
                self.mMake = True
                self.mCMake = True
        elif 'Darwin' == sysName:
            if 'e' == nBuildParameter:
                self.mPlatform = 'Xcode'
                self.mCMake = True
            if 'c' == nBuildParameter:
                self.mPlatform = 'Unix Makefiles'
                self.mMake = True
                self.mCMake = True
        else:
            if 'e' == nBuildParameter:
                self.mPlatform = 'Unix Makefiles'
                self.mMake = True
                self.mCMake = True
            if 'c' == nBuildParameter:
                self.mPlatform = 'Unix Makefiles'
                self.mMake = True
                self.mCMake = True
        if 'm' == nBuildParameter:
            self.mMake = True
        if 'd' == nBuildParameter:
            self.mDebug = 'DEBUG'
            self.mBuild = True
        if 'r' == nBuildParameter:
            self.mDebug = 'RELEASE'
            self.mBuild = True
            
    def runBuild(self):
        if True == self.mCMake:
            cmakeCmd = 'cmake %s -G\"%s\" -D__WORKSPACE__=%s -D__PROJECT__=%s' % (self.mSource, self.mPlatform, self.mWorkspace, self.mProject)
            buildbase.BuildBase.interBuild(self, cmakeCmd)
        if True == self.mBuild:
            makeCmd = 'make'
            sysName = platform.system()
            if 'Windows' == sysName:
                if False == self.mMake:
                    makeCmd = 'msbuild %s.sln  /p:Configuration=%s' % (self.mProject, self.mDebug)
                else:
                    makeCmd = 'nmake'
            elif 'Darwin' == sysName:
                if False == self.mMake:
                    makeCmd = 'xcodebuild -project %s.xcodeproj -configuration %s' % (self.mProject, self.mDebug)
            else:
                makeCmd = 'make'
            buildbase.BuildBase.interBuild(self, makeCmd)

