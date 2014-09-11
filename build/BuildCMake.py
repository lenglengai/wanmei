import platform
import buildbase

class BuildCMake(buildbase.BuildBase):

    def getName(self):
        return '-m'
    
    def runInit(self):
        sysName = platform.system()
        if 'Windows' == sysName:
            mPlatform = 'Visual Studio 12 2013'
        elif 'Darwin' == sysName:
            mPlatform = 'Xcode'
        else:
            mPlatform = 'Unix Makefiles'

    def runBuild(self):
        cmakeCmd = 'cmake %s -G\"%s\" -D__WORKSPACE__=%s -D__PROJECT__=%s' % (mSource, mPlatform, mWorkSpace, mProject)
        buildbase.BuildBase.interBuild(self, cmakeCmd)

    def setWorkSpace(self, nWorkSpace):
        mWorkSpace = nWorkSpace

    def setProject(self, nProject):
        mProject = nProject
        
    def setSource(self, nSource):
        mSource = nSource

    mWorkSpace = ''
    mPlatform = ''
    mProject = ''
    mSource = ''

    
    
