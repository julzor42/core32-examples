#!/bin/bash
TARGET=julzor/xc32:8.3.1
PROJECT_DIR=`pwd`
docker run --rm \
        -v$PROJECT_DIR:/project \
        -v$PROJECT_DIR/../../core32:/opt/core32 \
         $TARGET $*