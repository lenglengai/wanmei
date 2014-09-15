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
    
    def insertBuildParameter(self, nBuildParameter):
        cmdPath = '../%s/binary/' % self.mWorkspace
        buildbase.BuildBase.runChdir(self, cmdPath)

    def runBuild(self):
        self.runCopy()
        self.runConfigure()

    def runConfigure(self):
        configurePath = '../configure/%sConfigure.xml' % self.mProject
        configurePath = os.path.abspath(configurePath)
        outPath = '../binary/%sConfigure.jf' % self.mProject
        outPath = os.path.abspath(outPath)
        configureCmd = 'configure.exe %s %s' % (configurePath, outPath)
        sysName = platform.system()
        if 'Windows' != sysName:
            configureCmd = './configure %s %s' % (configurePath, outPath)
        buildbase.BuildBase.interBuild(self, configureCmd)

    def inCopyXml(self, nLine, nAssetPath):
        line = nLine.strip()
        start = line.rfind('/')
        end = len(line)
        fileName = line[start:end]
        dstPath = nAssetPath + fileName
        xmlPath = os.path.abspath(line)
        shutil.copy(xmlPath, dstPath)

    def runCopyXml():
        assetPath = ''
        if 'android' == nPlatform:
            assetPath = os.path.abspath('../mbclient/Resources')
        elif 'server' == nPlatform:
            configurePath = '../%s/configure' % nProj
            assetPath = os.path.abspath(configurePath)
        xmlPath = os.path.abspath('../source/XMLLISTS')
        for line in open(xmlPath):
            inCopyXml(line, assetPath)
