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
    print 'welcome to wanmei\'s build of tools'


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
