#!/bin/bash  

# 获取当前日期和时间  
current_date=$(date +"%Y-%m-%d")  
current_time=$(date +"%H:%M:%S")  
  
# 获取本地计算机的操作系统名  
os_name=$(uname -s)  
  
# 获取本次修改过的文件名  
modified_files=$(git status --porcelain | grep -oE "([A-Za-z0-9]+/)*([A-Za-z0-9]+)")  
  
# 构建备注内容  
commit_message="${current_date} ${current_time} ${os_name} ${modified_files}"  

git add .

# 执行git commit命令  
git commit -m "${commit_message}"

git push origin main