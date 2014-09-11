import shutil
import platform
import buildbase

class BuildConfigure(buildbase.BuildBase):

    def runBuild(self):


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
