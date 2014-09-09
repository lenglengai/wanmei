import platform
import subprocess

class BuildIDE():
    def __init__(self, nDebug):
        mDebug=nDebug

    def runBuild():

    def initPlatform():
        sysName = platform.system()
        if 'Windows' == sysName:
            mPlatform += 'devenv'
        elif 'Darwin' == sysName:
            mPlatform += 'xcodebuild'
        else:
            mPlatform += '\"Unix Makefiles\"'

    mPlatform = ''
    mDebug=False
