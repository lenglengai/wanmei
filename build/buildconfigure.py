#!/usr/bin/env python
#-*- coding:utf-8 -*-

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
        configureCmd = 'gameClient.exe configure'
        sysName = platform.system()
        if 'Windows' != sysName:
            configureCmd = './gameClient configure'
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
        elif 'gameServer' == nPlatform:
            configurePath = '../%s/binary' % nProj
            assetPath = os.path.abspath(configurePath)
        xmlPath = os.path.abspath('../source/XMLLISTS')
        for line in open(xmlPath):
            inCopyXml(line, assetPath)
