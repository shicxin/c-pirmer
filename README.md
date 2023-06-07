git add -A

git commit -m ""

git pull origin project



## 初始化：

-   `git init`：在当前目录下创建一个新的git仓库，生成一个.git目录，用于保存所有版本记录
-   `git init <directory>`：在指定目录下创建一个新的git仓库，如果目录不存在，会自动创建
-   `git clone <repo>`：从现有的git仓库中克隆项目到本地
-   `git clone <repo> <directory>`：从现有的git仓库中克隆项目到指定的本地目录

初始化一个git仓库后，你需要新建一个分支，命令是：

-   `git branch <branch_name>`：在当前仓库下创建一个新的分支，但不切换到该分支
-   `git checkout <branch_name>`：切换到指定的分支
-   `git checkout -b <branch_name>`：创建一个新的分支并切换到该分支

本地仓库相关配置：

-   `git config --global user.name <name>`：设置提交代码时的用户名
-   `git config --global user.email <email>`：设置提交代码时的邮箱
-   `git config --list`：显示当前的git配置信息
-   `git config -e`：编辑git配置文件
-   `git remote add origin <remote_repo>`：关联本地仓库和远程仓库

基础使用：

-   `git add <file>`：将文件添加到暂存区
-   `git commit -m <message>`：将暂存区的文件提交到本地仓库
-   `git push origin <branch>`：将本地仓库的指定分支推送到远程仓库

## 关于分支：

-   `git branch`：查看本地分支
-   `git branch -r`：查看远程分支
-   `git branch -a`：查看本地和远程分支
-   `git branch 分支名`：创建本地分支
-   `git checkout 分支名`：切换到指定分支
-   `git checkout -b 分支名`：创建并切换到新分支
-   `git branch -d 分支名`：删除本地分支

**切换分支时，如果当前分支有未提交的修改，你可以选择以下方法：**

-   [使用`git stash`命令暂存当前修改，然后切换分支，再用`git stash pop`恢复修改](https://www.cnblogs.com/yhjoker/p/11776240.html)[3](https://www.cnblogs.com/yhjoker/p/11776240.html)
-   使用`git commit`命令提交当前修改，然后切换分支，再用`git cherry-pick`或者`git rebase`将提交应用到其他分支
-   [使用`git checkout -f`命令强制切换分支，丢弃当前修改](https://www.cnblogs.com/yhjoker/p/11776240.html)

**git下拉仓库新增文件的基本命令是：**

-   `git clone 仓库地址`：将远程仓库的代码克隆到本地
-   `git fetch 仓库名 分支名`：从远程仓库获取最新版本到本地，不会自动合并
-   `git pull 仓库名 分支名`：从远程仓库获取最新版本并合并到本地
-   `git merge 仓库名/分支名`：将远程仓库的指定分支合并到当前分支

**git合并分支的基本命令是：**

-   `git merge 分支名`：将指定分支合并到当前分支
-   `git merge --no-ff 分支名`：使用普通模式合并，即使合并可以快进，也会创建一个新的提交对象
-   `git merge --squash 分支名`：将指定分支的所有提交压缩为一个提交，然后合并到当前分支
-   `git merge --abort`：取消当前的合并操作，重置到合并前的状态

合并分支时，可能会遇到冲突，即两个分支对同一个文件的同一部分做了不同的修改。这时，你需要手动解决冲突，然后再提交合并结果。

**你可以使用以下命令来查看和解决冲突：**

-   `git status`：查看哪些文件有冲突
-   `git diff`：查看具体的冲突内容
-   `git add 文件名`：标记冲突已解决
-   `git commit`：完成合并操作



1.  切换到你想要更新的本地分支，比如master分支：`git checkout master`
2.  从远程仓库拉取最新的代码到本地分支，比如origin/master分支：`git pull origin master`
3.  如果没有冲突，你的本地分支就会自动合并远程分支的更新。如果有冲突，你需要手动解决冲突，然后提交修改：`git add .` `git commit -m "解决冲突"`
4.  如果你想把本地分支的更新推送到远程仓库，你可以使用：`git push origin master`
5.  如果你想要比较当前工作区的分支（比如master分支）和远程仓库的同名分支（比如origin/master分支），你可以使用：git diff master origin/master
6.  如果你想要查看远程仓库有而当前工作区没有的提交信息，你可以使用：git log master..origin/master
7.  如果你想要查看两个分支的文件改动统计，你可以使用：git diff --stat master origin/master

1.  输入`git init`命令，初始化本地仓库。
2.  输入`git add .`命令，把文件夹里的所有文件添加到本地仓库。
3.  输入`git commit -m "注释"`命令，提交文件到本地仓库，并添加一些说明信息。
4.  输入`git remote add origin 仓库地址`命令，把本地仓库和远程仓库关联起来，仓库地址可以在gitee上找到。
5.  输入`git pull --rebase origin master`命令，把远程仓库的内容同步到本地仓库，如果远程仓库为空可以跳过这一步。
6.  输入`git push -u origin master`命令，把本地仓库的文件推送到远程仓库。
