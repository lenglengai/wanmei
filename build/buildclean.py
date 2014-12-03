#!/usr/bin/env python
#-*- coding:utf-8 -*-

import os
import platform
import buildbase

class BuildClean(buildbase.BuildBase):

    @staticmethod
    def getName():
        return 'i'

    def interName(self):
        return BuildClean.getName()
    
    def __init__(self, nWorkspace, nProject):
        self.mWorkspace = nWorkspace
        self.mProject = nProject
        self.__initChdir()
        
    def __initChdir(self):
        cmdPath = '../%s/build/' % self.mWorkspace
        buildbase.BuildBase.runChdir(self, cmdPath)
        
    def insertBuildParameter(self, nBuildParameter):
        print 'run clean %s' % self.mProject
            
    def runBuild(self):
        cleanCmd = 'rm -rf %s' % self.mProject
        buildbase.BuildBase.interBuild(self, cleanCmd)

