import os
import subprocess

class BuildBase():

    def runChdir(self, nCmdPath):
        mCmdPath = os.path.abspath(nCmdPath)
        os.chdir(mCmdPath)

    def interBuild(self, nCmd):
        subprocess.call(nCmd, shell=True)

    mCmdPath = ''
 
