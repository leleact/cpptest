生成证书
keytool -genkey -alias keyname -keyalg RSA -keysize 2048 -keypass keypasswd -validity 1095 -keystore client_cert.ks -storepass storepasswd

导出证书
keytool -export -alias keyname -keystore client_cert.ks -file xxx.cer -storepass storepasswd
