#!/bin/bash

# Create proper .geode mod file
mkdir -p gravity-mod
cp -r src/ gravity-mod/
cp -r include/ gravity-mod/
cp geode.json gravity-mod/

# Create valid zip
cd gravity-mod
zip -r ../gravity-mod.geode *
cd ..

echo "✅ gravity-mod.geode created!"
