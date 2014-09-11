import platform
import buildbase

class BuildJourney(buildbase.BuildBase):

    def getName(self):
        return '-j'
    
    def runInit(self):
        cmdPath = '../%s/binary/' % mProj
        buildbase.BuildBase.runChdir(self, cmdPath)
        
    def runBuild(self):
        journeyPath = '../%s/journey/journey_%s' % (nProj, nNo)
        journeyPath = os.path.abspath(journeyPath)
        journeyCmd = 'journey.exe %s' % journeyPath
        sysName = platform.system()
        if 'Windows' != sysName:
            journeyCmd = './journey %s' % journeyPath
        buildbase.BuildBase.interBuild(self, journeyCmd)
                
    def setProj(self, nProj):
        mProj = nProj
        
    def setNo(self, nNo):
        mNo = nNo

    mProj = ''
    mNo = 0
