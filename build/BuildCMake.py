import platform
import subprocess

class BuildCMake():
    def __init__(self, nCmdPath, )
    
    
    def runBuild():
        subprocess.call(cmakeCmd, shell=True)

    def initPlatform():
        sysName = platform.system()
        if 'Windows' == sysName:
            mPlatform += '\"Visual Studio 12 2013\"'
        elif 'Darwin' == sysName:
            mPlatform += '\"Xcode\"'
        else:
            mPlatform += '\"Unix Makefiles\"'


    mPlatform = ''
    mCmdPath = ''
    
    
