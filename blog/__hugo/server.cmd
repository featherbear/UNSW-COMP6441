@echo off
cd %~dp0
title Hugo dev server
hugo server -D --bind=0.0.0.0 --disableFastRender