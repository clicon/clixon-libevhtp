# Libevtp for clixon 5.1-5.5

See [orig README](README.orig.md)

Note that this lib is necessary for Clixon RESTCONF HTTP/1 versions 5.1-5.5.
It is not needed in Clixon 5.6 (or later).

Modified libevtp as follows:

- Autotools instead of cmake
- Restconf support only (eventually)
- Stripped everything not needed by clixon, eg all examples, etc, please see original libevhtp for full implementation
- Added two API functions to make it work with external event handler and openssl init::

    int connection_parse_nobev(char *buf, size_t buflen, void *arg);`
    evhtp_connection_t *evhtp_connection_new_server(evhtp_t * htp, evutil_socket_t sock);

Install:
```
./configure
make
sudo make install
```