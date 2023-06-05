git add -A

git commit -m ""

git pull origin project



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
