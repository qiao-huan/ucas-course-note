#!/bin/bash  
  
# 获取远程origin仓库的最新commit哈希  
remote_commit=$(git ls-remote origin main | awk '{print $1}')  
  
# 获取本地main分支的最新commit哈希  
local_commit=$(git rev-parse main)  
  
# 检查远程和本地commit哈希是否相同  
if [ "$remote_commit" == "$local_commit" ]; then  
  echo "远程origin仓库的main分支没有更新。"  
else  
  echo "远程origin仓库的main分支有更新，开始拉取合并..."  
    
  # 将本地尚未add或commit的工作暂存  
  git stash save "Local changes"  
    
  # 拉取远程origin仓库的最新更新  
  git fetch origin main  
    
  # 切换到本地main分支  
  git checkout main  
    
  # 合并远程origin仓库的main分支到本地main分支  
  git merge origin/main  
    
  # 将之前暂存的工作应用回来  
  git stash pop  
    
  echo "拉取合并完成。当前本地分支状态已更新为最新。"  
fi
