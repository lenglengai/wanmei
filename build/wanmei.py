import os
import sys

import buildcmake
import buildide

class Startup():
    
    def __init__(self, nWorkspace, nProject):
        self.mWorkspace = nWorkspace
        self.mProject = nProject
        self.__initChdir()
        

    def __initChdir(self):
        filePath = os.path.abspath(__file__)
        self.mCmdPath = os.path.split(filePath)[0]


    def __initBuild(self, nBuildParameters):
        for i in nBuildParameters:
            self.__insertBuild(i)
            
            
    def __insertBuild(self, nBuildParameter):
        insert = False
        for i in self.mBuildBase:
            if nBuildParameter in i.interName():
                i.insertBuildParameter(nBuildParameter)
                insert = True
                break
        if False == insert:
            buildBase = self.__getBuildBase(nBuildParameter)
            buildBase.insertBuildParameter(nBuildParameter)
            self.mBuildBase.append(buildBase)

        
    def __getBuildBase(self, nName):
        if nName in buildcmake.BuildCMake.getName():
            return buildcmake.BuildCMake(self.mWorkspace, self.mProject)
        elif nName in buildcmake.BuildIDE.getName():
            return buildide.BuildIDE(self.mWorkspace, self.mProject)

        
    def runStart(self, nBuildParameters):
        self.__initBuild(nBuildParameters)
        for i in mBuildBase:
            os.chdir(mCmdPath)
            buildBase.runBuild()
            

    mBuildBase = []
    mWorkspace = ''
    mProject = ''
    mCmdPath = ''
    

if __name__ == '__main__':
    startup = Startup(sys.argv[2], sys.argv[3])
    startup.runStart(sys.argv[1])
