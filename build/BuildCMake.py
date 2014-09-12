import os

import platform
import buildbase

class BuildCMake(buildbase.BuildBase):

    @staticmethod
    def getName(self):
        return 'me'

    def interName(self):
        return 'me'
    
    def __init__(self, nWorkspace, nProject):
        self.mWorkspace = nWorkspace
        self.mProject = nProject
        self.__initChdir()
        self.__initSource()
        

    def __insertBuild(self, nBuildParameter):
        sysName = platform.system()
        if 'Windows' == sysName:
            if 'e' == nBuildParameter:
                self.mPlatform = 'Visual Studio 12 2013'
            else:
                self.mPlatform = 'NMake Makefiles'
        elif 'Darwin' == sysName:
            if 'e' == nBuildParameter:
                self.mPlatform = 'Xcode'
            else:
                self.mPlatform = 'Unix Makefiles'
        else:
            self.mPlatform = 'Unix Makefiles'
            

    def __initChdir(self):
        cmdPath = '../%s/build/%s/' % (self.mWorkSpace, self.mProject)
        if not os.path.isdir(cmdPath):
            os.mkdir(cmdPath)
        buildbase.BuildBase.runChdir(self, cmdPath)


    def __initSource(self):
        if 'configure' == self.mProject:
            self.mSource = '../../../build/build-cmake/configure/'
        elif 'journey' == self.mProject:
            self.mSource = '../../../build/build-cmake/journey/'
        else:
            self.mSource = '../../../build/build-cmake/source/'
            

    def runBuild(self):
        cmakeCmd = 'cmake %s -G\"%s\" -D__WORKSPACE__=%s -D__PROJECT__=%s' % (self.mSource, self.mPlatform, self.mWorkSpace, self.mProject)
        buildbase.BuildBase.interBuild(self, cmakeCmd)
        

    mWorkSpace = ''
    mPlatform = ''
    mProject = ''
    mSource = ''
    
    
    
