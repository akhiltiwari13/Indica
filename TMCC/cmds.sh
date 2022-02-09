#! /bin/zsh
cd build
cmake -G Xcode .. -DOPENSSL_ROOT_DIR=/opt/homebrew/opt/openssl/ -DOPENSSL_INCLUDE_DIR=/opt/homebrew/opt/openssl/include -DBUILD_TESTING=OFF -DBUILD_CURL_EXE=OFF -DUSE_MANUAL=OFF -DBOOST_FILESYSTEM=ON -DBOOST_OPTIONAL=ON -DBOOST_INCLUDE_DIR=/opt/homebrew/opt/boost -DBOOST_LIB_DIR=/opt/homebrew/opt/boost/lib -DCMAKE_EXPORT_COMPILE_COMANDS=True 
