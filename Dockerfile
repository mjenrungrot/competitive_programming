# Start from the code-server Debian base image
FROM codercom/code-server:latest

USER coder

# Apply VS Code settings
COPY deploy-container/settings.json .local/share/code-server/User/settings.json

# Use bash shell
ENV SHELL=/bin/bash

# Install unzip + rclone (support for remote filesystem)
RUN sudo apt-get update && sudo apt-get install unzip -y
RUN curl https://rclone.org/install.sh | sudo bash

# install from nodesource using apt-get
RUN curl -fsSL https://deb.nodesource.com/setup_current.x | sudo -E bash -
RUN sudo apt-get install -yq nodejs build-essential

# fix npm - not the latest version installed by apt-get
RUN sudo npm install -g npm

# Copy rclone tasks to /tmp, to potentially be used
COPY deploy-container/rclone-tasks.json /tmp/rclone-tasks.json

# Fix permissions for code-server
RUN sudo chown -R coder:coder /home/coder/.local

# You can add custom software and dependencies for your environment below
# -----------
# Install vsce for building vsix
RUN sudo npm install -g vsce

# Install a VS Code extension:
# Note: we use a different marketplace than VS Code. See https://github.com/cdr/code-server/blob/main/docs/FAQ.md#differences-compared-to-vs-code
RUN code-server --install-extension esbenp.prettier-vscode
RUN code-server --install-extension ms-python.python
RUN curl -L https://github.com/microsoft/vscode-cpptools/releases/download/1.7.1/cpptools-linux.vsix --output cpptools-linux.vsix
RUN code-server --install-extension cpptools-linux.vsix
RUN rm cpptools-linux.vsix

RUN git clone https://github.com/wenfangdu/vscode-snippet-generator
WORKDIR vscode-snippet-generator
RUN vsce package --out vscode-snippet-generator.vsix
RUN code-server --install-extension vscode-snippet-generator.vsix
WORKDIR ..
RUN rm -rf vscode-snippet-generator



# Install apt packages:
RUN sudo apt-get install -y build-essential

# Copy files: 
# COPY deploy-container/myTool /home/coder/myTool

# Git config
RUN git config --global user.email ""
RUN git config --global user.name "Teerapat Jenrungrot"
RUN git clone https://github.com/mjenrungrot/competitive_programming /home/coder/project

# Set ulimit

RUN ulimit -s unlimited

# -----------

# Port
ENV PORT=8080

# Use our custom entrypoint script first
COPY deploy-container/entrypoint.sh /usr/bin/deploy-container-entrypoint.sh
ENTRYPOINT ["/usr/bin/deploy-container-entrypoint.sh"]
