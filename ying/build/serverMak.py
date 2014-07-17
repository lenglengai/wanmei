import os
import sys

print 'welcome to build of server'

sys.path.append('../../build')
import cmakeBuild

binNick = 'SERVER'
includePath = os.path.abspath('../Include')

cmakeBuild.runBuild(includePath, binNick, False)
