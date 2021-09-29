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
# https://www.digitalocean.com/community/tutorials/how-to-install-node-js-on-an-ubuntu-14-04-server
RUN curl -sL https://deb.nodesource.com/setup | sudo bash - && \
RUN sudo apt-get install -yq nodejs build-essential

# fix npm - not the latest version installed by apt-get
RUN npm install -g npm

# Copy rclone tasks to /tmp, to potentially be used
COPY deploy-container/rclone-tasks.json /tmp/rclone-tasks.json

# Fix permissions for code-server
RUN sudo chown -R coder:coder /home/coder/.local

# You can add custom software and dependencies for your environment below
# -----------

# Install a VS Code extension:
# Note: we use a different marketplace than VS Code. See https://github.com/cdr/code-server/blob/main/docs/FAQ.md#differences-compared-to-vs-code
RUN code-server --install-extension esbenp.prettier-vscode
RUN code-server --install-extension ms-python.python
RUN curl -L https://github.com/microsoft/vscode-cpptools/releases/download/1.7.0-insiders/cpptools-linux.vsix --output cpptools-linux.vsix
RUN code-server --install-extension cpptools-linux.vsix
RUN rm cpptools-linux.vsix


# Install apt packages:
RUN sudo apt-get install -y build-essential

# Copy files: 
# COPY deploy-container/myTool /home/coder/myTool

# Git config
RUN git config --global user.email ""
RUN git config --global user.name "Teerapat Jenrungrot"

# Set ulimit

RUN ulimit -s unlimited

# -----------

# Port
ENV PORT=8080

# Use our custom entrypoint script first
COPY deploy-container/entrypoint.sh /usr/bin/deploy-container-entrypoint.sh
ENTRYPOINT ["/usr/bin/deploy-container-entrypoint.sh"]
