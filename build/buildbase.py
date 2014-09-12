import os
import subprocess

class BuildBase():

    def runChdir(self, nCmdPath):
        self.mCmdPath = os.path.abspath(nCmdPath)
        os.chdir(self.mCmdPath)


    def interBuild(self, nCmd):
        subprocess.call(nCmd, shell=True)
        
    mCmdPath = ''
 
