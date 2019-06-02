@echo off
cd %~dp0
title Create new Hugo post
set/pname=Enter post file name: 
hugo new content/post/%name%
