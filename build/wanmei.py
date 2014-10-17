#!/usr/bin/env python
#-*- coding:utf-8 -*-

import os
import sys

import buildcmake
import buildide
import buildjourney
import buildconfigure

class Startup():
    
    def __init__(self, nWorkspace, nProject):
        self.mWorkspace = nWorkspace
        self.mProject = nProject
        self.__initChdir()
        
    def __initChdir(self):
        filePath = os.path.abspath(__file__)
        self.mCmdPath = os.path.split(filePath)[0]
        os.chdir(self.mCmdPath)

    def runStart(self, nBuildParameters):
        self.__initBuild(nBuildParameters)
        self.__runBuild()

    def __runBuild(self):
        for i in self.mBuildBases:
            i.runBuild()
            os.chdir(self.mCmdPath)
            
    def __initBuild(self, nBuildParameters):
        for i in nBuildParameters:
            self.__insertBuild(i)
            
    def __insertBuild(self, nBuildParameter):
        insert = False
        for i in self.mBuildBases:
            if nBuildParameter in i.interName():
                i.insertBuildParameter(nBuildParameter)
                insert = True
                break
        if False == insert:
            buildBase = self.__getBuildBase(nBuildParameter)
            buildBase.insertBuildParameter(nBuildParameter)
            self.mBuildBases.append(buildBase)
        
    def __getBuildBase(self, nName):
        if nName in buildcmake.BuildCMake.getName():
            return buildcmake.BuildCMake(self.mWorkspace, self.mProject)
        elif nName in buildide.BuildIDE.getName():
            return buildide.BuildIDE(self.mWorkspace, self.mProject)
        elif nName in buildjourney.BuildJourney.getName():
            return buildjourney.BuildJourney(self.mWorkspace, self.mProject)
        elif nName in buildconfigure.BuildConfigure.getName():
            return buildconfigure.BuildConfigure(self.mWorkspace, self.mProject)
			
    mBuildBases = []

if __name__ == '__main__':
    startup = Startup(sys.argv[2], sys.argv[3])
    startup.runStart(sys.argv[1])
