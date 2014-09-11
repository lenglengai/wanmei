import platform
import buildbase

class BuildIDE(buildbase.BuildBase):

    def getName(self):
        return '-m'

    def runInit(self):
        sysName = platform.system()
        if 'Windows' == sysName:
            mPlatform += 'devenv'
        elif 'Darwin' == sysName:
            mPlatform += 'xcodebuild'
        else:
            mPlatform += 'make'
            
    def runBuild(self):
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
        
    mPlatform = ''
    mDebug = ''

    http://argouml-downloads.tigris.org/nonav/argouml-0.34/ArgoUML-0.34.app.tar.gz
