import os

class BuildBase():
    
    def runBuild(self):
        print('error call BuildBase\'s runBuild!')
        
    def runChdir(self, nCmdPath):
        os.chdir(nCmdPath)

    def runInit(self):
        print('error call BuildBase\'s runInit!')

    
