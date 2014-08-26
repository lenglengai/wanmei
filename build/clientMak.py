import os
import sys

print 'welcome to build of client'

sys.path.append('../../build')
import cmakeBuild

binNick = 'client'
includePath = os.path.abspath('../Include')

cmakeBuild.runBuild(includePath, binNick, False)
