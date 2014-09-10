import platform
import subprocess

import buildbase

class BuildCMake(buildbase.BuildBase):

    def runBuild(self):
        cmakeCmd = 'cmake %s -G\"%s\" -D__%s__ -D' % (mSource, mPlatform, )
        subprocess.call(cmakeCmd, shell=True)

    def runInit(self):
        sysName = platform.system()
        if 'Windows' == sysName:
            mPlatform = 'Visual Studio 12 2013'
        elif 'Darwin' == sysName:
            mPlatform = 'Xcode'
        else:
            mPlatform = 'Unix Makefiles'

    mPlatform = ''
    mCmdPath = ''
    mSource = ''
    m

    
    
