#!/bin/bash

echo "Hello"

START_DIR="/home/coder/project"

PREFIX="deploy-code-server"

mkdir -p $START_DIR

echo "[$PREFIX] Starting code-server..."
# Now we can run code-server with the default entrypoint
/usr/bin/entrypoint.sh --bind-addr 0.0.0.0:8080 $START_DIR
