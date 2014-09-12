import platform
import buildbase

class BuildIDE(buildbase.BuildBase):

    @staticmethod
    def getName(self):
        
        return 'uidr'


    def __init__(self, nWorkspace, nProject):

        self.mWorkspace = nWorkspace
        self.mProject = nProject
        
        self.__initChdir()


    def __runInit(self, nBuildParameter):
        
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

        sysName = platform.system()
        if 'Windows' == sysName:
            mPlatform += 'devenv'
        elif 'Darwin' == sysName:
            mPlatform += 'xcodebuild'
        else:
            mPlatform += 'make'


    def __initChdir(self):
        
        cmdPath = '../%s/build/%s/' % (self.mWorkSpace, self.mProject)
        buildbase.BuildBase.runChdir(self, cmdPath)

            
    def runBuild(self, nBuildParameter):
        makeCmd = 'make'
        if 'Windows' == sysName:
            makeCmd = 'devenv %s.sln /build %s /out output.txt' % (mPlatform, mDebug)
        elif 'Darwin' == sysName:
            makeCmd = 'xcodebuild -project %s.xcodeproj -configuration %s' % (mPlatform, mDebug)
        else:
            makeCmd = 'make'
        buildbase.BuildBase.interBuild(self, makeCmd)
        
        
    def setDebug(self, nDebug):
        if True == nDebug:
            mDebug = 'DEBUG'
        else:
            mDebug = 'RELEASE'


    mWorkSpace = ''
    mPlatform = ''
    mProject = ''
    mDebug = ''
