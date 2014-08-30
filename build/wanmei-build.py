import os
import sys
import shutil
import platform
import subprocess

def runJourney(nProj, nNo):
    print 'build the %s\'s journey of NO.%s' % (nProj, nNo)
    cmdPath = '../%s/binary/' % nProj
    cmdPath = os.path.abspath(cmdPath)
    os.chdir(cmdPath)
    projDir = '../%s/journey/journey_%s' % (nProj, nNo)
    journeyPath = os.path.abspath(projDir)
    cmakeCmd = 'journey %s' % journeyPath
    subprocess.call(cmakeCmd, shell=True)

def inCopyXml(nLine)
    info = nLine.split(' ')
    

def runCopyXml(nProj, nPlatform)
    assetPath = ''
    if 'android' == nPlatform:
        assetPath = os.path.abspath('../mbclient/Resources')
    else:
        assetPath = os.path.abspath('../%s/build/config')
        if not os.path.isdir(assetPath):
            os.mkdir(assetPath)
    xmlPath = os.path.abspath('../source/XMLLISTS')
    for line in open(xmlPath):
        runCopy(line, assetPath)
    
        
    
def runBuild(nProj, nPlatform):
    sysName = platform.system()
    print 'build %s of %s in %s' % (nPlatform, nProj, sysName)
    if 'android' == nPlatform:
        incPath = '../%s/include' % nProj
        includePath = os.path.abspath(incPath)
        os.environ['WANMEI_INCLUDE'] = includePath
        cmdPath = os.path.abspath('../mbclient')
        os.chdir(cmdPath)
	cmakeCmd = 'cocos compile -p android -j 4 --ap 15'
	subprocess.call(cmakeCmd, shell=True)
    elif 'journey' == nPlatform:
        dirName = '../%s/build/%s/' % (nProj, nPlatform)
        binPath = '../%s/build/%s/Release/%s.exe' % (nProj, nPlatform, nPlatform)
        binPath = os.path.abspath(binPath)
        binOut = '../%s/binary/%s.exe' % (nProj, nPlatform)
        binOut = os.path.abspath(binOut)
        if not os.path.isdir(dirName):
            os.mkdir(dirName)
        cmdPath = os.path.abspath(dirName)
        os.chdir(cmdPath)
        cmakeCmd = 'cmake '
        cmakeCmd += '../../../build/build-cmake/journey/'
        cmakeCmd += ' -G'
        if 'Windows' == sysName:
            cmakeCmd += '\"Visual Studio 12 2013\"'
        elif 'Darwin' == sysName:
            cmakeCmd += '\"Xcode\"'
        else:
            cmakeCmd += '\"Unix Makefiles\"'
        cmakeCmd += ' -D__'
        cmakeCmd += nPlatform.upper()
        cmakeCmd += '__=ON -D__PROJDIR__='
        incPath = '../../'
        includePath = os.path.abspath(incPath)
        cmakeCmd += includePath
        subprocess.call(cmakeCmd, shell=True)
        if 'Windows' == sysName:
            buildCmd = 'devenv %s.sln /rebuild RELEASE /out output.txt' % nPlatform
            subprocess.call(buildCmd, shell=True)
            shutil.copy(binPath, binOut)
        else:
            subprocess.call('make', shell=True)
    else:
        dirName = '../%s/build/%s/' % (nProj, nPlatform)
        binPath = '../%s/build/%s/Release/%s.exe' % (nProj, nPlatform, nPlatform)
        binPath = os.path.abspath(binPath)
        binOut = '../%s/binary/%s.exe' % (nProj, nPlatform)
        binOut = os.path.abspath(binOut)
        if not os.path.isdir(dirName):
            os.mkdir(dirName)
        cmdPath = os.path.abspath(dirName)
        os.chdir(cmdPath)
        cmakeCmd = 'cmake '
        cmakeCmd += '../../../build/build-cmake/source/'
        cmakeCmd += ' -G'
        if 'Windows' == sysName:
            cmakeCmd += '\"Visual Studio 12 2013\"'
        elif 'Darwin' == sysName:
            cmakeCmd += '\"Xcode\"'
        else:
            cmakeCmd += '\"Unix Makefiles\"'
        cmakeCmd += ' -D__'
        cmakeCmd += nPlatform.upper()
        cmakeCmd += '__=ON -D__PROJDIR__='
        incPath = '../../'
        includePath = os.path.abspath(incPath)
        cmakeCmd += includePath
        subprocess.call(cmakeCmd, shell=True)
        if 'Windows' == sysName:
            buildCmd = 'devenv %s.sln /rebuild RELEASE /out output.txt' % nPlatform
            subprocess.call(buildCmd, shell=True)
            shutil.copy(binPath, binOut)
        else:
            subprocess.call('make', shell=True)
            
if __name__ == '__main__':
    print 'welcome to wanmei\'s build system'
    if len(sys.argv) > 2:
        if '-j' == sys.argv[1]:
            runJourney(sys.argv[2], sys.argv[3])
        elif '-b' == sys.argv[1]:
            runBuild(sys.argv[2], sys.argv[3])
        elif '-a' == sys.argv[1]:
            runBuild(sys.argv[2], 'login')
            runBuild(sys.argv[2], 'server')
            runBuild(sys.argv[2], 'client')
        else:
            print 'error parameters %s' % sys.argv[1]
    else:
        print 'error parameter count'
