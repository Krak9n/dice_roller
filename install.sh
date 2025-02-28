#!/bin/bash
set -e
echo "Installing..."
git clone https://github.com/Krak9n/dice_roller.git
cd dice_roller
make
sudo make install
echo "Installation complete!"
