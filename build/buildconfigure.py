import shutil
import platform
import buildbase

class BuildConfigure(buildbase.BuildBase):

    @staticmethod
    def getName():
        return 'c'

    def interName(self):
        return BuildCMake.getName()

    def __init__(self, nWorkspace, nProject):
        self.mWorkspace = nWorkspace
        self.mProject = nProject
        self.__initChdir()
        
    def __initChdir(self):
        cmdPath = '../%s/binary/' % self.mWorkspace
        buildbase.BuildBase.runChdir(self, cmdPath)

    def runConfigure(self):
        configureCmd = 'configure.exe %s %sConfigure.xml' % (journeyPath, mProject)
        sysName = platform.system()
        if 'Windows' != sysName:
            configureCmd = './configure %s %s' % (journeyPath, platStr)
        buildbase.BuildBase.interBuild(self, configureCmd)

    def runCopy(self):
        cmdPath = cmdPath + '/configure.jf'
        journeyPath = journeyPath + '/configure.jf'
        shutil.copy(journeyPath, cmdPath)

    def setProject(nProject):
        mProject = nProject
        
    mProject = ''
