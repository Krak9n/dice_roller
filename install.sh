#!/bin/bash
set -e
echo "Installing..."
git clone https://github.com/Krak9n/dice_roller.git
cd dice_roller
make
<<<<<<< HEAD
sudo make install
=======
make install
>>>>>>> a6ae12f (few changes)
echo "Installation complete!"
