1 查看、添加、提交、删除、找回，重置修改文件
  2 
  3 
  4 git help <command> # 显示command的help
  5 
  6 git show # 显示某次提交的内容 git show $id
  7 
  8 git co -- <file> # 抛弃工作区修改
  9 
 10 git co . # 抛弃工作区修改
 11 
 12 git add <file> # 将工作文件修改提交到本地暂存区
 13 
 14 git add . # 将所有修改过的工作文件提交暂存区
 15 
 16 git rm <file> # 从版本库中删除文件
 17 
 18 git rm <file> --cached # 从版本库中删除文件，但不删除文件
 19 
 20 git reset <file> # 从暂存区恢复到工作文件
 21 
 22 git reset -- . # 从暂存区恢复到工作文件
 23 
 24 git reset --hard # 恢复最近一次提交过的状态，即放弃上次提交后的所有本次修改
 25 
 26 git ci <file> git ci . git ci -a # 将git add, git rm和git ci等操作都合并在一起做　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　git ci -am "some comments"
 27 
 28 git ci --amend # 修改最后一次提交记录
 29 
 30 git revert <$id> # 恢复某次提交的状态，恢复动作本身也创建次提交对象
 31 
 32 git revert HEAD # 恢复最后一次提交的状态
 33 
 34 查看文件diff
 35 
 36 
 37 git help <command> # 显示command的help
 38 
 39 git show # 显示某次提交的内容 git show $id
 40 
 41 git co -- <file> # 抛弃工作区修改
 42 
 43 git co . # 抛弃工作区修改
 44 
 45 git add <file> # 将工作文件修改提交到本地暂存区
 46 
 47 git add . # 将所有修改过的工作文件提交暂存区
 48 
 49 git rm <file> # 从版本库中删除文件
 50 
 51 git rm <file> --cached # 从版本库中删除文件，但不删除文件
 52 
 53 git reset <file> # 从暂存区恢复到工作文件
 54 
 55 git reset -- . # 从暂存区恢复到工作文件
 56 
 57 git reset --hard # 恢复最近一次提交过的状态，即放弃上次提交后的所有本次修改
 58 
 59 git ci <file> git ci . git ci -a # 将git add, git rm和git ci等操作都合并在一起做　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　git ci -am "some comments"
 60 
 61 git ci --amend # 修改最后一次提交记录
 62 
 63 git revert <$id> # 恢复某次提交的状态，恢复动作本身也创建次提交对象
 64 
 65 git revert HEAD # 恢复最后一次提交的状态
 66 
 67 查看提交记录
 68 
 69 git log git log <file> # 查看该文件每次提交记录
 70 
 71 git log -p <file> # 查看每次详细修改内容的diff
 72 
 73 git log -p -2 # 查看最近两次详细修改内容的diff
 74 
 75 git log --stat #查看提交统计信息
 76 tig
 77 
 78 Mac上可以使用tig代替diff和log，brew install tig
 79 
 80 
 81 Git 本地分支管理
 82 查看、切换、创建和删除分支
 83 
 84 
 85 git br -r # 查看远程分支
 86 
 87 git br <new_branch> # 创建新的分支
 88 
 89 git br -v # 查看各个分支最后提交信息
 90 
 91 git br --merged # 查看已经被合并到当前分支的分支
 92 
 93 git br --no-merged # 查看尚未被合并到当前分支的分支
 94 
 95 git co <branch> # 切换到某个分支
 96 
 97 git co -b <new_branch> # 创建新的分支，并且切换过去
 98 
 99 git co -b <new_branch> <branch> # 基于branch创建新的new_branch
100 
101 git co $id # 把某次历史提交记录checkout出来，但无分支信息，切换到其他分支会自动删除
102 
103 git co $id -b <new_branch> # 把某次历史提交记录checkout出来，创建成一个分支
104 
105 git br -d <branch> # 删除某个分支
106 
107 git br -D <branch> # 强制删除某个分支 (未被合并的分支被删除的时候需要强制)
108  分支合并和reba
109 git merge <branch> # 将branch分支合并到当前分支
110 
111 git merge origin/master --no-ff # 不要Fast-Foward合并，这样可以生成merge提交
112 
113 git rebase master <branch> # 将master rebase到branch，相当于： git co <branch> && git rebase master && git co master && git merge <branch>
114  Git补丁管理(方便在多台机器上开发同步时用)
115 
116 
117 git merge <branch> # 将branch分支合并到当前分支
118 
119 git merge origin/master --no-ff # 不要Fast-Foward合并，这样可以生成merge提交
120 
121 git rebase master <branch> # 将master rebase到branch，相当于： git co <branch> && git rebase master && git co master && git merge <branch>
122 
123  Git暂存管
124 git stash # 暂存
125 
126 git stash list # 列所有stash
127 
128 git stash apply # 恢复暂存的内容
129 
130 git stash drop # 删除暂存区
131 
132 Git远程分支管理
133 
134 git pull # 抓取远程仓库所有分支更新并合并到本地
135 
136 git pull --no-ff # 抓取远程仓库所有分支更新并合并到本地，不要快进合并
137 
138 git fetch origin # 抓取远程仓库更新
139 
140 git merge origin/master # 将远程主分支合并到本地当前分支
141 
142 git co --track origin/branch # 跟踪某个远程分支创建相应的本地分支
143 
144 git co -b <local_branch> origin/<remote_branch> # 基于远程分支创建本地分支，功能同上
145 
146 git push # push所有分支
147 
148 git push origin master # 将本地主分支推到远程主分支
149 
150 git push -u origin master # 将本地主分支推到远程(如无远程主分支则创建，用于初始化远程仓库)
151 
152 git push origin <local_branch> # 创建远程分支， origin是远程仓库名
153 
154 git push origin <local_branch>:<remote_branch> # 创建远程分支
155 
156 git push origin :<remote_branch> #先删除本地分支(git br -d <branch>)，然后再push删除远程分支
157 
158 Git远程仓库管
159 git remote -v # 查看远程服务器地址和仓库名称
160 
161 git remote show origin # 查看远程服务器仓库状态
162 
163 git remote add origin git@ github:robbin/robbin_site.git # 添加远程仓库地址
164 
165 git remote set-url origin git@ github.com:robbin/robbin_site.git # 设置远程仓库地址(用于修改远程仓库地址) git remote rm <repository> # 删除远程仓库
166 
167 创建远程仓库
168 
169 git clone --bare robbin_site robbin_site.git # 用带版本的项目创建纯版本仓库
170 
171 scp -r my_project.git git@ git.csdn.net:~ # 将纯仓库上传到服务器上
172 
173 mkdir robbin_site.git && cd robbin_site.git && git --bare init # 在服务器创建纯仓库
174 
175 git remote add origin git@ github.com:robbin/robbin_site.git # 设置远程仓库地址
176 
177 git push -u origin master # 客户端首次提交
178 
179 git push -u origin develop # 首次将本地develop分支提交到远程develop分支，并且track
180 
181 git remote set-head origin master # 设置远程仓库的HEAD指向master分支
182 
183 也可以命令设置跟踪远程库和本地库
184 
185 git branch --set-upstream master origin/master
186 
187 git branch --set-upstream develop origin/develop
