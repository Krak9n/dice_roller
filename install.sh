#!/bin/bash
set -e
echo "Installing..."
make
sudo make install
make install
echo "Installation complete!"
