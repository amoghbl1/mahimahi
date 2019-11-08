mahimahi: a web performance measurement toolkit

# Installation for Fedora

1. `dnf install -y protobuf-compiler autoconf automake iptables pkgconfig dnsmasq httpd httpd-devel mod_ssl debhelper openssl openssl-devel openssl-libs libxcb-devel cairo-devel pango-devel`.
2. Create an ssl cert at `/etc/ssl/certs/ssl-cert-snakeoil.pem`.
3. ./autgen.sh
4. ./configure
5. make
6. sudo make install
