#!/bin/bash
set -e
echo "Installing..."
make
sudo make install
make install
# making it executable systemwide
sudo mv throw_dice /usr/bin/
echo "Installation complete!"
