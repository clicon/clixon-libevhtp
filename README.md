# Libevtp for clixon

See [orig README](README.orig.md)

Modified libevtp as follows:

- Autotools instead of cmake
- Restconf support only (eventually)
- Stripped everything not needed by clixon, eg all examples, etc, please see original libevhtp for full implementation

Install:
```
./configure
make
sudo make install
```