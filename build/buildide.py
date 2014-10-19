#!/usr/bin/env python
#-*- coding:utf-8 -*-

import os
import shutil
import platform
import buildbase

class BuildIDE(buildbase.BuildBase):

    @staticmethod
    def getName():
        return 'uidr'

    def interName(self):
        return BuildIDE.getName()
    
    def __init__(self, nWorkspace, nProject):
        self.mWorkspace = nWorkspace
        self.mProject = nProject
        cmdPath = '../%s/build/%s/' % (nWorkspace, nProject)
        buildbase.BuildBase.runChdir(self, cmdPath)
                
    def insertBuildParameter(self, nBuildParameter):
        if 'u' == nBuildParameter:
            self.mMake = True
        if 'i' == nBuildParameter:
            self.mMake = False
        if 'd' == nBuildParameter:
            self.mDebug = 'DEBUG'
        if 'r' == nBuildParameter:
            self.mDebug = 'RELEASE'
            
    def runBuild(self):
        makeCmd = 'make'
	exePath = ''
	binPath = ''
        sysName = platform.system()
        if 'Windows' == sysName:
	    binPath = '../../binary/%s.exe' % self.mProject
	    binPath = os.path.abspath(binPath)
            if False == self.mMake:
                exePath = '%s/%s.exe' % (self.mDebug, self.mProject)
                makeCmd = 'msbuild %s.sln  /p:Configuration=%s' % (self.mProject, self.mDebug)
            else:
                exePath = '%s.exe' % self.mProject
                makeCmd = 'nmake'
        elif 'Darwin' == sysName:
            if False == self.mMake:
                makeCmd = 'xcodebuild -project %s.xcodeproj -configuration %s' % (self.mProject, self.mDebug)
        else:
            makeCmd = 'make'
        buildbase.BuildBase.interBuild(self, makeCmd)
	shutil.copy(exePath, binPath)
