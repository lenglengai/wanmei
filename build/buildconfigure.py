#!/usr/bin/env python
#-*- coding:utf-8 -*-

import os
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
        self.runCopyXml()
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

    def runCopyXml(self):
        assetPath = ''
        if 'android' == self.mProject:
            assetPath = os.path.abspath('../mbclient/Resources')
        elif 'gameServer' == self.mProject:
            configurePath = '../binary'
            assetPath = os.path.abspath(configurePath)
        xmlPath = os.path.abspath('../../source/XMLLISTS')
        for line in open(xmlPath):
            self.inCopyXml(line, assetPath)
