#!/usr/bin/env python
#-*- coding:utf-8 -*-

import os
import platform
import buildbase

class BuildStart(buildbase.BuildBase):

    @staticmethod
    def getName():
        return 's'

    def interName(self):
        return BuildClean.getName()
    
    def __init__(self, nWorkspace, nProject):
        self.mWorkspace = nWorkspace
        self.mProject = nProject
        self.__initChdir()
        
    def __initChdir(self):
        cmdPath = '../%s/binary/' % self.mWorkspace
        buildbase.BuildBase.runChdir(self, cmdPath)
        
    def insertBuildParameter(self, nBuildParameter):
        print 'start %s' % self.mProject
        
    def runBuild(self):
        sysName = platform.system()
        cleanCmd = './%s' % self.mProject
        if 'Windows' == sysName:
            cleanCmd = 'start %s.exe' % self.mProject
        buildbase.BuildBase.interBuild(self, cleanCmd)
