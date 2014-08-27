import os
import sys
import subprocess

def runJourney(nProj, nNo):
    print 'build the %s\'s journey of NO.%s' % (nProj, nNo)
    cmdPath = os.path.abspath('../tools/')
    os.chdir(cmdPath)
    projDir = '../%s/journey_%s' % (nProj, nNo)
    journeyPath = os.path.abspath(projDir)
    cmakeCmd = 'journey %s' % journeyPath
    subprocess.call(cmakeCmd, shell=True)
    
def runBuild(nProj, nPlatform):
    print 'build %s in %s' % (nProj, nPlatform)
    if 'android' == nPlatform:
        incPath = '../%s/include' % nProj
        includePath = os.path.abspath(incPath)
        os.environ['WANMEI_INCLUDE'] = includePath
        cmdPath = os.path.abspath('../mbclient')
        os.chdir(cmdPath)
	cmakeCmd = 'cocos compile -p android -j 4 --ap 15'
	subprocess.call(cmakeCmd, shell=True)
    else:
        dirName = '../%s/binary' % nProj
        if not os.path.isdir(dirName):
            os.mkdir(dirName)
            
        print 'build %s in %s' % (nProj, nPlatform)

print 'welcome to wanmei\'s build system'

if len(sys.argv) > 2:
    if '-j' == sys.argv[1]:
        runJourney(sys.argv[2], sys.argv[3])
    elif '-b' == sys.argv[1]:
        runBuild(sys.argv[2], sys.argv[3])
    else:
        print 'error parameters %s' % sys.argv[1]
else:
    print 'error parameter count'
