#!/usr/bin/env bash

curl_time=$(date +%F-%H-%M-%S)

curl -X POST \
https://tom-logger.azurewebsites.net/api/log \
-d 'LinuxClass: True' \
-d 'UboxDate: $curl_time' \

echo "";


