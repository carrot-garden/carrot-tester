#!/bin/bash

#
# note: make sure vpn is working
#	http://linux.die.net/man/8/vpnc
#	see /etc/vpnc/default.conf
#

#
# note: you must setup authorized_keys on cqg tunnel server
#

# http://linux.die.net/man/8/vpnc
echo "### stop vpn if running"
sudo vpnc-disconnect
sleep 3

# http://linux.die.net/man/8/vpnc
echo "### start vpn from barchart to cqg"
sudo vpnc
sleep 3

# cqg tunnel ssh login
TUNNEL_USER="XXX"
TUNNEL_HOST="172.18.62.166"

# expose cqg test environment on localhost
LOCAL_BIND="localhost"
LOCAL_PORT="2222"

# cqg SDC (security definition server) inside cqg vpn
REMOTE_HOST="10.1.0.71"
REMOTE_PORT="2222"

# http://unixhelp.ed.ac.uk/CGI/man-cgi?ssh+1
#
#     -L [bind_address:]port:host:hostport
#	     Specifies that the given port on the local (client) host is to be
#	     forwarded to the given host and port on the remote side.  This
#	     works by allocating a socket to listen to port on the local side,
#	     optionally bound to the specified bind_address.  Whenever a con-
#	     nection is made to this port, the connection is forwarded over
#	     the secure channel, and a connection is made to host port
#	     hostport from the remote machine.	Port forwardings can also be
#	     specified in the configuration file.  IPv6 addresses can be spec-
#	     ified with an alternative syntax:
#	     [bind_address/]port/host/hostport or by enclosing the address in
#	     square brackets.  Only the superuser can forward privileged
#	     ports.  By default, the local port is bound in accordance with
#	     the GatewayPorts setting.	However, an explicit bind_address may
#	     be used to bind the connection to a specific address.  The
#	     bind_address of "localhost" indicates that the listening port be
#	     bound for local use only, while an empty address or '*' indicates
#	     that the port should be available from all interfaces.

echo "### setup forward; start ping to avoid inactivity disconnect"

ssh \
	-L $LOCAL_BIND:$LOCAL_PORT:$REMOTE_HOST:$REMOTE_PORT \
	$TUNNEL_USER@$TUNNEL_HOST \
	"ping $REMOTE_HOST"
