import os
import platform
import subprocess

def runBuild(nInclude, nBinName, nIDE):
########################################################################
  print '[1]create build directories'
  dirName = './' + nBinName
  if True == nIDE:
    dirName += '-ide/'
  else:
    dirName += '-mak/'
  if not os.path.isdir(dirName):
  	os.mkdir(dirName)
########################################################################
  print '[2]run cmake generate makefiles'
  os.chdir(dirName)
  cmakeCmd = 'cmake '
  cmakeCmd += '../../../source/'
  cmakeCmd += ' -G'

  sysName = platform.system()
  if 'Windows' == sysName:
    if True == nIDE:
      cmakeCmd += '\"Visual Studio 12 2013\"'
    else:
      cmakeCmd += '\"MinGW Makefiles\"'
  elif 'Darwin' == sysName:
    if True == nIDE:
      cmakeCmd += '\"Xcode\"'
    else:
      cmakeCmd += '\"Unix Makefiles\"'
  else:
    if True == nIDE:
      cmakeCmd += '\"Visual Studio 12 2013\"'
    else:
      cmakeCmd += '\"Unix Makefiles\"'
      
  cmakeCmd += ' -D__'
  cmakeCmd += nBinName.upper()
  cmakeCmd += '__=ON -D__INCLUDE__='
  cmakeCmd += nInclude

  subprocess.call(cmakeCmd, shell=True)
########################################################################
  if True == nIDE:
    return

  print '[3]run make generate binary file'

  if 'Windows' == sysName:
    subprocess.call('mingw32-make', shell=True)
  else:
    subprocess.call('make', shell=True)
########################################################################
  print '[4]binary file generate finish, bye bye!'
 