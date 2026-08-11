#!/bin/bash

# Install Geode CLI
echo "Installing Geode CLI..."

# Create bin directory if it doesn't exist
mkdir -p ~/.local/bin

# Download Geode CLI for Linux
curl -L https://github.com/geode-sdk/cli/releases/latest/download/geode-cli-linux -o ~/.local/bin/geode 2>/dev/null

# Make it executable
chmod +x ~/.local/bin/geode

# Add to PATH if not already there
if ! grep -q "~/.local/bin" ~/.bashrc; then
    echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
fi

# Verify installation
echo ""
echo "Checking Geode CLI installation..."
~/.local/bin/geode --version

echo ""
echo "✅ Geode CLI installed successfully!"
echo "You can now use: geode build"
