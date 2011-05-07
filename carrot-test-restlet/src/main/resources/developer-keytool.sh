#!/bin/bash

#
#http://www.exampledepot.com/egs/java.security.cert/CreateCert.html
#

ALIAS="developer"

#
#	private store
#

# "user & pass"
STOREPASS="45aa2f77-9c86-4ee9-e013-dfaa06ed30d5"

# location
KEYSTORE="$HOME/.ssl/$ALIAS-java-keys.jks"

# identity of the signer
DNAME="cn=dev, ou=dev, o=dev, c=US"

# validity of certificate
DAYS="9999"

echo "### list keys"
keytool -list -keystore "$KEYSTORE" -storepass "$STOREPASS"

echo "### delete key"
keytool -delete -alias "$ALIAS" -keystore "$KEYSTORE" -storepass "$STOREPASS"

echo "### generate key"
keytool -genkey -alias "$ALIAS" -keystore "$KEYSTORE" -storepass "$STOREPASS" -keypass "$STOREPASS" -validity "$DAYS" -dname "$DNAME"


#
#	public store
#

TRUSTSTORE="$HOME/.ssl/$ALIAS-java-cert.jks"
TRUSTPASS="62e403d8-108b-f394-fad8-d9460eff1fb5"

CERT="$ALIAS.crt"

echo "### delete cert"
keytool -delete -alias "$ALIAS" -keystore "$TRUSTSTORE" -storepass "$TRUSTPASS"

echo "### export cert"
keytool -exportcert -alias "$ALIAS" -keystore "$KEYSTORE" -storepass "$STOREPASS" -keypass "$STOREPASS" -file "$CERT"

echo "### import cert"
keytool -importcert -alias "$ALIAS" -keystore "$TRUSTSTORE" -storepass "$TRUSTPASS" -file "$CERT" -noprompt -trustcacerts

